#include "ruzzle_file_io.h"

/**
 * ReadRuzzleSchemeFromFile
 *
 * Finite-state machine to parse the Ruzzle scheme from a file.
 * First reads the matrix size, then the letters matrix and finally the bonuses matrix.
 *
 * @param filePath                  Path of the file containing the Ruzzle scheme
 * @param matrixSize                Output matrix size
 * @param ruzzleLettersMatrix       Output letter matrix
 * @param ruzzleBonusesMatrix       Output bonuses matrix
 *
 * @return  ReturnType_Error if the file could not be opened or some parsing error occurred,
 *          ReturnType_Success otherwise
 */
int ReadRuzzleSchemeFromFile(char *filePath, unsigned int *matrixSize, char **ruzzleLettersMatrix, char **ruzzleBonusesMatrix)
{
    int iResult = ReturnType_Success;
    FILE *pFile = fopen(filePath, "r");
    if(pFile)
    {
        FileParser_State_t eCurrentState = FileParser_State_Matrix_Size; /* Set the initial state to "find and parse matrix size" */
        size_t bufferSize = RUZZLE_INPUT_STRING_MAX_LENGTH;
        long lSizeCounter = 0; /* Counter to store the matrix's row size */
        char bLettersMatrixValid = 0, bBonusesMatrixValid;

        char *sBuffer = malloc(sizeof(char) * bufferSize);

        while(getline(&sBuffer, &bufferSize, pFile) != -1 && eCurrentState != FileParser_State_Max)
        {
            if(ValidateBuffer(sBuffer) == ReturnType_Success)
            {
                switch(eCurrentState)
                {
                    case FileParser_State_Matrix_Size:
                    {
                        char *pEndPtr = NULL;

                        /* Safely convert a string to an integer */
                        *matrixSize = (unsigned int)strtol(&sBuffer[0], &pEndPtr, 10);
                        if(pEndPtr == &sBuffer[0])
                        {
                            /* No valid integer found, raise error and interrupt */
                            iResult = ReturnType_Error;
                            eCurrentState = FileParser_State_Max;
                            break;
                        }

                        /* Allocate matrix buffers */
                        *ruzzleLettersMatrix = calloc((*matrixSize) * (*matrixSize), sizeof(char));
                        *ruzzleBonusesMatrix = calloc((*matrixSize) * (*matrixSize), sizeof(char));

                        /* Advance state */
                        eCurrentState = FileParser_State_Letters_Matrix;
                        break;
                    }
                    case FileParser_State_Letters_Matrix:
                    {
                        if(lSizeCounter < (*matrixSize))
                        {
                            /* Parse single row into matrix (letters) */
                            if(ParseSchemeRow(ruzzleLettersMatrix, (*matrixSize), lSizeCounter, sBuffer, 1) != ReturnType_Success)
                            {
                                iResult = ReturnType_Error;
                                break;
                            }

                            lSizeCounter++;
                        }

                        if(lSizeCounter >= (*matrixSize))
                        {
                            /* Advance state */
                            eCurrentState = FileParser_State_Bonuses_Matrix;
                            lSizeCounter = 0;
                            bLettersMatrixValid = 1;
                        }

                        break;
                    }
                    case FileParser_State_Bonuses_Matrix:
                    {
                        if(lSizeCounter < (*matrixSize))
                        {
                            /* Parse single row into matrix (bonuses) */
                            if(ParseSchemeRow(ruzzleBonusesMatrix, (*matrixSize), lSizeCounter, sBuffer, 0) != ReturnType_Success)
                            {
                                iResult = ReturnType_Error;
                                break;
                            }

                            lSizeCounter++;
                        }

                        if(lSizeCounter >= (*matrixSize))
                        {
                            /* Advance state, thus terminating the finite-state machine */
                            eCurrentState = FileParser_State_Max;
                            lSizeCounter = 0;
                            bBonusesMatrixValid = 1;
                        }

                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }

        if(!bLettersMatrixValid || !bBonusesMatrixValid) /* Some parsing error occurred */
        {
            iResult = ReturnType_Error;
        }

        free(sBuffer);
        sBuffer = NULL;

        fclose(pFile);
    }
    else
    {
        iResult = ReturnType_Error;
    }

    return iResult;
}

/**
 * ReadDictionaryStringOffline
 *
 * Reads a single string from the specified dictionary file into the given buffer.
 * Converts the read string to uppercase.
 * Uses a position parameter to keep track of the next string to read.
 *
 * @param dictionaryPath    File path of the dictionary
 * @param startPos          Parameter to keep track of the current line. MUST be set to 0 on first call
 * @param pBuffer           Output buffer to save the read string into
 * @param bufferSize        Output buffer size, must be bigger than the read string's size
 *
 * @return  ReturnType_Error if the file could not be opened,
 *          ReturnType_Overflow if bufferSize is too small to save the read string,
 *          ReturnType_EOF if EOF was reached,
 *          otherwise the number of VALID (non-whitespace and non-newline) read characters is returned
 */
int ReadDictionaryStringOffline(char *dictionaryPath, unsigned int* startPos, char* pBuffer, size_t bufferSize)
{
    FILE *pFile = NULL;
    pFile = fopen(dictionaryPath, "r");

    if(pFile)
    {
        size_t szBufferSize = RUZZLE_INPUT_STRING_MAX_LENGTH;
        char *sBuffer;
        int iRead = 0;

        if(*startPos > 0)
        {
            /* Move to stored position */
            fseek(pFile, *startPos, SEEK_SET);
        }

        sBuffer = malloc(sizeof(char) * szBufferSize);

        while((iRead = getline(&sBuffer, &szBufferSize, pFile)) != -1)
        {
            /* Cleanup the input string */
            ValidateBuffer(sBuffer);

            *startPos = ftell(pFile);

            if(CheckValidAlphaString(sBuffer))
            {
                szBufferSize = strlen(sBuffer);
                if(bufferSize < (szBufferSize + 1)) /* Check for buffer overflow */
                {
                    free(sBuffer);
                    sBuffer = NULL;

                    return ReturnType_Overflow;
                }

                /* Copy string to output and save current position */
                strncpy(pBuffer, sBuffer, bufferSize);
                break;
            }
        }

        free(sBuffer);
        sBuffer = NULL;

        fclose(pFile);
        return (iRead == -1 ? ReturnType_Success : szBufferSize);
    }

    /* Something went wrong while opening the file */
    return ReturnType_Error;
}

#if 0
/**
 * PrintPathToFile
 *
 * Prints the specified path to the specified file, appending it.
 *
 * The output format is:
 *  <word> <score> (row, column)->(row, column)->...->(row, column)
 *
 * @param filePath          File to append the path to
 * @param word              The path's word
 * @param pPath             The path to output
 */
ReturnType_t PrintPathToFile(char* filePath, char* word, path_t* pPath)
{
    FILE *pFile;
    if(filePath == NULL || word == NULL || pPath == NULL)
    {
        return ReturnType_Error;
    }

    pFile = fopen(filePath, "a"); /* Open in append mode */
    if(pFile)
    {
        unsigned int i;
        fprintf(pFile, "%s %i ", word, pPath->score);
        for(i = 0; i < pPath->n_valid; i++)
        {
            cell_t cell = pPath->p_cells[i];

            if(i == (pPath->n_valid - 1))
            {
                fprintf(pFile, "(%d,%d)", cell.row, cell.column);
            }
            else
            {
                fprintf(pFile, "(%d,%d)->", cell.row, cell.column);
            }
        }

        fprintf(pFile, "\n");
        fclose(pFile);
        return ReturnType_Success;
    }

    return ReturnType_Error;
}
#else
/**
 * PrintPathToFile
 *
 * Prints the specified path to the specified file, appending it.
 *
 * The output format is:
 *  <word> <score> (row, column)->(row, column)->...->(row, column)
 *
 * @param filePath          File to append the path to
 * @param word              The path's word
 * @param pPath             The path to output
 */
ReturnType_t PrintPathToFile(char* filePath, char* word, path_t* pPath)
{
    FILE *pFile;
    if(filePath == NULL || word == NULL || pPath == NULL)
    {
        return ReturnType_Error;
    }

    pFile = fopen(filePath, "a"); /* Open in append mode */
    if(pFile)
    {
        unsigned int i;
        fprintf(pFile, "%s %i ", word, pPath->score);
        for(i = 0; i < pPath->n_valid; i++)
        {
            cell_t cell = pPath->p_cells[i];

            if(i == (pPath->n_valid - 1))
            {
                fprintf(pFile, "(%d, %d)", cell.row, cell.column);
            }
            else
            {
                fprintf(pFile, "(%d, %d)->", cell.row, cell.column);
            }
        }

        fprintf(pFile, "\n");
        fclose(pFile);
        return ReturnType_Success;
    }

    return ReturnType_Error;
}
#endif

/**
 * EraseFile
 *
 * Erases a file by creating a new one with the same name and thus overwriting the old one.
 *
 * @param filePath  Path to file to erase
 *
 * @return  ReturnType_Error if the path is empty or if there was an error while trying to open the file
 *          ReturnType_Success if everything went well and the file was correctly erased
 */
ReturnType_t EraseFile(char* filePath)
{
    FILE *pFile;
    if(filePath == NULL)
    {
        return ReturnType_Error;
    }

    pFile = fopen(filePath, "w");
    if(pFile)
    {
        return ReturnType_Success;
    }

    return ReturnType_Error;
}
