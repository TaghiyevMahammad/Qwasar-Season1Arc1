#include <ctype.h>
#include <stdio.h>
int my_isspace (char param_1) {
    if (isspace(param_1)) {
        return 1;
    }
    else {
        return 0;
    }
}
