#include "ruzzle_scores.h"

/**
 * EvaluateMultiplier
 *
 * Get the numerical multiplier given the multiplier tag
 *
 * @param toEvaluateMultiplier  Multiplier tag (t, d, D or T) case-sensitive
 *
 * @return the numerical multiplier
 */
int EvaluateMultiplier(char toEvaluateMultiplier)
{
    int iReturn = Score_Multiplier_Default;
    switch(toEvaluateMultiplier)
    {
        case 'd': case 'D':
        {
            iReturn = Score_Multiplier_Double;
            break;
        }

        case 't': case 'T':
        {
            iReturn = Score_Multiplier_Triple;
            break;
        }

        default:
        {
            iReturn = Score_Multiplier_Default;
            break;
        }
    }

    return iReturn;
}

/**
 * EvaluateLetter
 *
 * Get the letter's value based on Ruzzle's scoring rules
 *
 * @param toEvaluateLetter      Letter to get the score of (MUST be uppercase and A~Z)
 *
 * @return ReturnType_Error if no matching value could be found,
 *         the letter's value otherwise
 */
int EvaluateLetter(char toEvaluateLetter)
{
    int iReturn = ReturnType_Error;
    switch(toEvaluateLetter)
    {
        case 'J': case 'Q': case 'W': case 'X':
        {
            iReturn = Letter_Score_Highest;
            break;
        }
        case 'G': case 'H': case 'Z':
        {
            iReturn = Letter_Score_Intermediate_5;
            break;
        }
        case 'B': case 'D': case 'F': case 'K': case 'P': case 'V':
        {
            iReturn = Letter_Score_Intermediate_4;
            break;
        }
        case 'Y':
        {
            iReturn = Letter_Score_Intermediate_3;
            break;
        }
        case 'L': case 'M': case 'N': case 'U':
        {
            iReturn = Letter_Score_Intermediate_2;
            break;
        }
        case 'C': case 'R': case 'S': case 'T':
        {
            iReturn = Letter_Score_Intermediate_1;
            break;
        }
        case 'A': case 'E': case 'I': case 'O':
        {
            iReturn = Letter_Score_Lowest;
            break;
        }
    }

    return iReturn;
}

/**
 * EvaluateLetterScore
 *
 * Evaluate a letter's score based on Ruzzle's scoring rules.
 * Adds the letter's value and multiplies it by any bonus multipliers (such as d and t)
 * Saves the numerical word multiplier if any exists (such as D and T)
 *
 * @param bonusesMatrix         The matrix containing bonuses in character form
 * @param matrixSize            Size of the bonuses matrix
 * @param letterToEvaluate      Letter to find the score of
 * @param row                   Current row of the letter in the letters matrix
 * @param column                Current column of the letter in the letters matrix
 * @param score                 Output score
 * @param wordMultiplier        Output word multiplier
 *
 * @return  ReturnType_Error if the evaluation did not succeed,
 *          ReturnType_Success otherwise
 */
int EvaluateLetterScore(char *bonusesMatrix, int matrixSize, char letterToEvaluate, unsigned int row, unsigned int column, unsigned int *score, unsigned int *wordMultiplier)
{
    char cBonus;
    int iCurrentMultiplier;
    int iLetterValue;

    if(letterToEvaluate == '\0')
    {
        return ReturnType_Error;
    }

    cBonus = bonusesMatrix[row * matrixSize + column];
    iCurrentMultiplier = EvaluateMultiplier(cBonus);
    iLetterValue = EvaluateLetter(letterToEvaluate);

    if(iCurrentMultiplier == ReturnType_Error || iLetterValue == ReturnType_Error)
    {
        return ReturnType_Error;
    }

    if(cBonus == 'D' || cBonus == 'T')
    {
        *wordMultiplier *= iCurrentMultiplier;
    }
    else
    {
        iLetterValue *= iCurrentMultiplier;
    }

    *score += iLetterValue;

    return ReturnType_Success;
}

/**
 * EvaluatePathScore
 *
 * Evaluates the score of a specific path for a specific word.
 *
 * @param bonusesMatrix     The matrix containing bonuses in character form
 * @param matrixSize        The size of the matrix
 * @param pPath             Path to evaluate
 * @param word              Word that the path belongs to
 *
 * @return  ReturnType_Error if something went wrong during path evaluation
 *          the score of the path otherwise
 */
int EvaluatePathScore(char *bonusesMatrix, int matrixSize, path_t* pPath, const char* word)
{
    unsigned int iScore = 0;
    unsigned int iMultiplier = 1;
    int i;

    for(i = 0; i < pPath->n_valid && word[i] != '\0'; i++)
    {
        if(EvaluateLetterScore(bonusesMatrix, matrixSize, word[i], pPath->p_cells[i].row, pPath->p_cells[i].column, &iScore, &iMultiplier) != ReturnType_Success)
        {
            return ReturnType_Error;
        }
    }

    iScore *= iMultiplier;
    return iScore;
}
