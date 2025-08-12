#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_spaceship(char* param_1) {
    int x = 0,y = 0;
    int direction = 0;
    
    int len = strlen(param_1);
    for(int i = 0;i < len;i++) {
        if(param_1[i] == 'R') {
            direction = (direction + 1) % 4;
        }
        else if (param_1[i] == 'L') {
            direction = (direction + 3) % 4;
        }
        else if (param_1[i] == 'A') {
            if (direction == 0) y -= 1;
            else if (direction == 1) x += 1;
            else if (direction == 2) y += 1;
            else if (direction == 3) x -= 1;
        }
    }
    const char* directions[] = {"up", "right", "down", "left"};

    char* result = malloc(100);
    snprintf(result, 100, "{x: %d, y: %d, direction: '%s'}", x, y, directions[direction]);

    return result;


}