#include "regfile.h"
#include <stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
  srand(time(NULL));
  // Testing the RegFile
  uint32_t *s_data = (uint32_t *) malloc(sizeof(uint32_t)), *t_data = (uint32_t *) malloc(sizeof(uint32_t)); 
  uint32_t i, write_data; 

  reg_addr rs, rt, rd;
  bool write_en;
  // Fill it up
  for(i = 0; i < REGFILESIZE; i++){
    printf("i: %u\n", i);
    RegFile(0, 0, (reg_addr) i, rand(), 1, s_data, t_data);
  }
  // Do some random testing (reads and writes)
  for(i = 0; i < (REGFILESIZE * 4); i++){
    rs = rand();
    rt = rand();
    rd = rand();
    write_en = rand() % 2;
    write_data = rand();
    printf("RegFile(%u, %u, %u, %u, %u, s_data, t_data) => ", rs, rt, rd, write_data, write_en);
    RegFile(rs, rt, rd, write_data, write_en, s_data, t_data);
    printf("s_read: %d, t_read: %d\n", *s_data, *t_data);
  }
  
  free(s_data);
  free(t_data);
  return 0;
}

/*
  Register File that takes 1 cycle to run. Contains @REGFILESIZE registers.
  s_data and t_data are the pointers to return the results to. 

  UNTESTED, but this should not require boundary checks because
  a) reg_addr is unsigned 
  b) REGFILESIZE is defined in terms of the *size* of reg_addr 
 */
void RegFile(reg_addr rs, reg_addr rt, reg_addr rd, uint32_t wrt_data, bool wrt_enb, uint32_t *s_data, uint32_t *t_data) {
  // First half of clock cycle data from previous cycle is written
  if(wrt_enb){ // Data can *only* be read when the controller says so
    reg_file[rd] = wrt_data;
  }
  // Second half data is retrieved. Data is *always* read
  *s_data = reg_file[rs];
  *t_data = reg_file[rt];
  return;
}
