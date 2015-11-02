#include "Memory.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	//To ensure random number is generated everytime program is executed.
	srand(time(NULL));

	uint32_t *rd_data = (uint32_t *) malloc(sizeof(uint32_t));
	MemWidth i, bus;

	mem_addr addr;
  	
	//fill up the memory first
	for(i = 0; i < MemorySize; i++){
	  bus = i*3;
	  memory((mem_addr) i, 0, &bus); 
	}
  	// Do some random testing (reads and writes)
  	for(i = 0; i < MemorySize*2; i++){
	  addr = rand();
	  
	  int dir = rand() % 2;
	 
	  if(dir == 0){
	    bus = rand();
	  }
	  printf("Memory(%u, %u, %u, bus) => ", addr, dir, bus);
	  
	  memory(addr, dir, &bus);
	
	  if(dir == 1){
	    printf("Read mode: *rd_data = %u\n", bus);
	  }
	  else{
	    printf("Write mode: Memory[%u] = %u\n", addr, bus); 
	  }

	}
	
	free(rd_data);
  	return 0;
}
