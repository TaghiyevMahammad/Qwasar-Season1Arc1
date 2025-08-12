#include <stdio.h>
void detonation_in(int timer){
    printf("detonation in... %d seconds.\n", timer);
}
int main (){
    int timer = 10;

    while(timer > 0) {
        detonation_in(timer);
        timer--;
    }
    return 0;
}