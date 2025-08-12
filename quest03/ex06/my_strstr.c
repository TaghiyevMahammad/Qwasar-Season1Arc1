#include <stdio.h>
#include <stdlib.h>

char* my_strstr(char* haystack, char* needle) {
    int i, j, found = 0;

    for (i = 0; haystack[i] != '\0'; i++) {
        for (j = 0; needle[j] != '\0'; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (needle[j] == '\0') {
            found = 1;
            break;
        }
    }

    if (found == 0) {
        return NULL;
    }
    char* param_3 = malloc(100);
    int n = 0;
    while (haystack[i] != '\0') {
        param_3[n++] = haystack[i++];
    }
    param_3[n] = '\0';

    return param_3;
}
