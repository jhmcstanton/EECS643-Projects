#include "regfile.h"
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

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
