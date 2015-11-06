#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <stdint.h>

extern void random_init(uint32_t seed);
extern void random_reseed(uint32_t seed);
extern void random_reseed_time(void);

extern uint32_t random_uint(uint32_t max);
extern uint32_t random_uint_range(uint32_t min, uint32_t max);

#endif // RANDOM_H_INCLUDED
