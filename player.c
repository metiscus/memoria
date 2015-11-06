#include "player.h"
#include <assert.h>
#include <stdlib.h>

player_t* player_new()
{
    player_t *ptr = (player_t*)calloc(1, sizeof(player_t));
    assert(ptr);
    return ptr;
}

void player_delete(player_t* ptr)
{
    if(ptr)
    {
        free(ptr->inventory);
    }
    free(ptr);
}

void player_save(player_t* ptr, char* filename)
{
    assert(false);
}

void player_load(char* filename, player_t* ptr)
{
    assert(false);
}

void player_inv_add(player_t* ptr, uint32_t id)
{
    if(ptr)
    {
        if(ptr->inventory)
        {
            int i;
            for(i=0; i<ptr->inventory_count; ++i)
            {
                if(id == ptr->inventory[i].id && ptr->inventory[i].is_stackable)
                {
                    ++ptr->inventory[i].qty;
                    return;
                }
            }
        }
        // append to inventory
        object_ref_t *newInvPtr = realloc(ptr->inventory, (ptr->inventory_count + 1) * sizeof(object_ref_t));
        if(newInvPtr)
        {
            ptr->inventory = newInvPtr;
            ptr->inventory[ptr->inventory_count].id  = id;
            ptr->inventory[ptr->inventory_count].qty = 1;
        }
        else
        {
            assert(false);
        }
    }
}

void player_inv_remove(player_t* ptr, uint32_t id)
{
    assert(false);
}

uint32_t player_inv_count(player_t* ptr, uint32_t id)
{
    return 0;
}

void player_move(player_t* ptr, uint32_t x, uint32_t y)
{
    assert(ptr);
    ptr->x += x;
    ptr->y += y;
}
