#include "ruzzle_pathfinding.h"
#include "ruzzle_scores.h"

/**
 * QSortCompareScoresFn
 *
 * Callback function for std's qsort().
 * Implements a simple comparator that sorts path elements in DESCENDING order, based on their scores
 *
 * @param a The first element to compare
 * @param b The second element to compare
 *
 * @return < 0 if b's score > a's score
 *         == 0 if b's score == a's score
 *         > 0 if b's score < a's score
 */
int QSortCompareScoresFn(const void *a, const void *b)
{
   return ((*(path_t*)b).score - (*(path_t*)a).score);
}

/**
 * GetCellNeighbours
 *
 * Gets a cell's neighbours that match the given letter.
 *
 * @param matrix        The input matrix
 * @param matrixSize    The size of the input matrix
 * @param rowCur        The current row inside the matrix
 * @param columnCur     The current column inside the matrix
 * @param nextLetter    The letter to match against
 * @param pNeighbours   Output structure that will contain the neighbours
 *
 * @return ReturnType_Error if pNeighbours is NULL,
 *         the number of valid neighbours otherwise
 */
int GetCellNeighbours(char* matrix, int matrixSize, int rowCur, int columnCur, char nextLetter, neighbours_t* pNeighbours)
{
    if(pNeighbours == NULL)
    {
        return ReturnType_Error;
    }

    memset(pNeighbours, 0, sizeof(*pNeighbours)); /* Cleanup the output structure */

    {
        /* Walk the 3x3 block around the current position, checking bounds and skipping the current position */
        int rowOffset;
        for(rowOffset = -1; rowOffset < 2; rowOffset++)
        {
            int columnOffset;
            int row = rowCur + rowOffset; /* Move to row */

            if(row < 0 || row >= matrixSize) /* Check row bounds */
            {
                continue;
            }

            for(columnOffset = -1; columnOffset < 2; columnOffset++)
            {
                int column = columnCur + columnOffset; /* Move to column */
                if(column < 0 || column >= matrixSize || (row == rowCur && column == columnCur)) /* Check column bounds and filter out current position */
                {
                    continue;
                }

                if(matrix[row * matrixSize + column] == nextLetter) /* Check if neighbour matches given letter */
                {
                    /* Add neighbour to output structure */
                    cell_t* pNeighbour = &(pNeighbours->neighbours[pNeighbours->n_valid]);
                    pNeighbour->row = row;
                    pNeighbour->column = column;
                    pNeighbours->n_valid++;
                }
            }
        }
    }

    return pNeighbours->n_valid;
}

/**
 * AddCellToPath
 *
 * Adds a matrix cell to a path
 *
 * @param pPath         The path to add the cell to
 * @param row           The row value of the cell
 * @param column        The column value of the cell
 * @param wordLength    The length of the word we're searching for, used to check bounds
 *
 * @return  ReturnType_Error if the path is NULL or the array would overflow,
 *          ReturnType_Success otherwise
 */
int AddCellToPath(path_t *pPath, unsigned int row, unsigned int column, size_t wordLength)
{
    if(pPath == NULL || pPath->n_valid >= wordLength)
    {
        return ReturnType_Error;
    }

    pPath->p_cells[pPath->n_valid].row = row;
    pPath->p_cells[pPath->n_valid].column = column;
    pPath->n_valid++;

    return ReturnType_Success;
}

/**
 * RemoveLastCellFromPath
 *
 * Removes the last cell from a path by decrementing the "valid cells" counter
 *
 * @param pPath     The path to remove the cell from
 *
 * @return  ReturnType_Error if the cell couldn't be removed,
 *          ReturnType_Success otherwise
 */
int RemoveLastCellFromPath(path_t *pPath)
{
    if(pPath == NULL || pPath->n_valid <= 0)
    {
        return ReturnType_Error;
    }

    pPath->n_valid--;
    return ReturnType_Success;
}

