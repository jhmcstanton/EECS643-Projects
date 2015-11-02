#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include<stdint.h>
#include<commontypes.h>
#include<stdio.h>
#include<stdlib.h>

struct Instructions {
  MemWidth *instructions;
  uint16_t PC; 
  uint16_t instr_size;
  uint16_t instr_used;
} instructions; // Normally we should let main setup all the simulation components, but this should be fine. (Just like with the memory)

void load_program(FILE *file);

MemWidth fetch_instruction();

void clean_instructions();

#endif
