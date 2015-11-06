#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>

#define NAME_LENGTH 100

typedef struct object
{
    uint32_t id;
    char name[NAME_LENGTH];
    uint32_t weight;
    uint32_t value;
    uint32_t type;
    bool is_stackable;
} object_t;

typedef struct object_ref
{
    uint32_t id;
    uint32_t qty;
    bool is_stackable;
} object_ref_t;

extern void         object_load_file(char *filename);
extern object_ref_t object_create_instance(uint32_t id);
extern object_t*    object_get(uint32_t id);

#endif // OBJECT_H_INCLUDED
