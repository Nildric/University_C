#ifndef RUZZLE_H_
#define RUZZLE_H_

#include "common.h"

/* This struct represents a cell in a matrix */
typedef struct
{
    unsigned int row;
    unsigned int column;
} cell_t;

/* This struct contains the neighbouring cells of a cell */
typedef struct
{
    cell_t neighbours[8]; /* neighbouring cells */
    unsigned int n_valid; /* number of valid neighbouring cells */
} neighbours_t;

/* This struct represents a path within the matrix */
typedef struct
{
    cell_t* p_cells;            /* dynamically-allocated array of cells representing the path (usually set to the word's size) */
    unsigned int n_valid;       /* number of valid path cells */
    unsigned int score;         /* final score of the path, includes bonuses */
} path_t;

/* This struct is a buffer of paths */
typedef struct
{
    path_t max_score_path;          /* max-scoring path, used for offline mode (unused in interactive mode) */
    path_t* p_paths;                /* dynamically-allocated array of paths used in interactive mode (unused in offline mode, set to NULL) */
    unsigned int paths_size;        /* current size of the paths array (used for dynamic allocation) */
    unsigned int n_valid;           /* number of valid paths */
    unsigned int n_total_paths;     /* total number of paths (different from number of valid paths because it's not flushed when MAX_NUM_PATHS is hit) */
} paths_buffer_t;

#endif /* RUZZLE_H_ */
