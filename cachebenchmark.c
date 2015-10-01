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

int32_t Data[NbrPlanes][NbrRows][NbrCols];

int main(int argc, const char * argv[]) {

  srand(time(NULL));  
  int32_t I, J, K = 0;
  int32_t L = NbrIterations;
  int32_t *X = 0;
  long inner_time_sum = 0;

  time_t StartTime, EndTime, InnerStartTime, InnerEndTime;

  printf(">>CacheBenchmark: Starting \n");
  
  time(&StartTime);
  printf(">>CacheBenchmark: Start: Time = %12ld    %s\n", StartTime, ctime(&StartTime));
  
  printf(">>Size of int: %ld; Size of long int: %ld; Size of time_t: %ld\n", sizeof( int ), sizeof( long int), sizeof( time_t));

  FILE *trace_file = fopen("memtrace.bin", "wb");
  FILE *rand_file  = fopen("rand_memtrace.bin", "wb");
  int32_t *base_addr = &Data[0][0][0];
  for(I = 0; I < NbrPlanes; I++){
    for(J = 0; J < NbrRows; J++){
      for(K = 0; K < NbrCols; K++) {       
	X = ((uint64_t)&Data[I][J][K]) - ((uint64_t)base_addr);	 
	//Data[I][J][K] = 0;
        fwrite(&X, sizeof(int32_t), 1, trace_file);
        X = ((uint64_t)&Data[rand() % NbrPlanes][rand() % NbrRows][rand() % NbrCols]) - ((uint64_t)base_addr);
        fwrite(&X, sizeof(int32_t), 1, rand_file);
      }
    }
  }
  fclose(trace_file);
  fclose(rand_file);
  /*
  sleep( 1 );
  time (&StartTime);
  for( L=0; L < NbrIterations; L++){
    time( &InnerStartTime);
    for( I = 0; I < NbrPlanes; I++){
      for( J = 0; J < NbrRows; J++){
	for( K = 0; K < NbrCols; K++){
	  X = Data[I][J][K];
	}
      }
    }
    time( &InnerEndTime );
    inner_time_sum += InnerEndTime - InnerStartTime;
  }

  time( &EndTime );
  
  printf( ">>>>X: %d\n", X);
  printf(">>CacheBenchmark: Start %12ld; End: %12ld; Delta: %12ld; InnerLoopAvg: %12ld\n", 
	 StartTime, EndTime, (EndTime - StartTime), inner_time_sum / NbrIterations);

  inner_time_sum = 0;

  sleep( 1 );

  time( &StartTime );
  for(L = 0; L < NbrIterations; L++){
    time( &InnerStartTime);
    for( K = 0; K < NbrCols; K++){
      for( J = 0; J < NbrRows; J++) {
	for ( I = 0;  I < NbrPlanes; I++) {
	  X = Data[I][J][K];
	}
      }
    }
    time( &InnerEndTime );
    inner_time_sum += InnerEndTime - InnerStartTime;
  }

  time ( &EndTime);

  printf(">>>>X: %d\n", X);
  printf(">>CacheBenchmark: Start: %12ld; End: %12ld; Delta: %12ld; InnerLoopAvg: %12ld\n", 
	 StartTime, EndTime, (EndTime - StartTime), inner_time_sum / NbrIterations); */
  return 1;
}
