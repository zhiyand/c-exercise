/**
* A console-based maze game
* C excercise
*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "maze.h"

/*---- Static Functions ----*/

char blocks[] = {
    /*  0    1    2    3 */
       '.', 'X', '@', '$'};

void maze_put(Maze maze, int row, int col, char ch)
{
    int index = maze->cols * row + col;
    maze->grid[index] = ch;
}

char maze_get(Maze maze, int row, int col)
{
    int index = maze->cols * row + col;

    if(row < 0 || row >= maze->rows || col < 0 || col >= maze->cols)
        return 0;

    return maze->grid[index];
}

void maze_move(Maze maze, char direction)
{
    int dr = maze->r; int dc = maze->c;

    switch(direction){
    case 'L':
        dc = maze->c - 1;
        break;
    case 'R':
        dc = maze->c + 1;
        break;
    case 'D':
        dr = maze->r + 1;
        break;
    case 'U':
    default:
        dr = maze->r - 1;
        break;
    }

    char ch = maze_get(maze, dr, dc);

    if(ch == '.' || ch == '$'){
        maze_put(maze, dr, dc, '@');
        maze_put(maze, maze->r, maze->c, '.');
        maze->r = dr; maze->c = dc;
    }
}

/*----// Static Functions ----*/

/*---- Exposed Functions ----*/

Maze maze_init(int rows, int cols)
{
    Maze maze = (Maze) malloc(sizeof(struct _Maze));

    maze->rows = rows;    maze->cols = cols;
    maze->r    = 0;       maze->c    = 0;
    maze->R    = cols -1; maze->C    = rows -1;

    maze->grid = (char*) malloc(rows * cols * sizeof(char));

    return maze;
}

void maze_free(Maze maze)
{
    if(NULL == maze->grid)
        return;
    free(maze->grid);
    maze->grid = NULL;

    maze->r    = 0; maze->c    = 0;
    maze->R    = 0; maze->C    = 0;
    maze->rows = 0; maze->cols = 0;
}

void maze_display(Maze maze)
{
    int i = 0; int j = 0;

    clear();

    for(i = 0; i < maze->rows; i++){
        for(j = 0; j < maze->cols; j++){
            mvaddch(i, j * 2, maze_get(maze, i, j));
        }
        addch('\n');
    }
    
    refresh();
}

/*
 * Load maze layout from standard input
 */
Maze maze_load(const char * filename)
{
    int rows = 0; int cols = 0;
    FILE * file = fopen(filename, "r");

    fscanf(file, "%d %d", &rows, &cols);

    Maze maze = maze_init(rows, cols);

    int i = 0; int j = 0;
    char ch; int CH;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            fscanf(file, "%d", &CH);
            ch = blocks[ CH ];
            maze_put(maze, i, j, ch);

            if(ch == '@'){
                maze->r = i;
                maze->c = j;
            }

            if(ch == '$'){
                maze->R = i;
                maze->C = j;
            }
        }
    }

    fclose(file);

    return maze;
}


/*
 * Process a input character
 */
void maze_process(Maze maze, char ch)
{
    switch(ch){
    case 'h': // left
        maze_move(maze, 'L');
        break;
    case 'l': // right
        maze_move(maze, 'R');
        break;
    case 'j': // down
        maze_move(maze, 'D');
        break;
    case 'k': // up
        maze_move(maze, 'U');
        break;
    }
}

int is_maze_won(Maze maze)
{
    return maze->r == maze->R && maze->c == maze->C;
}
