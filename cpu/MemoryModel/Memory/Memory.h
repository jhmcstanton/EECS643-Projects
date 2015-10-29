#ifndef MAINMEMORY_H
#define MAINMEMORY_H

#include <stdint.h>
#include "../memconfig.h"

#define mem_addr uint16_t
// 2^10 = 1024 entries = 1kB
#define MemorySize (1 << (8 * sizeof(mem_addr)))

MemWidth Memory[MemorySize];

void memory(mem_addr addr, int dir, uint32_t write_data, uint32_t *rd_data);

#endif 
