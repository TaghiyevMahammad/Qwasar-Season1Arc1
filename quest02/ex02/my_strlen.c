#include <stdio.h>
int my_strlen(char* s) {
    int result = 0;
    while(*s!='\0') {
        s++;
        result++;
    }
    return result;
}
