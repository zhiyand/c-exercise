/**
 * A console-based maze game
 * C excercise
 */

 #include <stdio.h>
 #include <curses.h>
 #include <unistd.h>

 #include "maze.h"

int main(int argc, char ** argv)
{
    // Initialize curses
    WINDOW* wnd = initscr();

    // Load maze
    Maze maze = maze_load(argv[1]);

    maze_display(maze);

    // Main loop
    char ch = 0;

    while( ! is_maze_won(maze) && 'q' != ch )
    {
        if(ERR == ch)
        {
            usleep(50 * 1000);
            continue;
        }

        ch = getch();

        maze_process(maze, ch);

        maze_display(maze);
    }

    // Game won
    endwin();
    maze_free(maze); maze = NULL;

    printf("%c[f%c[2J", 27, 27);
    printf("Congrats!~ You won!\n");

    return 0;
}
