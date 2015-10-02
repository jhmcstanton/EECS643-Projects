//#include<iostream>
#include<stdio.h>
#include<time.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdint.h>


#define NbrPlanes 64
#define NbrRows 1024
#define NbrCols 1024
#define NbrIterations 1
#define SizeOfArray (NbrPlanes * NbrRows * NbrCols)

int32_t Data[NbrPlanes][NbrRows][NbrCols];

int main(int argc, const char * argv[]) {

  srand(time(NULL));  
  int32_t I, J, K = 0;
  int32_t L = NbrIterations;
  int32_t *X = 0;
  int32_t walk_size = 200;

  long inner_time_sum = 0;

  time_t StartTime, EndTime, InnerStartTime, InnerEndTime;

  printf(">>CacheBenchmark: Starting \n");
  
  time(&StartTime);
  printf(">>CacheBenchmark: Start: Time = %12ld    %s\n", StartTime, ctime(&StartTime));
  
  printf(">>Size of int: %ld; Size of long int: %ld; Size of time_t: %ld\n", sizeof( int ), sizeof( long int), sizeof( time_t));

  FILE *trace_file = fopen("memcols.bin", "wb");
  FILE *rand_file  = fopen("rand_memtrace.bin", "wb");
  int32_t *base_addr = &Data[0][0][0];
  // Used for the random walk trace. This is used to find an address inside the array that is a multiple of 4
  uint32_t prev_addr = rand() % (SizeOfArray / 4) * 4; 
  for(I = 0; I < NbrPlanes; I++){
    for(J = 0; J < NbrRows; J++){
      for(K = 0; K < NbrCols; K++) {       
	X = ((uint32_t)&Data[I][J][K]) - ((uint32_t)base_addr);	 
        fwrite(&X, sizeof(int32_t), 1, trace_file);
        // Making the random walk trace
        if(rand() % 2 == 0){  // Moving forward in the array
	  X = prev_addr + (rand() % walk_size - 50) * 4; 
	}
	else { // Moving backward
	  X = prev_addr - (rand() % walk_size - 50) * 4; 
	}
	// If the address picked is out of the bounds of the array then just pick a new, random one inside the array
        if (X < 0 || X > SizeOfArray){
	  X = rand() % (SizeOfArray / 4) * 4;
	}
        fwrite(&X, sizeof(int32_t), 1, rand_file);        
        prev_addr = (uint32_t)X;
      }
    }
  }
  fclose(trace_file);
  fclose(rand_file);  

  time( &EndTime );
  
  printf(">>CacheBenchmark: Start %12ld; End: %12ld; Delta: %12ld; InnerLoopAvg: %12ld\n", 
	 StartTime, EndTime, (EndTime - StartTime), inner_time_sum / NbrIterations);

  inner_time_sum = 0;

  sleep( 1 );

  time( &StartTime );
  trace_file = fopen("memplanes.bin", "wb");
  for(L = 0; L < NbrIterations; L++){
    time( &InnerStartTime);
    for( K = 0; K < NbrCols; K++){
      for( J = 0; J < NbrRows; J++) {
	for ( I = 0;  I < NbrPlanes; I++) {
	X = ((uint32_t)&Data[I][J][K]) - ((uint32_t)base_addr);	 
        fwrite(&X, sizeof(int32_t), 1, trace_file);
	}
      }
    }
  }
  fclose(trace_file);

  time ( &EndTime);

  printf(">>>>X: %d\n", *X);
  printf(">>CacheBenchmark: Start: %12ld; End: %12ld; Delta: %12ld; InnerLoopAvg: %12ld\n", 
	 StartTime, EndTime, (EndTime - StartTime), inner_time_sum / NbrIterations); 
  return 1;
}
