#include "ruzzle_console_io.h"

/**
 * SafeScanf
 *
 * Safe version of scanf() which only reads the specified (bufferSize - 1) characters from stdin.
 * WARNING: This function discards all characters left in stdin, effectively flushing the buffer.
 *
 * @param pBuffer       Buffer to save the read input
 * @param bufferSize    Size of the buffer to save the read input
 *
 * @return  ReturnType_Error if the buffer/buffer size are invalid or scanf failed,
 *          the number of read characters otherwise
 */
int SafeScanf(char *pBuffer, size_t bufferSize)
{
    char sFormat[32], cFlushChar;
    int iOldFileFlags = 0; /* Used to set blocking/non-blocking mode on stdin */

    if(pBuffer == NULL || bufferSize == 0)
    {
        return ReturnType_Error;
    }

    snprintf(sFormat, sizeof(sFormat), "%%%ds", (int)(bufferSize - 1)); /* Uses max length formatter, e.g. %20s = maximum 20 characters */

    iOldFileFlags = fcntl(0, F_GETFL); /* Get current stdin flags */
    fcntl(0, F_SETFL, O_NONBLOCK); /* Set stdin (0) to non-blocking mode to flush buffer without waits caused by getchar() */
    while((cFlushChar = getchar()) != '\n' && cFlushChar != EOF) {} /* Flush buffer, used to avoid picking up garbage from strings that were too long */
    fcntl(0, F_SETFL, iOldFileFlags); /* Reset stdin (0) to previous mode */

    if(!scanf(sFormat, pBuffer))
    {
        return ReturnType_Error;
    }

    return strlen(pBuffer);
}

/**
 * ReadDictionaryInteractive
 *
 * Reads a single string from standard input into the given buffer.
 * Converts the read string to uppercase.
 *
 * @param pBuffer		Output buffer to save the read string into
 * @param bufferSize	Output buffer size, must be bigger than the read string's size
 *
 * @return	ReturnType_Success if the string for ending the procedure has been given as an input,
 * 			ReturnType_Overflow if bufferSize is too small to save the read string,
 * 			0 otherwise
 */
int ReadDictionaryInteractive(char* pBuffer, size_t bufferSize)
{
    unsigned int bValidWord = 1;
    int iRead = 0;
    char sBuffer[RUZZLE_INPUT_STRING_MAX_LENGTH] = {0};

    getchar();
    do
    {
        do
        {
            memset(sBuffer, 0, RUZZLE_INPUT_STRING_MAX_LENGTH);
            printf("\n\nInsert word: ");
        } while((iRead = SafeScanf(sBuffer, RUZZLE_INPUT_STRING_MAX_LENGTH)) <= 0);

        /* Validating input buffer */
        ValidateBuffer(sBuffer);

        /* Checking if input was end of procedure */
        if(sBuffer[0] == '0' && sBuffer[1] == '\0')
        {
            return ReturnType_Success;
        }

        /* Checking if input contains only characters belonging to the english alphabet */
        bValidWord = CheckValidAlphaString(sBuffer);
        if(bValidWord)
        {
            size_t szWordLength = strlen(sBuffer);
            /* Checking for buffer overflow */
            if(bufferSize < (szWordLength + 1))
            {
                return ReturnType_Overflow;
            }

            /* Copy string to output */
            strncpy(pBuffer, sBuffer, bufferSize);
        }
        else
        {
            printf("Invalid input, the word must contain only alphabetical characters\n");
        }
    } while(!bValidWord);

    return iRead;
}

/**
 * InteractiveMenuInputSize
 *
 * Reads a positive integer matrix size from standard input.
 *
 * @return	ReturnType_Error if something went wrong while reading,
 * 			the matrix size otherwise
 */
int InteractiveMenuInputSize()
{
    int iResult = ReturnType_Error;

    printf("*** Ruzzle Scheme Size Input ***\n\n");
    do
    {
        printf("Insert a size (e.g. A size of 4 equals to a 4 by 4 scheme): ");

        /* Checking if input size is valid */
        if(!scanf("%d", &iResult) || iResult < 1)
        {
            printf("Invalid input, the size must be an integer greater than zero\n\n");
        }
    }while(iResult < 1);

    return iResult;
}

/**
 * InteractiveMenuInputRuzzleLetters
 *
 * Reads a row of letters from standard input.
 * Converts the read letters to uppercase.
 * Puts the letters inside the correct row of the matrix used to hold the scheme in the game.
 * This process is done in row order.
 *
 * @param ruzzleSchemeMatrix	Matrix used to represent the letters scheme in Ruzzle
 * @param matrixSize			The size of the matrix
 *
 * @return	ReturnType_Success if the string for ending the procedure has been given as an input,
 *          ReturnType_Terminated if the input sequence was terminated by the user,
 * 			-1 if something went wrong while reading all matrix rows,
 * 			the length of the last read row otherwise
 */
