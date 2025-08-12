#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 256  

void fill_array(int* array, char* str) {
    int index = 0;
    while (str[index] != '\0') {  
        array[(int)str[index]] += 1;  
        index += 1;
    }
}

void print_array(int* array) {
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        if (array[i] > 0) {  
            if (i == 32)  
                printf(" :%d\n", array[i]);
            else
                printf("%c:%d\n", i, array[i]);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s str [str2, str3, ...]\n", argv[0]);
        return 1;
    }

    int frequency[MAX_ARRAY_SIZE] = {0};

    for (int i = 1; i < argc; i++) {
        fill_array(frequency, argv[i]);
    }

    print_array(frequency);

    return 0;
}
