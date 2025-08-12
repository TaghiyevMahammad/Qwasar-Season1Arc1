#include <ctype.h>
#include <stdio.h>
int my_isupper (char param_1) {
    if (isupper(param_1)) {
        return 1;
    }
    else {
        return 0;
    }
}
