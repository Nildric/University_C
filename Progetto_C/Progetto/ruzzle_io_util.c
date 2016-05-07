#include "ruzzle_io_util.h"

/**
 * RemoveSpaces
 *
 * Removes spaces from a string, replaces the input string with the space-stripped one
 *
 * @param string    The string to remove spaces from
 */
void RemoveSpaces(char *string)
{
    unsigned int i, uiNoSpaceCounter = 0;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] != ' ')
        {
            string[uiNoSpaceCounter++] = string[i];
        }
    }

    string[uiNoSpaceCounter] = '\0';
}

/**
 * ValidateBuffer
 *
 * Validates a string buffer fetched by getline() by removing spaces and the newline character
 * and doing size checks on the processed string
 *
 * @param buffer    The getline()-generated buffer to validate
 *
 * @return  ReturnType_Error if the buffer is empty after processing,
 *          ReturnType_Success otherwise
 */
ReturnType_t ValidateBuffer(char *buffer)
{
    size_t sLength;
    RemoveSpaces(buffer);

    sLength = strlen(buffer);
    if(sLength > 0)
    {
        if(buffer[sLength - 1] == '\n')
        {
            buffer[sLength - 1] = '\0';
        }

        if(buffer[0] != '\0')
        {
            return ReturnType_Success;
        }
    }

    return ReturnType_Error;
}

/**
 * StringToUpperCase
 *
 * Turn a string to an full uppercase string, maintaining the same characters.
 *
 * @param string    String that will be turned uppercase
 */
void StringToUpperCase(char *string)
{
    unsigned int i;
    /* Cycling the string */
    for(i = 0; string[i] != '\0'; i++)
    {
        /* Turning every character to an uppercase character */
        string[i] = (char)toupper(string[i]);
    }
}

/**
 * CheckValidAlphaString
 *
 * Check if a string is made only by characters belonging to the english alphabet.
 *
 * @param string    String that will be checked
 *
 * @return  0 in case the string doesn't belong to the english alphabet,
 *          1 otherwise
 */
int CheckValidAlphaString(char *string)
{
    unsigned int i;
    /* Cycling the string */
    for(i = 0; string[i] != '\0'; i++)
    {
        /* Checking if the current character doesn't belong to the english alphabet */
        if(!(string[i] >= 'a' && string[i] <= 'z') && !(string[i] >= 'A' && string[i] <= 'Z'))
        {
            return 0;
        }
    }

    return 1;
}
