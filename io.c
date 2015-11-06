#include "io.h"

#include <stdio.h>

#ifdef __linux__
#include <unistd.h>
#define PlatformLinux 1
#endif

void io_sleep(unsigned ms)
{
#if PlatformLinux
    usleep(ms);
#endif
}
