#ifndef RUZZLE_CONSOLE_IO_H_
#define RUZZLE_CONSOLE_IO_H_

#include "common.h"
#include "ruzzle.h"
#include "ruzzle_io_util.h"
#include "ruzzle_scheme_parsing.h"
#include <fcntl.h>

int SafeScanf(char *pBuffer, size_t bufferSize);
int ReadDictionaryInteractive(char* pBuffer, size_t bufferSize);
int InteractiveMenuInputSize();
int InteractiveMenuInputRuzzleLetters(char **ruzzleSchemeMatrix, int matrixSize);
void PrintPossibleBonuses();
int InteractiveMenuInputRuzzleMultipliers(char **ruzzleMultipliersMatrix, int matrixSize);
ReturnType_t ShowInteractiveMenu(unsigned int *matrixSize, char **ruzzleLettersMatrix, char **ruzzleBonusesMatrix);
ReturnType_t PrintPathToConsole(const char* word, path_t* pPath);

#endif /* RUZZLE_CONSOLE_IO_H_ */
