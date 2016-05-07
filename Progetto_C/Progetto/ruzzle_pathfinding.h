#ifndef RUZZLE_PATHFINDING_H_
#define RUZZLE_PATHFINDING_H_

#include "ruzzle.h"
#include "ruzzle_io_util.h"
#include "ruzzle_console_io.h"

int QSortCompareScoresFn(const void *a, const void *b);
int GetCellNeighbours(char* matrix, int matrixSize, int rowCur, int columnCur, char nextLetter, neighbours_t* pNeighbours);
int AddCellToPath(path_t *pPath, unsigned int row, unsigned int column, size_t wordLength);
int RemoveLastCellFromPath(path_t *pPath);
int CopyPathToPath(path_t* pPathSrc, path_t* pPathDest);
int AddPathToBuffer(paths_buffer_t* pPathsBuffer, path_t* pPath);
inline void SavePathScorePrev(path_t* pPath, unsigned int* scorePrev);
inline void ResetPathScorePrev(path_t* pPath, unsigned int scorePrev);
ReturnType_t ComputePaths(char* pLetterMatrix,
                            char* pBonusesMatrix,
                            unsigned int matrixSize,
                            const char* wordToFind,
                            size_t wordLength,
                            unsigned int currentCharacter,
                            unsigned int row,
                            unsigned int column,
                            paths_buffer_t *pPathsContainer,
                            path_t *pCurrentPath,
                            ReturnType_t* lastError);

ReturnType_t FindWordPaths(char* pLetterMatrix,
                            char* pBonusesMatrix,
                            unsigned int matrixSize,
                            const char* wordToFind,
                            size_t wordLength,
                            paths_buffer_t *pPathsContainer,
                            ReturnType_t* lastError);

#endif /* RUZZLE_PATHFINDING_H_ */
