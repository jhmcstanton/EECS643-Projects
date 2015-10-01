#include<iostream>
#include<stdio.h>
#include<time.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char* argv[]) {

  int32_t address;

  if(argc <= 1){
    printf("Provide a file name.\n");
    return 1;
  }
  FILE *bin_file = fopen(argv[1], "rb");
  
  while(fread(&address, sizeof(int32_t), 1, bin_file)){
      printf("%x\n", address);
  }
  return 0;
}
