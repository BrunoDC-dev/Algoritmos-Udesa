#include "tp1.h"
#include <stdlib.h>
#include <math.h>
bool is_prime(int x){

    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int storage_capacity(float d, float v){
    
    return (int) floor(d / v);
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int array_max(const int *array, int length) {
     int max = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

void array_map(int *array, int length, int f(int)) {
      if (f == NULL) {
        return;
    }

    for (int i = 0; i < length; i++) {
        array[i] = f(array[i]);
    }
}

int *copy_array(const int *array, int length) {
     if (array == NULL) return NULL;
    int *copy = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        copy[i] = array[i];
    }
    return copy;
}

int **copy_array_of_arrays(const int **array_of_arrays, const int *array_lenghts, int array_amount){
    if (array_of_arrays == NULL) return NULL;
    int **copy = malloc(array_amount * sizeof(int *));
    for (int i = 0; i < array_amount; i++) {
        copy[i] = copy_array(array_of_arrays[i], array_lenghts[i]);
    }
    return copy;
}

void free_array_of_arrays(int **array_of_arrays, int *array_lenghts, int array_amount){
    
    for (int i = 0; i < array_amount; i++) {
        free(array_of_arrays[i]);
    }
        free(array_of_arrays);
        free (array_lenghts);
}

void bubble_sort(int *array, int length){
     if (array == NULL) return;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) swap(&array[j], &array[j + 1]);
        }
    }
}

bool array_equal(const int *array1, int length1, const int *array2, int length2){
    if (length1 != length2) return false;
    if (array1 == NULL || array2 == NULL) return array1 == array2;

    for (int i = 0; i < length1; i++) {
        if (array1[i] != array2[i]) return false;
    }
    return true;
}

bool integer_anagrams(const int *array1, int length1,
                      const int *array2, int length2){
    if (array1 == NULL && array2 == NULL) return false;
    if (length1 != length2) return false;
    int *copy1 = copy_array(array1, length1);
    int *copy2 = copy_array(array2, length2);
    bubble_sort(copy1, length1);
    bubble_sort(copy2, length2);
    bool result = array_equal(copy1, length1, copy2, length2);
    free(copy1);
    free(copy2);
    return result;
}