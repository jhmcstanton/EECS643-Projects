#include<Instructions.h>
#include<time.h>

#define NUM_OPS 500

int main(){
  // Loading arbitrary date into a file
  srand(time(NULL));
  FILE *data_file = fopen("junk_data.bin", "ab+");
  MemWidth *buffer = (MemWidth*) malloc(sizeof(MemWidth));
  MemWidth instruction;
  uint16_t i;

  for(i = 0; i < NUM_OPS; i++){
    *buffer = rand();
    printf("Buffer contents: %u\n", *buffer);
    fwrite(buffer, sizeof(MemWidth), 1, data_file);
  }
  free(buffer);
  
  // Load the program 
  rewind(data_file);
  load_program(data_file);
  fclose(data_file);

  // fetch all the instructions
  for(i = 0; i < NUM_OPS; i++){
    instruction = fetch_instruction();
    printf("Instruction: %u\n", instruction);
  }
  clean_instructions();
  return 0;
}
