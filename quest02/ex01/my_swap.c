#include <stdio.h>
void my_swap (int *variable_a ,int *variable_b) {
    int c = *variable_a;
    *variable_a = *variable_b;
    *variable_b = c;
}