#include <stdio.h>
#include <stdlib.h>
char* my_strdup(char* param_1) {
    int size;
    int i;
    for (size = 0;param_1[size]!='\0';size++) {
        continue;
    }
    char *copy = (char *)malloc(sizeof(char)*(size+1));
    if (copy == NULL) {
        return NULL;
    }
    for (i = 0;i <= size;i++) {
        copy[i] = param_1[i];
        
    }
    return copy;
}