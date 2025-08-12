#include <stdio.h>
#include <unistd.h>
void my_putstr(char* param_1) {
    char *t ;
    for (t = param_1; *t != '\0'; t++) {
        write(1,t,1);
    }

}