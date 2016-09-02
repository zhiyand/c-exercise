/**
 * Quick sort algorithm exercise.
 *
 * DUAN Zhiyan <dzy0451@gmail.com>
 */

#include <stdio.h>

/**
 * Print an array on screen.
 */
void display(int * array, int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

/**
 * Swap two elements in an array.
 */
void swap(int * array, int i, int j){
    if(i == j) return;

    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

/**
 * Sort an array in ascending order.
 */
void quick_sort(int * array, int size){
    int cursor = 1;

    if(size <= 1)
        return;

    for(int i = 1; i < size; i++){
        if(array[i] < array[0]){
            swap(array, cursor, i);
            cursor += 1;
        }
    }

    swap(array, cursor-1, 0);

    quick_sort(array, cursor-1);
    quick_sort(array + cursor, size - cursor);
}

/**
 * Find the top k elements (not in strict order) in an array.
 * The top k elements will be placed in the first k positions of the array.
 */
void top(int * array, int size, int k){
    int cursor = 1;

    if(size <= 1)
        return;

    for(int i = 1; i < size; i++){
        if(array[i] < array[0]){
            swap(array, cursor, i);
            cursor += 1;
        }
    }

    swap(array, cursor-1, 0);

    if(cursor > k)
        top(array, cursor, k);
    if(cursor < k)
        top(& array[cursor], size - cursor, k - cursor);
}

int main(int argc, char ** argv){

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

    display(array, 10);
    quick_sort(array, 10);
    display(array, 10);

    int a[] = { 1, 2, 3 };

    display(a, 3);
    quick_sort(a, 3);
    display(a, 3);

    int b[] = { 2, 1 };

    display(b, 2);
    quick_sort(b, 2);
    display(b, 2);

    int data[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

    display(data, 10);

    top(data, 10, 5);
    display(data, 10);
    top(data, 10, 4);
    display(data, 10);
    top(data, 10, 3);
    display(data, 10);

    return 0;
}