/**
 * CopyPathToPath
 *
 * Copies path pPathSrc to path pPathDest, freeing the pPathDest array of cells
 * if it's not empty and reallocating it
 *
 * @param pBranchPath       The branch path to copy from
 * @param pPath             The path to copy to
 *
 * @return  ReturnType_Error if either path pointer is NULL,
 *          ReturnType_OutOfMemory if malloc() failed (heap is full),
 *          ReturnType_Success otherwise
 */
int CopyPathToPath(path_t* pPathSrc, path_t* pPathDest)
{
    size_t szSize;
    if(pPathSrc == NULL || pPathDest == NULL)
    {
        return ReturnType_Error;
    }

    if(pPathDest->p_cells != NULL) /* Free the current path's array of cells if it's allocated */
    {
        free(pPathDest->p_cells);
        pPathDest->p_cells = NULL;
    }

    szSize = (sizeof(cell_t) * pPathSrc->n_valid);

    pPathDest->p_cells = malloc(szSize); /* Allocate the new array of cells */
    if(pPathDest->p_cells == NULL)
    {
        /* malloc() failed, out of memory */
        return ReturnType_OutOfMemory;
    }

    /* Copy cells and set n_valid and score */
    memcpy(pPathDest->p_cells, pPathSrc->p_cells, szSize);

    pPathDest->n_valid = pPathSrc->n_valid;
    pPathDest->score = pPathSrc->score;

    return ReturnType_Success;
}

/**
 * AddPathToBuffer
 *
 * Adds a path to the paths buffer
 *
 * @param pPathsBuffer  The paths buffer to add the path to
 * @param pPath         The path to add
 *
 * @return  ReturnType_Error if either pointer is NULL,
 *          ReturnType_Overflow if the maximum number of paths has been reached,
 *          ReturnType_OutOfMemory if out_of_memory was triggered,
 *          ReturnType_Success otherwise
 */
int AddPathToBuffer(paths_buffer_t* pPathsBuffer, path_t* pPath)
{
    int iCopyResult;
    if(pPathsBuffer == NULL || pPath == NULL)
    {
        return ReturnType_Error;
    }

    if(pPathsBuffer->n_valid >= RUZZLE_MAX_NUM_PATHS) /* Check for overflow */
    {
        return ReturnType_Overflow;
    }

    if(pPathsBuffer->n_valid >= pPathsBuffer->paths_size)
    {
        size_t szAllocSize;
        int i;
        path_t* pTempArray;

        if((pPathsBuffer->paths_size + RUZZLE_PATH_ARRAY_INCREMENT_SIZE) < RUZZLE_MAX_NUM_PATHS) /* We still have space to allocate PATH_ARRAY_INCREMENT_SIZE blocks */
        {
            szAllocSize = (pPathsBuffer->paths_size + RUZZLE_PATH_ARRAY_INCREMENT_SIZE);
        }
        else /* We'd surpass the limit, just allocate the maximum available size */
        {
            szAllocSize = RUZZLE_MAX_NUM_PATHS;
        }

        pTempArray = malloc(sizeof(path_t) * szAllocSize);
        memset(pTempArray, 0, sizeof(path_t) * szAllocSize);

        /* Copy each array of cells to the new path, freeing the old arrays after the copy */
        for(i = 0; i < pPathsBuffer->n_valid; i++)
        {
            CopyPathToPath(&pPathsBuffer->p_paths[i], &pTempArray[i]);
            free(pPathsBuffer->p_paths[i].p_cells);
            pPathsBuffer->p_paths[i].p_cells = NULL;
        }

        if(pPathsBuffer->p_paths != NULL)
        {
            free(pPathsBuffer->p_paths);
            pPathsBuffer->p_paths = NULL;
        }

        pPathsBuffer->p_paths = pTempArray;
        pPathsBuffer->paths_size = szAllocSize;
    }

    /* Copy the branch to the buffer's next available spot and increment the number of valid spots if successful */
    pPathsBuffer->p_paths[pPathsBuffer->n_valid].p_cells = NULL;
    iCopyResult = CopyPathToPath(pPath, &pPathsBuffer->p_paths[pPathsBuffer->n_valid]);
    if(iCopyResult == 0)
    {
        pPathsBuffer->n_valid++;
    }

    return iCopyResult;
}
/**
 * SavePathScorePrev
 *
 * Save the path's score to the specified variable on the stack
 *
 * @param pPath             The path to save the score and multiplier of
 * @param scorePrev         The pointer to the stack variable holding the previous score
 */
