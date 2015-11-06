#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <stdint.h>

#define NAME_LENGTH 100

typedef struct object
{
    uint32_t id;
    char name[NAME_LENGTH];
    uint32_t weight;
    uint32_t value;
    uint32_t type;
} object_t;

#endif // OBJECT_H_INCLUDED
