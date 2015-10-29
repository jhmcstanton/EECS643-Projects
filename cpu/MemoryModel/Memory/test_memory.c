#include "Memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	//To ensure random number is generated everytime program is executed.
	srand(time(NULL));

	uint32_t *rd_data = (uint32_t *) malloc(sizeof(uint32_t));
	uint32_t i, write_data;

	mem_addr addr;
  	
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
