#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** array2d(int dimension);

void rotate(int ** array, int dimension);

void display(int ** array, int dimension);


int main(int argc, char ** argv)
{
    int dimension = 5;

    int ** array = array2d(dimension);

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            array[i][j] = i * dimension + j;
        }
    }

    // Initial array
    display(array, dimension);

    // Rotate 90 degrees clockwise
    rotate(array, dimension);

    // Array after rotation
    display(array, dimension);

    free(array);
    
    return 0;
}

/**
 * Rotate one circle of the array by 90 degrees clockwise
 *
 *  .....
 *  .***.
 *  .*.*.
 *  .***.
 *  .....   -- rotate those denoted as `*`
 *
 */
void circle_rotate(int ** array, int dimension, int level){
    int box = 0;

    int range = dimension - level;


    for(int offset = 0; offset < range - level - 1; offset++){
        /* cache left */
        box = array[level+offset][level];

        /* left <- bottom */
        array[level+offset][level] = array[range -1][level + offset];

        /* bottom <- right */
        array[range -1][level + offset] = array[range -1 - offset][range -1];

        /* right <- top */
        array[range -1 - offset][range - 1] = array[level][range - 1 - offset];

        /* top <- left */
        array[level][range - 1 - offset] = box;
    }
}

/**
 * Rotate a 2D-array by 90 degrees clockwise
 */
void rotate(int ** array, int dimension){
    int half = dimension / 2;

    for(int round = 0; round < half; round++){
        circle_rotate(array, dimension, round);
    }
}


/**
 * Create a 2D array
 */
int ** array2d(int dimension){
    int ** array = (int **) malloc(sizeof(int *) * dimension);

    for(int i = 0; i < dimension; i++){
        array[i] = (int *) malloc(sizeof(int) * dimension);

        memset(array[i], 0, dimension * sizeof(int));
    }

    return array;
}

/**
 * Display a 2D array
 */
void display(int ** array, int dimension){
    for(int i = 0; i < dimension; i++){
        printf("|");
        for(int j = 0; j < dimension; j++){
            printf("%4d  ", array[i][j]);
        }
        printf("|\n");
    }
    printf("\n\n");
}

