#include <stdio.h>

void print_position(int number) {
    int step_size = 1;
    int strike = 0;
    int current_position_x = 0;
    int current_position_y = 0;
    int side = 3;
    for(int i=0;i<number;i++) {
        switch (side) {
            case 1: current_position_x -= step_size; break;
            case 2: current_position_y -= step_size; break;
            case 3: current_position_x += step_size; break;
            case 4: current_position_y += step_size; break;
            default: printf("Impossible"); return;
        }

        side++;
        if(side == 5) {
            side = 1;
        }

        strike++;
        if(strike == 2) {
            step_size++;
            strike = 0;
        }
    }
    printf("%d %d", current_position_x, current_position_y);
}


int main() {
    int number;
    scanf("%d", &number);
    print_position(number - 1);
}
