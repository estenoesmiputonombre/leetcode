#include <assert.h>

#include <limits.h>

#include <math.h>

#include <stdbool.h>

#include <stddef.h>

#include <stdint.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

char * readline();
char ** split_string(char * );
void swap(int * a, int * b);

/*
Array is sorted in 3 swaps.
First Element: 1
Last Element: 3
*/
// Complete the countSwaps function below.
void countSwaps(int a_count, int * a) {
    int firstElement = -1,
        lastElement = -1,
        numSwap = 0;
    for (int i = 0; i < a_count - 1; i++) {
        for (int j = i + 1; j < a_count; j++) {
            if ( * (a + j) < * (a + i)) {
                swap((a + j), (a + i));
                numSwap++;
            }
        }
    }
    firstElement = * (a);
    lastElement = * (a + a_count - 1);
    printf("Array is sorted in %d swaps.\n", numSwap);
    printf("First Element: %d\n", firstElement);
    printf("Last Element: %d\n", lastElement);
}

void swap(int * a, int * b) {
    int temp = * a;
    * a = * b;
    * b = temp;
}

int main() {
    char * n_endptr;
    char * n_str = readline();
    int n = strtol(n_str, & n_endptr, 10);

    if (n_endptr == n_str || * n_endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    char ** a_temp = split_string(readline());

    int * a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char * a_item_endptr;
        char * a_item_str = * (a_temp + i);
        int a_item = strtol(a_item_str, & a_item_endptr, 10);

        if (a_item_endptr == a_item_str || * a_item_endptr != '\0') {
            exit(EXIT_FAILURE);
        }

        *(a + i) = a_item;
    }

    int a_count = n;

    countSwaps(a_count, a);

    return 0;
}

char * readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char * data = malloc(alloc_length);

    while (true) {
        char * cursor = data + data_length;
        char * line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char ** split_string(char * str) {
    char ** splits = NULL;
    char * token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char * ) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
