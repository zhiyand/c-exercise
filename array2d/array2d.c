#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array2D{
    int rows;
    int cols;
    int * array;
    int * widths;
};

/*
 * Create and initiate a 2d array with `rows` rows and `cols` columns.
 */
struct Array2D array2d_create(int rows, int cols){
    struct Array2D array2d;
    int bytes = sizeof(int) * rows * cols;

    array2d.rows   = rows;
    array2d.cols   = cols;
    array2d.array  = (int*) malloc(bytes);
    array2d.widths = (int*) malloc(bytes / rows);

    memset((void*)array2d.array, 0, bytes);
    memset((void*)array2d.widths, 0, bytes / rows);

    return array2d;
}

/*
 * Count the number of digits in the integer `value`
 */
int array2d_count_digits(int value){
    int i = 0, n = value, digits = 0;

    for(i = 0; 1; i++){
        n = n / 10;
        if(n == 0){
            break;
        }
    }

    digits = i+1;
    if(value < 0){
        digits += 1;
    }

    return digits;
}

/*
 * Set the value of `array2d` at row `row`, column `col` to `value`
 */
void array2d_set(struct Array2D array2d, int row, int col, int value){
    array2d.array[ row * array2d.cols + col ] = value;

    int digits = array2d_count_digits(value);
    if(digits > array2d.widths[col]){
        array2d.widths[col] = digits;
    }
}

/*
 * Get the value of `array2d` at row `row`, column `col`
 */
int array2d_get(struct Array2D array2d, int row, int col){
    return array2d.array[ row * array2d.cols + col ];
}

void array2d_display_horizontal_line(struct Array2D array2d){
    int j = 0, k = 0;
    for(j = 0; j < array2d.cols; j++){
        printf("+");
        for(k = 0; k < array2d.widths[j]; k++){
            printf("-");
        }
    }
    printf("+\n");
}

void array2d_display_row(struct Array2D array2d, int row){
    int j = 0;
    char format[10] = { '\0' };
    for(j = 0; j < array2d.cols; j++){
        printf("|");
        sprintf(format, "%%-%dd", array2d.widths[j]);
        printf(format, array2d_get(array2d, row, j));
    }
    printf("|\n");
}

/*
 * Display the 2d array `array2d`
 */
void array2d_display(struct Array2D array2d){
    int i = 0, j = 0, k = 0;

    for(i = 0; i < array2d.rows; i++){
        array2d_display_horizontal_line(array2d);

        array2d_display_row(array2d, i);
    }
    array2d_display_horizontal_line(array2d);
}

/*
 * Destroy and release a 2d array
 */
void array2d_destroy(struct Array2D array2d){
    array2d.rows = 0;
    array2d.cols = 0;
    free(array2d.array);
    free(array2d.widths);
}


int main(void){
    struct Array2D my_array = array2d_create(2, 3);

    array2d_set(my_array, 0, 0, 39);
    array2d_set(my_array, 0, 1, -21);
    array2d_set(my_array, 0, 2, 11);
    array2d_set(my_array, 1, 0, -4632);
    array2d_set(my_array, 1, 1, 968723);
    array2d_set(my_array, 1, 2, 701);

    array2d_display(my_array);

    array2d_destroy(my_array);

    return 0;
}
