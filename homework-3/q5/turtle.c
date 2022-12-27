#include <stdbool.h>
#include <stdio.h>

#define MINIMUM_LENGTH_X (-3)
#define MAXIMUM_LENGTH_X 3
#define MINIMUM_LENGTH_Y (-3)
#define MAXIMUM_LENGTH_Y 3
#define FIRST_POSITION_X 0
#define FIRST_POSITION_Y 0
int position_x = FIRST_POSITION_X;
int position_y = FIRST_POSITION_Y;

int find_opposite(int move) {
    switch (move) {
        case 1: return 9;
        case 2: return 8;
        case 3: return 7;
        case 4: return 6;
        case 6: return 4;
        case 7: return 3;
        case 8: return 2;
        case 9: return 1;
        default: return -1;
    }
}

void change_position(int move) {
    switch (move) {
        case 1: position_x--; position_y++;  break;
        case 2: position_y++; break;
        case 3: position_x++; position_y++; break;
        case 4: position_x--; break;
        case 6: position_x++; break;
        case 7: position_x--; position_y--; break;
        case 8: position_y--; break;
        case 9: position_x++; position_y--; break;
        default: break;
    }
}

bool movement_not_allowed() {
    if(position_y < MINIMUM_LENGTH_Y || MAXIMUM_LENGTH_Y < position_y
       || position_x < MINIMUM_LENGTH_X || MAXIMUM_LENGTH_X < position_x) {
        return true;
    }
    return false;
}

bool is_position_of_turtle(int x, int y) {
    return x == position_x && y == position_y;
}

void print_screen() {
    for(int y=MINIMUM_LENGTH_Y;y<=MAXIMUM_LENGTH_Y;y++) {
        for(int x=MINIMUM_LENGTH_X;x<=MAXIMUM_LENGTH_X;x++) {
            if(is_position_of_turtle(x, y)) {
                printf("M");
            } else {
                printf("*");
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void play_game() {
    int move = -1;
    do {
        print_screen();
        scanf("%d", &move);
        change_position(move);
        if(movement_not_allowed()) {
            change_position(find_opposite(move));
        }
    } while(move!=0);
}

int main() {
    play_game();
}

