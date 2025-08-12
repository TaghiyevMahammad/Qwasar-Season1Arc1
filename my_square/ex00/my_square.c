#include <stdio.h>
#include <stdlib.h>

void print_line(char start, char middle,char end, int length) {
    if (length == 1) {
        putchar(start);
    }
    else {
        putchar(start);
        for (int i = 0;i <length -2;i++) {
            putchar(middle);
        }
        putchar(end);
    }
    putchar('\n');

}
void my_square(int x, int y) {
    if (x <= 0 || y <= 0)
        return;

    if (y == 1) {
        print_line('o', '-', 'o', x);
    } else if (y == 2) {
        print_line('o', '-', 'o', x);
        print_line('o', '-', 'o', x);
    } else {
        print_line('o', '-', 'o', x);
        for (int i = 0; i < y - 2; i++) {
            print_line('|', ' ', '|', x);
        }
        print_line('o', '-', 'o', x);
    }
}
int main(int argc, char **argv) {
    if (argc == 3) {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        my_square(x, y);
    }
    return 0;
}