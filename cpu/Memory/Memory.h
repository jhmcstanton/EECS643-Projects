#include <stdint.h>
#include "regfile.h"

// 2^10 = 1024 entries = 1kB
#define MemorySize 1 << 10

uint32_t Memory[MemorySize];

void memory(reg_addr addr, int dir, uint32_t write_data, uint32_t *rd_data);