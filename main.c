// main.c
#include <stdio.h>
#include <string.h>
#include "world.h"

char get_input() {
    char buffer[10];
    printf("\n> Enter a direction (n/e/s/w or q to quit): ");
    fgets(buffer, sizeof(buffer), stdin);
    return buffer[0];
}

Direction char_to_direction(char c) {
    switch (c) {
        case 'n': return NORTH;
        case 's': return SOUTH;
        case 'e': return EAST;
        case 'w': return WEST;
        default: return -1;
    }
}

int main(){
    World world;
    init_world(&world);
    describe_current_room(&world);

    while(1){
        char input = get_input();
        if (input == 'q') {
            printf("\nExiting the dungeon. Farewell, adventurer!\n");
            break;
        }

        Direction direction = char_to_direction(input);
        if (direction < 0 || direction > WEST) {
            printf("Invalid direction. Try n, e, s, or w.\n");
            continue;
        }

        move_player(&world, direction);
    }
    return 0;
}