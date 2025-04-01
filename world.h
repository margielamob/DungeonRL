// world.h
#ifndef WORLD_H
#define WORLD_H

#define MAX_ROOMS 10
#define MAX_EXITS 4

typedef enum {
    NORTH,
    SOUTH,
    EAST,
    WEST
} Direction;

typedef struct {
    int id;
    const char *name;
    const char *description;
    int exits[MAX_EXITS]; // -1 if no exit
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int current_room_id;
    int room_count;
} World;

void init_world(World *world);
void describe_current_room(const World *world);
int move_player(World *world, Direction direction);

#endif // WORLD_H