#ifndef RUZZLE_SCORES_H_
#define RUZZLE_SCORES_H_

#include "ruzzle.h"

/* Types of multipliers for word bonuses */
typedef enum
{
    Score_Multiplier_Default = 1,
    Score_Multiplier_Double = 2,
    Score_Multiplier_Triple = 3,
    Score_Multiplier_Max
} score_multiplier_t;

/* Types of letter scores */
typedef enum
{
    Letter_Score_Lowest = 1,          /* A, E, I, O */
    Letter_Score_Intermediate_1 = 2,  /* C, R, S, T */
    Letter_Score_Intermediate_2 = 3,  /* L, M, N, U */
    Letter_Score_Intermediate_3 = 4,  /* Y */
    Letter_Score_Intermediate_4 = 5,  /* B, D, F, K, P, V */
    Letter_Score_Intermediate_5 = 8,  /* G, H, Z */
    Letter_Score_Highest = 10,        /* J, Q, W, X */
    Letter_Score_Max
} letter_score_t;

int EvaluateMultiplier(char toEvaluateMultiplier);
int EvaluateLetter(char toEvaluateLetter);
int EvaluateLetterScore(char *bonusesMatrix, int matrixSize, char letterToEvaluate, unsigned int row, unsigned int column, unsigned int *score, unsigned int *wordMultiplier);
int EvaluatePathScore(char *bonusesMatrix, int matrixSize, path_t* pPath, const char* word);

#endif /* RUZZLE_SCORES_H_ */
