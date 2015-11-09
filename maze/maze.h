/**
 * A console-based maze game
 * C excercise
 */

#ifndef __MAZE__
#define __MAZE__

struct _Maze{
    char * grid;

    int rows;
    int cols;

    // Cursor
    int r;  // row
    int c;  // col

    // Destination
    int R;  // row
    int C;  // col
};

typedef struct _Maze * Maze;

/*
 * Initialize an empty maze
 */
Maze maze_init(int rows, int cols);

/*
 * Free a maze
 * `maze` itself should be set to NULL after calling this function.
 */
void maze_free(Maze maze);

void maze_display(Maze maze);

/*
 * Load maze layout from standard input
 */
Maze maze_load(const char * filename);

/*
 * Process a input character
 */
void maze_process(Maze maze, char ch);

int is_maze_won(Maze maze);

#endif