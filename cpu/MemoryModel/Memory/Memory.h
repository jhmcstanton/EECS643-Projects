#ifndef MAINMEMORY_H
#define MAINMEMORY_H

#include <stdint.h>
#include "../memconfig.h"

#define mem_addr uint16_t // arbitrarily chosen

#define MemorySize (1 << (8 * sizeof(mem_addr)))

MemWidth Memory[MemorySize];

void memory(mem_addr addr, int dir, MemWidth *bus);

#endif 
