#include <stdio.h>
#include <stdlib.h>

int* my_range(int param_1, int param_2) {
    int size = param_2 - param_1;
    if (size <= 0) return NULL;

    int* myNumbers = (int*)malloc(sizeof(int) * size);
    if (myNumbers == NULL) return NULL;

    for (int i = 0; i < size; i++) {
        myNumbers[i] = param_1 + i;
    }

    return myNumbers;
}
