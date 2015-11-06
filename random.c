#include "random.h"
#include <assert.h>
#include <mtwist.h>
#include <stdlib.h>

static mtwist *g_mtwist = 0;

void random_init(uint32_t seed)
{
    free(g_mtwist);
    g_mtwist = 0;
    g_mtwist = mtwist_new();
    assert(g_mtwist);
    mtwist_init(g_mtwist, seed);
}

void random_reseed(uint32_t seed)
{
    assert(g_mtwist);
    mtwist_init(g_mtwist, seed);
}

void random_reseed_time(void)
{
    assert(g_mtwist);
    mtwist_init(g_mtwist, mtwist_seed_from_system(g_mtwist));
}

uint32_t random_uint(uint32_t max)
{
    assert(g_mtwist);
    return mtwist_u32rand(g_mtwist) % max + 1;
}

uint32_t random_uint_range(uint32_t min, uint32_t max)
{
    assert(g_mtwist);
    assert(max > min);
    uint32_t range = max - min;
    return mtwist_u32rand(g_mtwist) % range + min;
}