int InteractiveMenuInputRuzzleLetters(char **ruzzleSchemeMatrix, int matrixSize)
{
    unsigned int i = 0, bValid = 0;
    int iRead = -1;
    char sBuffer[RUZZLE_INPUT_STRING_MAX_LENGTH] = {0};

    printf("*** Ruzzle Scheme Letters Input, in row order - You can exit this procedure at any time by typing \"0\" ***\n\n");
    for(i = 0; i < matrixSize; i++)
    {
        do
        {
            memset(sBuffer, 0, RUZZLE_INPUT_STRING_MAX_LENGTH);
            printf("Insert letters for row %i: ", (i + 1));

            if((iRead = SafeScanf(sBuffer, matrixSize + 1)) == matrixSize)
            {
                if(iRead == 1 && sBuffer[0] == '0')
                {
                    printf("Terminating...\n\n");
                    bValid = 1;
                }
                else
                {
                    bValid = 1;
                    /* Checking if input contains only characters belonging to the english alphabet */
                    if(!CheckValidAlphaString(sBuffer))
                    {
                        printf("Invalid input, the letters must be only alphabetical characters\n\n");
                        bValid = 0;
                    }
                }
            }
            else if(iRead == 1 && sBuffer[0] == '0')
            {
                printf("Terminating...\n\n");
                bValid = 1;
            }
            else
            {
                printf("Invalid input, the number of letters must match the desired matrix size\n\n");
                bValid = 0;
            }
        } while(!bValid);

        /* Validating input buffer */
        ValidateBuffer(sBuffer);

        if(sBuffer[0] == '0' && sBuffer[1] == '\0')
        {
            return ReturnType_Terminated;
        }

        /* Inserting read row into matrix */
        ParseSchemeRow(ruzzleSchemeMatrix, matrixSize, i, sBuffer, 1);
    }

    return iRead;
}

/**
 * PrintPossibleBonuses
 *
 * Prints to standard output the list of possible bonuses for a word to standard output.
 */
void PrintPossibleBonuses()
{
    printf("Possible Bonuses:\n");
    printf("* \"d\" - Used to multipy letter by two\n");
    printf("* \"t\" - Used to multipy letter by three\n");
    printf("* \"D\" - Used to multipy word by two\n");
    printf("* \"T\" - Used to multipy word by three\n");
    printf("* \".\" - No multiplier\n\n");
}

/**
 * InteractiveMenuInputRuzzleMultipliers
 *
 * Reads a row of multipliers from standard input.
 * Puts the multipliers insed the correct row of the matrix used to hold multipliers in the game.
 * This process is done in row order.
 *
 * @param ruzzleMultipliersMatrix	Matrix used to represent the multipliers scheme in Ruzzle
 * @param matrixSize				The size of the matrix
 *
 * @return	ReturnType_Success if the string for ending the procedure has been given as an input,
 *          ReturnType_Terminated if the input sequence was terminated by the user,
 * 			0 if something went wrong while reading all matrix rows,
 * 			the length of the last read row otherwise
 */
int InteractiveMenuInputRuzzleMultipliers(char **ruzzleMultipliersMatrix, int matrixSize)
{
    unsigned int i = 0, j = 0, bValid = 0;
    int iRead = 0;
    char sBuffer[RUZZLE_INPUT_STRING_MAX_LENGTH] = {0};

    printf("*** Ruzzle scheme bonuses Input, in row order - You can exit this procedure at any time by typing \"0\" ***\n\n");
    /* Printing possible bonuses to the user */
    PrintPossibleBonuses();

    for(i = 0; i < matrixSize; i++)
    {
        do
        {
            memset(sBuffer, 0, RUZZLE_INPUT_STRING_MAX_LENGTH);
            printf("Insert bonuses for row %i: ", (i + 1));

            if((iRead = SafeScanf(sBuffer, matrixSize + 1)) == matrixSize)
            {
                if(iRead == 1 && sBuffer[0] == '0')
                {
                    printf("Terminating...\n\n");
                    bValid = 1;
                }
                else
                {
                    bValid = 1;
                    for(j = 0; j < matrixSize; j++)
                    {
                        if(sBuffer[j] != 'D'
                            && sBuffer[j] != 'T'
                            && sBuffer[j] != 'd'
                            && sBuffer[j] != 't'
                            && sBuffer[j] != '.')
                        {
                            printf("Invalid input, ");
                            /* Printing possible bonuses to the user */
                            PrintPossibleBonuses();
                            bValid = 0;
                            break;
                        }
                    }
                }
            }
            else if(iRead == 1 && sBuffer[0] == '0')
            {
                printf("Terminating...\n\n");
                bValid = 1;
            }
            else
            {
            	printf("Invalid input, the number of bonuses must match the desired matrix size\n\n");
            	bValid = 0;
            }
        } while(!bValid);

        /* Validating input buffer */
        ValidateBuffer(sBuffer);

        if(sBuffer[0] == '0' && sBuffer[1] == '\0')
        {
            return ReturnType_Terminated;
        }

        /* Inserting read row into matrix */
        ParseSchemeRow(ruzzleMultipliersMatrix, matrixSize, i, sBuffer, 0);
    }

    return iRead;
}

