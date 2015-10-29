#include "Memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void memory(mem_addr addr, int dir, MemWidth *bus){

	//If direction is from memory to cache, write to destination address.
	if (dir == 1){
	        *bus = Memory[addr];
	}
	//If direction is from cache to memory, Memory[address] retrieves data from rd_data.
	else if (dir == 0){
		Memory[addr] = *bus;
	}

}
