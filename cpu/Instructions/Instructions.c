#include<Instructions.h>


#define MIN_INSTR_SIZE 100 //arbitrarily chosen
#define INSTR_INCREMENT MIN_INSTR_SIZE 

/* Loads a program into memory from HDD -> note, this simulation, so far, has register files, main memory and 
   instruction memory (seen here). */
void load_program(FILE *file){
  uint16_t i;
  if(instructions.instr_size == 0){ // setting up the struct (assumes that Instructions is allocated statically !)
    instructions.instr_size = MIN_INSTR_SIZE;
    instructions.instr_used = 0;
    instructions.PC = 0;
    instructions.instructions = (MemWidth*) malloc(sizeof(MemWidth) * instructions.instr_size);
  } 
  // Read in the program from the binary file 
  MemWidth *buffer = (MemWidth*) malloc(sizeof(MemWidth));
  while(fread(buffer, sizeof(MemWidth), 1, file) == 1){
    // copy into new array if needed
    if(instructions.instr_size == instructions.instr_used){ 
      instructions.instr_size += INSTR_INCREMENT;
      MemWidth *temp_arr = (MemWidth*) malloc(sizeof(MemWidth) * instructions.instr_size);
      
      for(i = 0; i < instructions.instr_used; i++){
	temp_arr[i] = instructions.instructions[i];
      }
      free(instructions.instructions);
      instructions.instructions = temp_arr;
    }

    instructions.instructions[instructions.instr_used] = *buffer;
    instructions.instr_used++;
  } 
  free(buffer);
}

/* Returns a single instruction, also increments the counter. 
   Exits the program if the next instruction is outside the program or the array is not initialized */ 
MemWidth fetch_instruction(){
  if(instructions.instructions != NULL && instructions.instr_size > instructions.PC){
    uint16_t temp_PC = instructions.PC;
    instructions.PC++;
    return instructions.instructions[temp_PC];
  } else {
    if (instructions.instructions == NULL){
      printf("INSTRUCTION ARRAY NOT INITIALIZED\n");
      exit(1);
    } else {
      printf("PC > instruction array size!\n");
      exit(2);
    }
  }   
}

void clean_instructions(){
  free(instructions.instructions);
}
