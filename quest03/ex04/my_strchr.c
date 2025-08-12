#include <stdio.h>
#include <stdlib.h>
char* my_strchr(char* param_1, char param_2) {
    char* param_3 = malloc(100);
    int i;
    for (i=0;param_1[i]!='\0';i++) {
        if (param_1[i]==param_2) {
            break;
        }
    }
    if (param_1[i] == '\0') {
        free(param_3); 
        return NULL;   
    }
    int n = 0;

    while (param_1[i]!='\0') {
        param_3[n] = param_1[i];
        n++;
        i++;
    }
    param_3[n] = '\0';
    return param_3;
}