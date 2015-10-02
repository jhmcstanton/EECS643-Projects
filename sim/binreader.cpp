#include<iostream>
#include<stdio.h>
#include<time.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdint.h>
#include "cache.cpp"

using namespace std;

#define Address uint32_t
#define Line uint32_t
#define Tag  uint32_t
#define Valid bool
#define L1CCs 4; // super arbitrary
#define MMCCs 100;
  

int main(int argc, char* argv[]) {
  int32_t address, num_hits = 0, total_accesses = 0, totalCCs = 0;  

  Cache cache2way(2);
  Line line = 0;
  Tag  tag  = 0;
  if(argc <= 1){
    printf("Provide a file name.\n");
    return 1;
  }

  FILE *bin_file = fopen(argv[1], "rb");
  while(fread(&address, sizeof(int32_t), 1, bin_file)){
    line = (address >> 6) & 0x1ff; // 9 bits of 1s 
    tag = (address >> 15) & 0xffff; // 9 for line + 6 for block
    total_accesses++;
    if(cache2way.access(line, tag)){
      totalCCs += L1CCs;
      num_hits++;      
      //      printf("Line: %d, Tag: %d, Address: %x, HIT!\n", line, tag, address);
    } else {
      totalCCs += MMCCs;
      cache2way.push(line, tag);
      printf("WHIFF\n");
    }
  }
  printf("Number of Hits: %d, Total Accesses: %d, Hit Rate: %F, total CC %d\n",
	 num_hits, total_accesses, ((double)num_hits) / ((double)total_accesses), totalCCs);
  fclose(bin_file);
  return 0;
}
