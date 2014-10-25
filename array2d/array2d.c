#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array2D{
    int rows;
    int cols;
    int * array;
};

struct Array2D array2d_create(int rows, int cols){
    struct Array2D array2d;
    int bytes = sizeof(int) * rows * cols;

    array2d.rows = rows;
    array2d.cols = cols;
    array2d.array = (int*) malloc(bytes);

    memset((void*)array2d.array, 0, bytes);

    return array2d;
}

void array2d_set(struct Array2D array2d, int row, int col, int value){
    *(array2d.array + (row * array2d.cols) + col) = value;
}

int array2d_get(struct Array2D array2d, int row, int col){
    return *(array2d.array + (row * array2d.cols) + col);
}

void array2d_display_horizontal_line(int cols){
    int j = 0, k = 0;
    for(j = 0; j < cols; j++){
        printf("+");
        for(k = 0; k < 6; k++){
            printf("-");
        }
    }
    printf("+\n");
}

void array2d_display(struct Array2D array2d){
    int i = 0, j = 0, k = 0;

    for(i = 0; i < array2d.rows; i++){
        array2d_display_horizontal_line(array2d.cols);

        /* Array row */
        for(j = 0; j < array2d.cols; j++){
            printf("|");
            printf("%-6d", array2d_get(array2d, i, j));
        }
        printf("|\n");
    }
    array2d_display_horizontal_line(array2d.cols);
}


int main(void){
    struct Array2D my_array = array2d_create(2, 3);

    array2d_set(my_array, 0, 0, 39701);
    array2d_set(my_array, 0, 1, -21);
    array2d_set(my_array, 0, 2, 11);
    array2d_set(my_array, 1, 0, -4632);
    array2d_set(my_array, 1, 1, 968723);
    array2d_set(my_array, 1, 2, 701);

    array2d_display(my_array);

    return 0;
}
