#include "ruzzle_scheme_parsing.h"

/**
 * ParseSchemeRow
 *
 * Parses a row from the loaded scheme into the specified matrix.
 * Accounts for the letter matrix by converting all characters to uppercase
 *
 * @param matrix            Matrix to store the parsed values in
 * @param matrixSize        Size of the output matrix
 * @param rowIndex          Current parsing row index
 * @param schemeRow         Current row buffer
 * @param bLetterMatrix     If true, values will be converted to uppercase
 *
 * @return  ReturnType_Error if some parsing error occurred,
 *          ReturnType_Success otherwise
 */
ReturnType_t ParseSchemeRow(char **matrix, unsigned int matrixSize, unsigned int rowIndex, char *schemeRow, unsigned int bLetterMatrix)
{
    unsigned int lColumnIndex;
    for(lColumnIndex = 0; lColumnIndex < matrixSize && schemeRow[lColumnIndex] != '\0'; lColumnIndex++)
    {
        /* matrixOffset is used to identify a single cell in the matrix[rowIndex, columnIndex] */
        unsigned int matrixOffset = rowIndex * matrixSize + lColumnIndex;
        (*matrix)[matrixOffset] = schemeRow[lColumnIndex];

        if(bLetterMatrix) /* If this is a letter matrix, convert characters to uppercase */
        {
            (*matrix)[matrixOffset] = toupper((*matrix)[matrixOffset]);
        }
    }

    if(lColumnIndex != matrixSize)
    {
        return ReturnType_Error;
    }

    return ReturnType_Success;
}
