#include "regfile.h"


int main(){

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
  if(wrt_enb){
    // First half of clock cycle data from previous cycle is written
    reg_file[rd] = wrt_data;
    // Second half data is retrieved.
    *s_data = reg_file[rs];
    *t_data = reg_file[rt];
  }
  return;
}