inline void SavePathScorePrev(path_t* pPath, unsigned int* scorePrev)
{
    *scorePrev = pPath->score;
}

/**
 * ResetPathScorePrev
 *
 * Resets the path's score to the value specified
 *
 * @param pPath             The path to restore the score and multiplier of
 * @param scorePrev         The previous score
 */
inline void ResetPathScorePrev(path_t* pPath, unsigned int scorePrev)
{
    pPath->score = scorePrev;
}

/**
 * ComputePaths
 *
 * The program's core. Computes paths by finding valid neighbours recursively,
 * marking already-traversed letters in the input matrix with a NUL character ('\0')
 * before entering branches and restoring the previous values when exiting them.
 *
 * The input matrix is therefore unchanged at the end of this function, but not during its execution.
 *
 * The function uses a single path_t structure to keep track of the current path, adding/removing cells as
 * it explores branches, just like it does for the input matrix.
 *
 * The path's score is calculated at each step and the word multipliers are applied once the word is found.
 * Once the word is found, the function decides how to behave based on the value of g_tGameMode:
 *
 *  - GameMode_Offline: the function only keeps track of the path with the highest score, discarding all others
 *  - GameMode_Interactive: the function keeps track of all paths, and the max_score_path field is unused.
 *
 * In case the pPathsContainer buffer is full, the function warns the user via stdin,
 * then proceeds to dump the current buffer to console. Once the buffer is dumped,
 * it's flushed and the function resumes searching.
 *
 * @param pLetterMatrix     Pointer to the matrix containing letters
 * @param pBonusesMatrix    Pointer to the matrix containing cell bonuses
 * @param matrixSize        Size of the matrices
 * @param wordToFind        The word to find
 * @param wordLength        The length of the word
 * @param currentCharacter  Current character, used internally. MUST be set to 0 when calling
 * @param row               Current row, used internally. MUST be set to the starting point when calling
 * @param column            Current column, used internally. MUST be set to the starting point when calling
 * @param pPathsContainer   Container for the found paths
 * @param pCurrentPath      Structure containing the current path, used internally. MUST be a valid pointer, automatically reset by the function
 * @param lastError         Last error occurred (if any)
 *
 * @return  ReturnType_Error if any of the input pointers is NULL or an internal error occurred,
 *          ReturnType_Success otherwise
 */
