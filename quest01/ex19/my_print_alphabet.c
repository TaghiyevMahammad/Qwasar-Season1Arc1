#include <stdio.h>
#include <unistd.h>
void my_print_alphabet () {
    char c;
    for(c = 'a';c<='z';c++) {
        write(1, &c, 1);
    }
    write(1,"\n",1);
}

