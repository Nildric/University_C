#ifndef RUZZLE_FILE_IO_H_
#define RUZZLE_FILE_IO_H_

#include "ruzzle.h"
#include "ruzzle_io_util.h"
#include "ruzzle_scheme_parsing.h"

/* Current state of the Ruzzle scheme file parser */
typedef enum
{
    FileParser_State_Matrix_Size,
    FileParser_State_Letters_Matrix,
    FileParser_State_Bonuses_Matrix,
    FileParser_State_Max
} FileParser_State_t;

int ReadRuzzleSchemeFromFile(char *filePath, unsigned int *matrixSize, char **ruzzleLettersMatrix, char **ruzzleBonusesMatrix);
int ReadDictionaryStringOffline(char *dictionaryPath, unsigned int* startPos, char* pBuffer, size_t bufferSize);
ReturnType_t PrintPathToFile(char* filePath, char* word, path_t* pPath);
ReturnType_t EraseFile(char* filePath);

#endif /* RUZZLE_FILE_IO_H_ */