/**
 * ShowInteractiveMenu
 *
 * Container used to display all the various menues used to read data from standard input.
 * Mostly used just to make code reading more elegant.
 *
 * @param matrixSize			The size of the scheme in ruzzle (used for both multipliers and letters scheme)
 * @param ruzzleLettersMatrix	Matrix used to represent the letters scheme in Ruzzle
 * @param ruzzleBonusesMatrix	Matrix used to represent the multipliers scheme in Ruzzle
 *
 * @return	ReturnType_Success if the process of reading all Ruzzle data from standard input was successful,
 * 			a value less than or equals to zero otherwise
 */
ReturnType_t ShowInteractiveMenu(unsigned int *matrixSize, char **ruzzleLettersMatrix, char **ruzzleBonusesMatrix)
{
    int iResult = ReturnType_Success;

    printf("\n--------------------------------------------------\n\n");

    /* Outputting menu to the user for matrixSize input */
    iResult = InteractiveMenuInputSize();
    if(iResult < 0)
    {
        return iResult;
    }

    *matrixSize = iResult;

    printf("\n--------------------------------------------------\n\n");

    /* Outputting menu to the user for matrix representing Ruzzle letters scheme input */
    *ruzzleLettersMatrix = calloc((*matrixSize) * (*matrixSize), sizeof(char));
    iResult = InteractiveMenuInputRuzzleLetters(ruzzleLettersMatrix, *matrixSize);
    if(iResult <= 0)
    {
        return iResult;
    }

    printf("\n--------------------------------------------------\n\n");

    /* Outputting menu to the user for matrix representing Ruzzle multipliers scheme input */
    *ruzzleBonusesMatrix = calloc((*matrixSize) * (*matrixSize), sizeof(char));
    iResult = InteractiveMenuInputRuzzleMultipliers(ruzzleBonusesMatrix, *matrixSize);
    if(iResult <= 0)
    {
        return iResult;
    }

    printf("\n--------------------------------------------------\n\n");
    printf("*** Ruzle Words Input - You can exit this procedure at any time by typing \"0\" ***");

    return iResult;
}

#if 0
/**
 * PrintPathToConsole
 *
 * Prints to standard output all the paths found for a certain word.
 *
 * @param word      The word that the paths belong to
 * @param pPath     The paths relative to the word
 *
 * @return  ReturnType_Error if one of the inputs is empty,
 *          ReturnType_Success otherwise
 */
ReturnType_t PrintPathToConsole(const char* word, path_t* pPath)
{
    unsigned int i;
    if(word == NULL || pPath == NULL)
    {
        return ReturnType_Error;
    }

    printf("%s %i ", word, pPath->score);
    for(i = 0; i < pPath->n_valid; i++)
    {
        cell_t cell = pPath->p_cells[i];

        if(i == (pPath->n_valid - 1))
        {
            printf("(%d,%d)", cell.row, cell.column);
        }
        else
        {
            printf("(%d,%d)->", cell.row, cell.column);
        }
    }

    printf("\n");
    return ReturnType_Success;
}
#else
/**
 * PrintPathToConsole
 *
 * Prints to standard output all the paths found for a certain word.
 *
 * @param word	    The word that the paths belong to
 * @param pPath	    The paths relative to the word
 *
 * @return	ReturnType_Error if one of the inputs is empty,
 * 			ReturnType_Success otherwise
 */
ReturnType_t PrintPathToConsole(const char* word, path_t* pPath)
{
    unsigned int i;
    if(word == NULL || pPath == NULL)
    {
        return ReturnType_Error;
    }

    printf("%s %i ", word, pPath->score);
    for(i = 0; i < pPath->n_valid; i++)
    {
        cell_t cell = pPath->p_cells[i];

        if(i == (pPath->n_valid - 1))
        {
            printf("(%d, %d)", cell.row, cell.column);
        }
        else
        {
            printf("(%d, %d)->", cell.row, cell.column);
        }
    }

    printf("\n");
    return ReturnType_Success;
}
#endif
