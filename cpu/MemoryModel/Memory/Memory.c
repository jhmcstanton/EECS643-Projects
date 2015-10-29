#include "Memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void memory(mem_addr addr, int dir, uint32_t write_data, uint32_t *rd_data){

	//If direction is from memory to cache, write to destination address.
	if (dir == 1){
		*rd_data = write_data;
		printf("*rd_data = %u\n", write_data);
	}
	//If direction is from cache to memory, Memory[address] retrieves data from rd_data.
	else if (dir == 0){
		Memory[addr] = *rd_data;
		printf("Memory[%u] = %u\n", addr, *rd_data);
	}

}
