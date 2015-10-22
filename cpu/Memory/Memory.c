#include "Memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	//To ensure random number is generated everytime program is executed.
	srand(time(NULL));

	uint32_t *rd_data = (uint32_t *) malloc(sizeof(uint32_t));
	uint32_t i, write_data;

	reg_addr addr;
  	
  	// Do some random testing (reads and writes)
  	for(i = 0; i < 10; i++){
    	addr = rand();
    	
    	const int dir = rand() % 2;

    	write_data = rand();

    	if (dir == 0){
    		*rd_data = rand();
    	}

    	printf("Memory(%u, %u, %u, rd_data) => ", addr, dir, write_data);
    	memory(addr, dir, write_data, rd_data);

  	}
  
  	free(rd_data);
  	return 0;
}

void memory(reg_addr addr, int dir, uint32_t write_data, uint32_t *rd_data){

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