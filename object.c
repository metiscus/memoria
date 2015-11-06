#include "object.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static object_t *g_objects = 0;
static uint32_t g_objects_count = 0;

void object_load_file(char *filename)
{
    assert(false);
}

object_t* object_get(uint32_t id)
{
    return 0;
}

object_ref_t object_create_instance(uint32_t id)
{
    object_ref_t ref;
    int i;
    for(i=0; i<g_objects_count; ++i)
    {
        if(g_objects[i].id == id)
        {
            ref.id = id;
            ref.qty = 1;
            ref.is_stackable = g_objects[i].is_stackable;
            return ref;
        }
    }

    ref.id  = 0xbadf00d;
    ref.qty = 0;
    ref.is_stackable = false;
    return ref;
}
