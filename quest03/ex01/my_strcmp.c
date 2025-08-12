#include <stdio.h>
int my_strcmp(char* param_1, char* param_2) {
    if (param_1[0] > param_2[0]) {
        return 1;
    }
    if (param_1[0] < param_2[0]) {
        return -1;
    }
    else {
        return 0;
    }
}