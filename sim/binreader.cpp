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

  

int main(int argc, char* argv[]) {
  int32_t address;  

  Cache cache2way(2);
  Cache cache4way(4);
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
    // 2 way access
    if(cache2way.access(line, tag)){
    } else {
      cache2way.push(line, tag);
      //printf("2-Way WHIFF\n");
    }
    // 4 way access
    if(cache4way.access(line, tag)){
    } else {
      cache4way.push(line, tag);
      //printf("4-Way WHIFF\n");
    }
  }
  fclose(bin_file);
  cache2way.print_results();
  cache4way.print_results();
  return 0;
}
