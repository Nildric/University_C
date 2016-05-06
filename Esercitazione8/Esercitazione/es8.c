/*
 * 857179	Federico Longhin
 */

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>

int main ()
{
    int iMenuEntry;

    srand(time(NULL));

    do
    {
        printf("Choose the part to execute:\n\t1 \t: Part 1 (Christmas tree)\n\t2 \t: Part 2 (Tic-tac-toe)\n\tother \t: Exit\n\n");
        scanf("%i", &iMenuEntry);

        if (iMenuEntry == 1)
        {
            int iTreeWidth;
            int iExternalCounter, iInternalCounter;
            float fTreeWidth, fTreeBaseWidth, fTreeBaseHeight;

            do
            {
                printf("Insert the width of your tree (must be a positive odd number)\n");
                scanf("%i", &iTreeWidth);
            } while (iTreeWidth % 2 == 0 || iTreeWidth <= 0);

            for (iExternalCounter = 1; iExternalCounter <= iTreeWidth; iExternalCounter += 2)
            {
				for (iInternalCounter = 0; iInternalCounter < ((iTreeWidth - iExternalCounter) / 2); iInternalCounter++)
				{
					printf(" ");
				}

				for (iInternalCounter = 0; iInternalCounter < iExternalCounter; iInternalCounter++)
				{
					if (iInternalCounter % 2 == 0)
					{
						printf("*");
					}
					else
					{
						printf("0");
					}
				}

				for (iInternalCounter = 0; iInternalCounter < ((iTreeWidth - iExternalCounter) / 2); iInternalCounter++)
				{
					printf(" ");
				}

				printf("\n");
            }

            fTreeWidth = (float)iTreeWidth;

            fTreeBaseWidth = roundf(fTreeWidth / 4);
            if ((int)fTreeBaseWidth % 2 == 0)
			{
            	fTreeBaseWidth = fTreeBaseWidth + 1;
			}
            fTreeBaseHeight = ceil(fTreeWidth / 10);

            for (iExternalCounter = 0; iExternalCounter < fTreeBaseHeight; iExternalCounter++)
            {
            	for (iInternalCounter = 0; iInternalCounter < ((fTreeWidth - fTreeBaseWidth) / 2); iInternalCounter++)
            	{
            		printf(" ");
            	}

            	for (iInternalCounter = 0; iInternalCounter < fTreeBaseWidth; iInternalCounter++)
				{
					printf("|");
				}

            	for (iInternalCounter = 0; iInternalCounter < ((fTreeWidth - fTreeBaseWidth) / 2); iInternalCounter++)
				{
					printf(" ");
				}

            	printf("\n");
            }
        }

        if (iMenuEntry == 2)
        {
        	int iChallengeAI = 0;
			int iTurn = 0;
			int iInputX, iInputY = 0;
			int iP1 = 0, iP2 = 0;
			int iPlayerWon = 0;
			int iDraw = 0;

			printf("Do you want to challenge the AI? (0=No, 1=Yes)\n");
			scanf("%i", &iChallengeAI);

			{
				int row;
				int column;
				for(row = 0; row < 3; row++)
				{
					for(column = 0; column < 3; column++)
					{
						printf(" ");

						if(column < 2)
						{
							printf("|");
						}
					}

					printf("\n");

					if(row < 2)
					{
						printf("-+-+-");
						printf("\n");
					}
				}
			}

			do
			{
				int iWeight = 0;
				int iInputInvalid = 0;
				int iRedoInput = 0;
				int iFreeP1 = 0, iFreeP2 = 0;
				int iAIChoiceX = 0, iAIChoiceY = 0;
				int row, column;
				int b0, b1, b2, b3, b4, b5, b6, b7, b8;
				int w = 1;

				printf("Player %i's turn...\n", (iTurn + 1));

				if(iTurn == 1 && iChallengeAI == 1)
				{
					do
					{
						iAIChoiceX = ((double)rand() / (double)RAND_MAX) * 3;
						iAIChoiceY = ((double)rand() / (double)RAND_MAX) * 3;

						iInputInvalid = iAIChoiceX < 0 || iAIChoiceX > 2 || iAIChoiceY < 0 || iAIChoiceY > 2;
						if(!iInputInvalid)
						{
							iWeight = pow(2, (3 * iAIChoiceX) + iAIChoiceY);
							iFreeP1 = (((iP1 / iWeight) / 2) * 2) == (iP1 / iWeight);
							iFreeP2 = (((iP2 / iWeight) / 2) * 2) == (iP2 / iWeight);
						}

					} while(iInputInvalid || !iFreeP1 || !iFreeP2);
				}
				else
				{
					printf("Insert the x and y coordinates:\n");
					scanf("%i %i", &iInputX, &iInputY);

					iInputInvalid = iInputX < 0 || iInputX > 2 || iInputY < 0 || iInputY > 2;
					if(!iInputInvalid)
					{
						iWeight = pow(2, (3 * iInputX) + iInputY);
						iFreeP1 = (((iP1 / iWeight) / 2) * 2) == (iP1 / iWeight);
						iFreeP2 = (((iP2 / iWeight) / 2) * 2) == (iP2 / iWeight);
					}

					if(iInputInvalid || !iFreeP1 || !iFreeP2)
					{
						printf("Bad coordinates, or location already filled\n");
						iRedoInput = 1;
					}
				}

				if(!iRedoInput)
				{
					if(iTurn == 0)
					{
						iP1 += iWeight;
					}
					else
					{
						iP2 += iWeight;
					}

					for(row = 0; row < 3; row++)
					{
						for(column = 0; column < 3; column++)
						{
							iWeight = pow(2, (3 * row) + column);
							iFreeP1 = (((iP1 / iWeight) / 2) * 2) == (iP1 / iWeight);
							iFreeP2 = (((iP2 / iWeight) / 2) * 2) == (iP2 / iWeight);

							if(iFreeP1 && iFreeP2)
							{
								printf(" ");
							}
							else if(!iFreeP1)
							{
								printf("x");
							}
							else
							{
								printf("o");
							}

							if(column < 2)
							{
								printf("|");
							}
						}

						printf("\n");

						if(row < 2)
						{
							printf("-+-+-");
							printf("\n");
						}
					}

					b0 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b1 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b2 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b3 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b4 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b5 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b6 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b7 = (((iP1 / w) / 2) * 2) != (iP1 / w);
					w *= 2;
					b8 = (((iP1 / w) / 2) * 2) != (iP1 / w);

					if((b0 && b1 && b2) || (b3 && b4 && b5) || (b6 && b7 && b8) ||
					   (b0 && b3 && b6) || (b1 && b4 && b7) || (b2 && b5 && b8) ||
					   (b0 && b4 && b8) || (b2 && b4 && b6))
					{
						iPlayerWon = 1;
					}
					else
					{
						w = 1;
						b0 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b1 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b2 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b3 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b4 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b5 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b6 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b7 = (((iP2 / w) / 2) * 2) != (iP2 / w);
						w *= 2;
						b8 = (((iP2 / w) / 2) * 2) != (iP2 / w);

						if((b0 && b1 && b2) || (b3 && b4 && b5) || (b6 && b7 && b8) ||
						   (b0 && b3 && b6) || (b1 && b4 && b7) || (b2 && b5 && b8) ||
						   (b0 && b4 && b8) || (b2 && b4 && b6))
						{
							iPlayerWon = 2;
						}
					}


					iDraw = ((iP1 + iP2) == 511);

					if(iTurn == 0)
					{
						iTurn = 1;
					}
					else
					{
						iTurn = 0;
					}
				}
			} while(!iPlayerWon && !iDraw);

			if(iPlayerWon)
			{
				printf("Player %i win!\n\n", iPlayerWon);
			}
			else if(iDraw)
			{
				printf("Draw!\n");
			}
        }
    } while (iMenuEntry == 1 || iMenuEntry == 2);

    return 0;
}
