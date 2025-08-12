#include <stdio.h>
char* reverse_string(char* param_1) {
    int i;
    int n = 0;
    for ( i = 0;param_1[i]!='\0';i++) {
        n = n+1;
    }
    n = n-1;
    for ( i = 0;i<n;i++,n--) {
       char temp = param_1[i];
       param_1[i] = param_1[n];
       param_1[n] = temp;
    }
    return param_1;
}