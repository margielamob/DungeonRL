// world.c
#include <stdio.h>
#include "world.h"

void init_world(World* world) {
    world -> room_count = 3;

    world -> rooms[0] = (Room){
        .id = 0,
        .name = "Entrance",
        .description = "You are standing at the entrance of a dark cave.",
        .exits = {1, -1, -1, -1}
    };

    world -> rooms[1] = (Room){
        .id = 1,
        .name = "Hallway",
        .description = "A damp hallway stretches before you.",
        .exits = {-1, -1, 2, 0}
    };

    world -> rooms[2] = (Room){
        .id = 2,
        .name = "Chamber",
        .description = "A wide chamber filled with bones.",
        .exits = {-1, -1, -1, 1}
    };

    world -> current_room_id = 0;
}

void describe_current_room(const World* world) {
    const Room* room = &world->rooms[world->current_room_id];
    printf("\n== %s ==\n%s\n", room->name, room->description);

    const char* directions[] = {"North", "South", "East", "West"};
    for (int i = 0; i < MAX_EXITS; i++) {
        if (room->exits[i] != -1) {
            printf("There is an exit to the %s.\n", directions[i]);
        }
    }
}

int move_player(World* world, Direction direction) {
    Room* room = &world->rooms[world->current_room_id];
    int next_room_id = room->exits[direction];

    if (next_room_id == -1) {
        printf("You can't go that way!\n");
        return 0;
    }

    world->current_room_id = next_room_id;
    describe_current_room(world); 
    return 1;
}