ReturnType_t ComputePaths(char* pLetterMatrix,
                            char* pBonusesMatrix,
                            unsigned int matrixSize,
                            const char* wordToFind,
                            size_t wordLength,
                            unsigned int currentCharacter,
                            unsigned int row,
                            unsigned int column,
                            paths_buffer_t *pPathsContainer,
                            path_t *pCurrentPath,
                            ReturnType_t* lastError)
{
#ifdef CALCULATE_SCORES_TRAVERSE
    static unsigned int iWordMultiplier = 1;
#endif

    if(pLetterMatrix == NULL || pBonusesMatrix == NULL || wordToFind == NULL || pPathsContainer == NULL || pCurrentPath == NULL || lastError == NULL)
    {
        return ReturnType_Error;
    }

    if(*lastError != ReturnType_Success) /* Prevent further calls, we had an error earlier on */
    {
        return ReturnType_Error;
    }

    if(currentCharacter == 0 && pLetterMatrix[row * matrixSize + column] == wordToFind[currentCharacter]) /* First character */
    {
        /* Reset score info */
        char cPrevious;
        pCurrentPath->score = 0;
        pCurrentPath->n_valid = 0;

#ifdef CALCULATE_SCORES_TRAVERSE
        iWordMultiplier = 1;
#endif

        cPrevious = pLetterMatrix[row * matrixSize + column]; /* Save current character */

        if(AddCellToPath(pCurrentPath, row, column, wordLength) == ReturnType_Success) /* Add cell to path before branch */
        {
#ifdef CALCULATE_SCORES_TRAVERSE
            unsigned int iScorePrev;
            unsigned int iMultiplierPrev;

            iMultiplierPrev = iWordMultiplier;
            SavePathScorePrev(pCurrentPath, &iScorePrev); /* Save current score before branch */

            /* Evaluate the current cell's score, adding it to the path's score and saving the multiplier */
            EvaluateLetterScore(pBonusesMatrix,
                                matrixSize,
                                cPrevious,
                                row,
                                column,
                                &(pCurrentPath->score),
                                &iWordMultiplier);
#endif

            pLetterMatrix[row * matrixSize + column] = 0; /* Mark current character as "used" for the next branch */
            ComputePaths(pLetterMatrix, pBonusesMatrix, matrixSize, wordToFind, wordLength, currentCharacter + 1, row, column, pPathsContainer, pCurrentPath, lastError);
            pLetterMatrix[row * matrixSize + column] = cPrevious; /* Here the branch has just ended, restore the previous character for subsequent branches */

#ifdef CALCULATE_SCORES_TRAVERSE
            iWordMultiplier = iMultiplierPrev;
            ResetPathScorePrev(pCurrentPath, iScorePrev); /* Restore score after branch */
#endif

            RemoveLastCellFromPath(pCurrentPath); /* Remove cell from path after branch */
        }

        return ReturnType_Success;
    }

    if(wordToFind[currentCharacter] == 0)
    {
        /* Error, should never happen */
        return ReturnType_Error;
    }

    {
        neighbours_t tNeighbours;
        if(GetCellNeighbours(pLetterMatrix, matrixSize, row, column, wordToFind[currentCharacter], &tNeighbours) > 0) /* Get cell's neighbours */
        {
            int i;
            for(i = 0; i < tNeighbours.n_valid; i++)
            {
                /* Launch search branches for each neighbour */
                cell_t *pNeighbourCell = &tNeighbours.neighbours[i];
                if(AddCellToPath(pCurrentPath, pNeighbourCell->row, pNeighbourCell->column, wordLength) == ReturnType_Success) /* Save current character */
                {
#ifdef CALCULATE_SCORES_TRAVERSE
                    unsigned int iScorePrev;
                    unsigned int iMultiplierPrev;

                    iMultiplierPrev = iWordMultiplier;
                    SavePathScorePrev(pCurrentPath, &iScorePrev); /* Save current score before branch */

                    /* Evaluate the current cell's score, adding it to the path's score and saving the multiplier */
                    EvaluateLetterScore(pBonusesMatrix,
                                        matrixSize,
                                        pLetterMatrix[pNeighbourCell->row * matrixSize + pNeighbourCell->column],
                                        pNeighbourCell->row,
                                        pNeighbourCell->column,
                                        &(pCurrentPath->score),
                                        &iWordMultiplier);
#endif

                    if(wordToFind[currentCharacter + 1] != '\0') /* Check next element, if it's not the endline character then keep cycling */
                    {
                        char cPrevious = pLetterMatrix[pNeighbourCell->row * matrixSize + pNeighbourCell->column]; /* Save current character */
                        pLetterMatrix[pNeighbourCell->row * matrixSize + pNeighbourCell->column] = 0; /* Mark current character as "used" for the next branch */
                        ComputePaths(pLetterMatrix, pBonusesMatrix, matrixSize, wordToFind, wordLength, currentCharacter + 1, pNeighbourCell->row, pNeighbourCell->column, pPathsContainer, pCurrentPath, lastError);
                        pLetterMatrix[pNeighbourCell->row * matrixSize + pNeighbourCell->column] = cPrevious; /* Here the branch has just ended, restore the previous character for subsequent branches */
                    }
                    else
                    {
                        /* Entire word found */
#ifdef CALCULATE_SCORES_TRAVERSE
                        pCurrentPath->score *= iWordMultiplier; /* Compute final score by multiplying it by the word multipliers */
#else
                        pCurrentPath->score = EvaluatePathScore(pBonusesMatrix, matrixSize, (path_t*)pCurrentPath, wordToFind);
#endif

                        if(g_tGameMode == GameMode_Interactive) /* If the current game mode is Interactive Mode, save all paths */
                        {
                            ReturnType_t tReturn = AddPathToBuffer(pPathsContainer, pCurrentPath);
                            if(tReturn == ReturnType_Overflow)
                            {
                                printf("WARNING: Dumping paths to console because we hit RUZZLE_MAX_NUM_PATHS (currently %i), try increasing this value if you need to compute large datasets\n", RUZZLE_MAX_NUM_PATHS);
                                printf("WARNING: Dumping paths in 5 seconds...\n");

                                sleep(5);

                                for(i = 0; i < pPathsContainer->n_valid; i++)
                                {
                                    if(PrintPathToConsole(wordToFind, &pPathsContainer->p_paths[i]) == ReturnType_Error)
                                    {
                                        break;
                                    }
                                }

                                for(i = 0; i < pPathsContainer->n_valid; i++)
                                {
                                    if(pPathsContainer->p_paths[i].p_cells != NULL)
                                    {
                                        free(pPathsContainer->p_paths[i].p_cells);
                                        pPathsContainer->p_paths[i].p_cells = NULL;
                                    }
                                }

                                if(pPathsContainer->max_score_path.p_cells != NULL)
                                {
                                    free(pPathsContainer->max_score_path.p_cells);
                                    pPathsContainer->max_score_path.p_cells = NULL;
                                }

                                if(pPathsContainer->p_paths != NULL)
                                {
                                    free(pPathsContainer->p_paths);
                                    pPathsContainer->p_paths = NULL;
                                }

                                memset(pPathsContainer, 0, sizeof(paths_buffer_t));

                                pPathsContainer->p_paths = malloc(sizeof(path_t) * RUZZLE_INITIAL_PATH_ARRAY_SIZE);
                                if(pPathsContainer->p_paths != NULL)
                                {
                                    pPathsContainer->paths_size = RUZZLE_INITIAL_PATH_ARRAY_SIZE;
                                    AddPathToBuffer(pPathsContainer, pCurrentPath); /* Add current path to new buffer, to avoid skipping it */
                                }
                                else
                                {
                                    *lastError = ReturnType_OutOfMemory;
                                    return ReturnType_Error;
                                }
                            }
                            else if(tReturn != ReturnType_Success)
                            {
                                *lastError = tReturn;
                                return ReturnType_Error;
                            }

                            pPathsContainer->n_total_paths++; /* Increment number of total paths */
                        }
                        else if(pCurrentPath->score > pPathsContainer->max_score_path.score) /* Only find highest-scoring path */
                        {
                            ReturnType_t tReturn = CopyPathToPath((path_t*)pCurrentPath, &pPathsContainer->max_score_path);
                            if(tReturn != ReturnType_Success)
                            {
                                *lastError = tReturn;
                                return ReturnType_Error;
                            }

                            pPathsContainer->n_total_paths = 1;
                        }
                    }

#ifdef CALCULATE_SCORES_TRAVERSE
                    iWordMultiplier = iMultiplierPrev;
                    ResetPathScorePrev(pCurrentPath, iScorePrev); /* Restore score after branch */
#endif
                    RemoveLastCellFromPath(pCurrentPath); /* Remove cell from path after branch */
                }
            }
        }
    }

    return ReturnType_Success;
}

