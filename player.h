#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "object.h"

typedef struct player
{
    char name [NAME_LENGTH];
    uint32_t gender;
    uint32_t race;
    uint32_t level;
    uint32_t exp;
    uint32_t hp;
    uint32_t hp_max;
    object_ref_t *inventory;
    uint32_t inventory_count;
    uint32_t x, y;
} player_t;

extern player_t* player_new();
extern void      player_delete(player_t* ptr);
extern void      player_save(player_t* ptr, char* filename);
extern void      player_load(char* filename, player_t* ptr);
extern void      player_inv_add(player_t* ptr, uint32_t id);
extern void      player_inv_remove(player_t* ptr, uint32_t id);
extern uint32_t  player_inv_count(player_t* ptr, uint32_t id);
extern void      player_move(player_t* ptr, uint32_t x, uint32_t y);

#endif // PLAYER_H_INCLUDED
