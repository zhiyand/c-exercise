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
 * Rotate one circle of the array by one step
 *
 *  .....
 *  .***.
 *  .*.*.
 *  .***.
 *  .....   -- rotate those denoted as `*` by one step
 *
 */
void circle_rotate(int ** array, int dimension, int level){
    int box = 0;

    int range = dimension - level;

    box = array[level][level];

    /* Move left col up */
    for(int i = level+1; i < range; i++){
        array[i-1][level] = array[i][level];
    }

    /* Move bottom row left */
    for(int j = level+1; j < range; j++){
        array[range - 1][j-1] = array[range-1][j];
    }

    /* Move right col down */
    for(int i = range - 1; i > level; i--){
        array[i][range-1] = array[i-1][range-1];
    }

    /* Move top row right */
    for(int j = range -1; j > level; j--){
        array[level][j] = array[level][j-1];
    }

    array[level][level+1] = box;
}

/**
 * Rotate a 2D-array by 90 degrees clockwise
 */
void rotate(int ** array, int dimension){
    int half = dimension / 2;

    for(int round = 0; round < half; round++){

        int times = dimension - 2 * round - 1;

        for(int i = 0; i < times; i++){
            circle_rotate(array, dimension, round);
        }
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

