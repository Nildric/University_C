#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#ifndef RUZZLE_INPUT_STRING_MAX_LENGTH
    #define RUZZLE_INPUT_STRING_MAX_LENGTH 128 /* Max length of an input string, used when reading from files/console */
#endif

#ifndef RUZZLE_MAX_NUM_PATHS
    #define RUZZLE_MAX_NUM_PATHS 512 /* Maximum number of paths we can save, depends on word length and heap size */
#endif

#ifndef RUZZLE_INITIAL_PATH_ARRAY_SIZE
    #define RUZZLE_INITIAL_PATH_ARRAY_SIZE 32 /* The initial array size for the paths buffer */
#endif

#ifndef RUZZLE_PATH_ARRAY_INCREMENT_SIZE
    #define RUZZLE_PATH_ARRAY_INCREMENT_SIZE 16 /* Block size to increment the paths buffer by when it runs out of space (still honors the MAX_NUM_PATHS limit) */
#endif

#ifndef RUZZLE_CALCULATE_SCORES_TRAVERSE /* Calculate scores as we traverse each path */
    #define RUZZLE_CALCULATE_SCORES_END /* Calculate scores after having computed all valid paths */
#endif

#ifndef RUZZLE_OFFLINE_PARAMETER_COUNT
    #define RUZZLE_OFFLINE_PARAMETER_COUNT 4 /* How many parameters we expect in argc (including the program's path) when checking if the program is in offline mode */
#endif

typedef enum
{
    ReturnType_Terminated = -4,     /* Input was terminated by the user */
    ReturnType_Overflow = -3,       /* Controlled overflow, e.g. we couldn't add a path to a buffer */
    ReturnType_OutOfMemory = -2,    /* out_of_memory was triggered, heap is full */
    ReturnType_Error = -1,          /* Generic error */
    ReturnType_Success = 0
} ReturnType_t;

typedef enum
{
    GameMode_Offline = 0,
    GameMode_Interactive
} GameMode_t;

extern GameMode_t g_tGameMode;

#endif /* COMMON_H_ */
