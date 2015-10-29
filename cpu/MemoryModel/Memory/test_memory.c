#include "Memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	//To ensure random number is generated everytime program is executed.
	srand(time(NULL));

	uint32_t *rd_data = (uint32_t *) malloc(sizeof(uint32_t));
	MemWidth i, write_data;

	mem_addr addr;
  	
	//fill up the memory first
	for(i = 0; i < MemorySize; i++){
	  write_data = i*3;
	  memory((mem_addr) i, 0, NULL, &write_data); 
	}
  	// Do some random testing (reads and writes)
  	for(i = 0; i < MemorySize*2; i++){
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