ReturnType_t FindWordPaths(char* pLetterMatrix,
                            char* pBonusesMatrix,
                            unsigned int matrixSize,
                            const char* wordToFind,
                            size_t wordLength,
                            paths_buffer_t *pPathsContainer,
                            ReturnType_t* lastError)
{
    unsigned int i = 0;
    unsigned int j = 0;
    ReturnType_t eReturnType = ReturnType_Success;
    path_t pathTemp;

    char *sWordUpperCase = malloc(sizeof(char) * (wordLength + 1));
    if(sWordUpperCase == NULL)
    {
        eReturnType = ReturnType_OutOfMemory;
        return eReturnType;
    }

    memset(sWordUpperCase, 0, sizeof(char) * (wordLength + 1));
    strncpy(sWordUpperCase, wordToFind, wordLength);
    StringToUpperCase(sWordUpperCase);

    pPathsContainer->n_valid = 0;
    pPathsContainer->max_score_path.p_cells = NULL;
    pPathsContainer->max_score_path.n_valid = 0;
    pPathsContainer->max_score_path.score = 0;

    memset(&pathTemp, 0, sizeof(path_t));

    for(i = 0; i < matrixSize && eReturnType == ReturnType_Success; i++)
    {
        for(j = 0; j < matrixSize; j++)
        {
            if(pLetterMatrix[i * matrixSize + j] == sWordUpperCase[0])
            {
                if(wordLength == 1)
                {
                    unsigned int uiScore = 0;
                    unsigned int uiMultiplier = 1;
                    EvaluateLetterScore(pBonusesMatrix, matrixSize, sWordUpperCase[0], i, j, &uiScore, &uiMultiplier);

                    uiScore *= uiMultiplier;

                    if(g_tGameMode == GameMode_Offline)
                    {
                        if(uiScore > pPathsContainer->max_score_path.score)
                        {
                            if(pPathsContainer->max_score_path.p_cells == NULL)
                            {
                                pPathsContainer->max_score_path.p_cells = malloc(sizeof(cell_t));
                                if(pPathsContainer->max_score_path.p_cells == NULL)
                                {
                                    eReturnType = ReturnType_OutOfMemory;
                                    break;
                                }
                            }

                            pPathsContainer->max_score_path.p_cells[0].row = i;
                            pPathsContainer->max_score_path.p_cells[0].column = j;
                            pPathsContainer->max_score_path.n_valid = 1;
                            pPathsContainer->max_score_path.score = uiScore;
                        }
                    }
                    else
                    {
                        if(pathTemp.p_cells != NULL)
                        {
                            free(pathTemp.p_cells);
                            pathTemp.p_cells = NULL;
                        }

                        pathTemp.p_cells = malloc(sizeof(cell_t));
                        if(pathTemp.p_cells == NULL)
                        {
                            eReturnType = ReturnType_OutOfMemory;
                            break;
                        }

                        pathTemp.p_cells[0].row = i;
                        pathTemp.p_cells[0].column = j;
                        pathTemp.n_valid = 1;
                        pathTemp.score = uiScore;

                        eReturnType = AddPathToBuffer(pPathsContainer, &pathTemp);
                        if(eReturnType != ReturnType_Success)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if(pathTemp.p_cells != NULL)
                    {
                        free(pathTemp.p_cells);
                        pathTemp.p_cells = NULL;
                    }

                    pathTemp.p_cells = malloc(sizeof(cell_t) * wordLength);
                    if(pathTemp.p_cells == NULL)
                    {
                        eReturnType = ReturnType_OutOfMemory;
                        break;
                    }

                    pathTemp.score = 0;
                    pathTemp.n_valid = 0;

                    if((eReturnType = ComputePaths(pLetterMatrix,
                                                    pBonusesMatrix,
                                                    matrixSize,
                                                    sWordUpperCase,
                                                    wordLength,
                                                    0,
                                                    i,
                                                    j,
                                                    pPathsContainer,
                                                    &pathTemp,
                                                    lastError)) != ReturnType_Success)
                    {
                        break;
                    }
                }
            }
        }
    }

    if(pPathsContainer->n_valid > 0)
    {
        qsort(pPathsContainer->p_paths, pPathsContainer->n_valid, sizeof(path_t), QSortCompareScoresFn);
    }

    if(pathTemp.p_cells != NULL)
    {
        free(pathTemp.p_cells);
        pathTemp.p_cells = NULL;
    }

    if(sWordUpperCase != NULL)
    {
        free(sWordUpperCase);
        sWordUpperCase = NULL;
    }

    return eReturnType;
}
