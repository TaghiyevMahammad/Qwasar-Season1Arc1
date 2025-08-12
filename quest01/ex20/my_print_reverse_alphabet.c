#include <stdio.h>
#include <unistd.h>
void my_print_reverse_alphabet () {
    char c;
    for (c = 'z';c>='a';c--) {
        write(1,&c,1);
    }
   write(1,"\n",1);

}