#include "main.h"

GameMode_t g_tGameMode = GameMode_Interactive;

void SetGameMode(int argc)
{
    if(argc == RUZZLE_OFFLINE_PARAMETER_COUNT)
    {
        g_tGameMode = GameMode_Offline;
    }
    else
    {
        g_tGameMode = GameMode_Interactive;
    }
}

int main(int argc, char **argv)
{
    unsigned int uiMatrixSize;      /* Matrix side size */
    char *pLettersMatrix = NULL;    /* Letters matrix */
    char *pBonusesMatrix = NULL;    /* Bonuses matrix */
    paths_buffer_t pathsBuffer;     /* Buffer to store results */
    ReturnType_t eLastError = ReturnType_Success;   /* Last error occurred */
    char sBuffer[RUZZLE_INPUT_STRING_MAX_LENGTH] = {0}; /* Buffer to store the word to find */
    int iWordLength = 0;    /* Length of the word to find */
    ReturnType_t eReturn = ReturnType_Success;  /* Return of last function */
    unsigned int iStartPos = 0; /* Read position, used by ReadDictionaryStringOffline to keep track of current position within file */
    unsigned int i = 0;

    SetGameMode(argc);

    printf("\n");
    printf("██████╗ ██╗   ██╗███████╗███████╗██╗     ███████╗ \n");
    printf("██╔══██╗██║   ██║╚══███╔╝╚══███╔╝██║     ██╔════╝ \n");
    printf("██████╔╝██║   ██║  ███╔╝   ███╔╝ ██║     █████╗	  \n");
    printf("██╔══██╗██║   ██║ ███╔╝   ███╔╝  ██║     ██╔══╝   \n");
    printf("██║  ██║╚██████╔╝███████╗███████╗███████╗███████╗ \n");
    printf("╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝╚══════╝╚══════╝ \n\n");

    if(g_tGameMode == GameMode_Offline)
    {
    	printf("*** Welcome to \"Ruzzle Offline Version\" ***\n");

        eReturn = ReadRuzzleSchemeFromFile(argv[2], &uiMatrixSize, &pLettersMatrix, &pBonusesMatrix); /* Read the Ruzzle scheme from the specified file */
        if(eReturn != ReturnType_Success)
        {
            printf("ERROR: ReadRuzzleSchemeFromFile error at line %i (error number: %i)\n", __LINE__, eReturn);
        }
        else
        {
            eReturn = EraseFile(argv[3]); /* Erase the output file */
            if(eReturn != ReturnType_Success)
            {
                printf("ERROR: EraseFile error at line %i (error number: %i)\n", __LINE__, eReturn);
            }
        }
    }
    else
    {
    	int iRead;
    	printf("*** Welcome to \"Ruzzle Interactive Version\" ***\n");

        iRead = ShowInteractiveMenu(&uiMatrixSize, &pLettersMatrix, &pBonusesMatrix); /* Show the interactive mode menu */
        if(iRead == ReturnType_Terminated)
        {
            eReturn = ReturnType_Terminated;
        }
        else if(iRead <= 0)
        {
            eReturn = iRead;
            printf("ERROR: Invalid input entered!\n");
        }
    }

    if(eReturn == ReturnType_Success)
    {
        do
        {
            /* Reset and reallocate paths */
            memset(&pathsBuffer, 0, sizeof(paths_buffer_t));
            pathsBuffer.p_paths = malloc(sizeof(path_t) * RUZZLE_INITIAL_PATH_ARRAY_SIZE);
            pathsBuffer.paths_size = RUZZLE_INITIAL_PATH_ARRAY_SIZE;

            if(g_tGameMode == GameMode_Offline)
            {
                /* Read a string from the dictionary */
                iWordLength = ReadDictionaryStringOffline(argv[1], &iStartPos, sBuffer, RUZZLE_INPUT_STRING_MAX_LENGTH);
                eReturn = iWordLength;

                if(iWordLength == ReturnType_Error)
                {
                    printf("ERROR: Generic error while reading string from file!\n");
                }
                else if(iWordLength == ReturnType_Overflow)
                {
                    printf("ERROR: Overflow when reading string from file! Recompile with an increased RUZZLE_INPUT_STRING_MAX_LENGTH value (current: %i)\n", RUZZLE_INPUT_STRING_MAX_LENGTH);
                }
                else if(iWordLength > 0)
                {
                    /* Find the max-scoring path for this word */
                    if((eReturn = FindWordPaths(pLettersMatrix, pBonusesMatrix, uiMatrixSize, sBuffer, iWordLength, &pathsBuffer, &eLastError)) != ReturnType_Success)
                    {
                        printf("ERROR: An error occurred at line %i (error number: %i) (last error: %i)\n", __LINE__, eReturn, eLastError);
                    }
                    else if(pathsBuffer.max_score_path.n_valid > 0)
                    {
                        /* Max-scoring path found, print it to file */
                        if((eReturn = PrintPathToFile(argv[3], sBuffer, &pathsBuffer.max_score_path)) == ReturnType_Error)
                        {
                            printf("ERROR: Could not find specified output file!\n");
                        }
                    }
                    else
                    {
                        printf("\tNo valid paths found for word \"%s\".\n", sBuffer);
                    }
                }
            }
            else
            {
                /* Read word to find from stdin */
                iWordLength = ReadDictionaryInteractive(sBuffer, RUZZLE_INPUT_STRING_MAX_LENGTH);
                eReturn = iWordLength;
                if(iWordLength == ReturnType_Error)
                {
                    printf("ERROR: Generic error while reading string from console!\n");
                }
                else if(iWordLength > 0)
                {
                    /* Find all paths for this word */
                    if((eReturn = FindWordPaths(pLettersMatrix, pBonusesMatrix, uiMatrixSize, sBuffer, iWordLength, &pathsBuffer, &eLastError)) != ReturnType_Success)
                    {
                        printf("ERROR: An error occurred at line %i (error number: %i) (last error: %i)\n", __LINE__, eReturn, eLastError);
                    }
                    else if(pathsBuffer.n_valid > 0)
                    {
                        for(i = 0; i < pathsBuffer.n_valid; i++)
                        {
                            /* Path is valid, print it to console */
                            if((eReturn = PrintPathToConsole(sBuffer, &(pathsBuffer.p_paths[i]))) == ReturnType_Error)
                            {
                                printf("ERROR: Invalid pointer passed to PrintPathToConsole!\n");
                                break;
                            }
                        }
                    }
                    else
                    {
                        printf("No valid paths found.");
                    }
                }
            }

            /* Cleanup */
            for(i = 0; i < pathsBuffer.n_valid; i++)
            {
                if(pathsBuffer.p_paths[i].p_cells != NULL)
                {
                    free(pathsBuffer.p_paths[i].p_cells);
                    pathsBuffer.p_paths[i].p_cells = NULL;
                }
            }

            if(pathsBuffer.max_score_path.p_cells != NULL)
            {
                free(pathsBuffer.max_score_path.p_cells);
                pathsBuffer.max_score_path.p_cells = NULL;
            }

            if(pathsBuffer.p_paths != NULL)
            {
                free(pathsBuffer.p_paths);
                pathsBuffer.p_paths = NULL;
            }

        } while(eReturn == ReturnType_Success && iWordLength > 0);
    }

    /* Cleanup */
    if(pLettersMatrix != NULL)
    {
        free(pLettersMatrix);
        pLettersMatrix = NULL;
    }

    if(pBonusesMatrix != NULL)
    {
        free(pBonusesMatrix);
        pBonusesMatrix = NULL;
    }

    printf("\n--------------------------------------------------\n\n");
    printf("*** Thank you for Playing ***\n");
    printf("*** Game made by Francesco Sponchiado (856166) and Federico Longhin (857179) ***\n\n");

    return (eReturn == ReturnType_Success ? EXIT_SUCCESS : EXIT_FAILURE);
}
