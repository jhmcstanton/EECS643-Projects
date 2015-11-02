#include<ALU.h>
#include<commontypes.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define NUM_R_FUNCS 100
#define NUM_ITYPE 3

uint32_t test_r_codes(FUNC *function, uint32_t size);

int main(){
  srand(time(NULL));
  uint32_t i, num_successes;
  // Make an array of random r-type funcs
  FUNC r_codes[NUM_R_FUNCS];
  for(i = 0; i < NUM_R_FUNCS; i++){
    r_codes[i] = rand() % (NUM_FUNCTIONS - NUM_ITYPE);
  }
  num_successes = test_r_codes(r_codes, NUM_R_FUNCS);
  printf("R-Type Tests: %u, Successes: %u\n", NUM_R_FUNCS, num_successes);
  return 0;
}

/* Tests each R-Type FUNC and returns the number of successful tests */
uint32_t test_r_codes(FUNC *functions, uint32_t size){
  uint32_t i, num_successes = 0;
  FUNC function;
  struct ALUResult result;
  MemWidth rs = 400, rt = 200; 

  for(i = 0; i < size; i++){
    function = functions[i];
    result =  ALU(R, function, rs, rt);
    switch(function){ 
    case ADDU : 
      if((rs + rt) == result.alu_result) 
	num_successes += 1; 
      else
	printf("Failure in ADDU func: rs = %u, rt = %u, alu_result = %u, test_result = %u\n", 
	       rs, rt, result.alu_result, rs + rt);
      break;
    case MULT : 
      if((rs * rt) == result.alu_result)
	num_successes += 1;
      else
	printf("Failure in MULT func: rs = %u, rt = %u, alu_result = %u, test_result = %u\n", 
	       rs, rt, result.alu_result, rs * rt);	
      break;
    case DIV  : 
      if((rs / rt) == result.alu_result)
	num_successes += 1;
      else
	printf("Failure in DIV func: rs = %u, rt = %u, alu_result = %u, test_result = %u\n", 
	       rs, rt, result.alu_result, rs / rt);	
      break;
    case AND  : 
      if((rs & rt)  == result.alu_result)
	num_successes += 1;
      else
	printf("Failure in AND func: rs = %u, rt = %u, alu_result = %u, test_result = %u\n", 
	       rs, rt, result.alu_result, rs & rt);
      break;
    case OR   : 
      if((rs | rt)  == result.alu_result)
	num_successes += 1;
      else
	printf("Failure in OR func: rs = %u, rt = %u, alu_result = %u, test_result = %u\n", 
	       rs, rt, result.alu_result, rs | rt);
      break;
    case NAND : 
      if(~(rs & rt) == result.alu_result)
	num_successes += 1;
      else
	printf("Failure in NAND func: rs = %u, rt = %u, alu_result = %u, test_result = %u\n", 
	       rs, rt, result.alu_result, ~(rs & rt));
      break;
    case NOR  : 
      if(~(rs | rt) == result.alu_result)
	num_successes += 1;
      else
	printf("Failure in NOR func: rs = %u, rt = %u, alu_result = %u, test_result = %u\n", 
	       rs, rt, result.alu_result, ~(rs | rt));
      break;
    default:
      printf("Found a weird Function: func: %u, alu_result = %u\n", function, result.alu_result);
    }
  }
  return num_successes; 
}
