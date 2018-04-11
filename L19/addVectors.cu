#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

#include "cuda.h"

//device funcion
__global__ void kernalAddVectors(double *a, double *b, double*c) {
  
  int threadid = threadIdx.x; // thread number
  int blockid = blockIdx.x; // block number
  int Nblock = blockDim.x; //number of threads in a block
  
  int id = threadid + blockid*Nblock;

  if (id<N) {
    c[id] = a[id] + b[id];
  }
}

int main(int argc, char **argv) {

  // get vector size from command line argument
  int N = atoi(argv[1]);
  
  double seed = clock();
  srand48(seed);

 double *h_a, *h_b, *h_c; //host vectors

  //alocate storage
  h_a = (double *) malloc(N*sizeof(double));
  h_b = (double *) malloc(N*sizeof(double));
  h_c = (double *) malloc(N*sizeof(double));

  //populate a and b
  for(int n=0; n<N; n++) {
    h_a[n] = drand48();
    h_b[n] = drand48();
  }

  double hostStart = clock();

  // c=a+b
  for(int n=0;n<N:n++) {
    h_c[n] = h_a[n] + h_b[n];
  }

  double hostEnd = clock();
  double hostTime = (hostEnd - hostStart)/(double) CLOCKS_PER_SEC;

  printf("The host took %g seconds to add a and b \n", hostTime);

  //Device arrays
  double *d_a, *d_b, *d_c;

  //allocate memory on the Device with cudaMalloc
  cudaMalloc(&d_a, N*sizeof(double));
  cudaMalloc(&d_b, N*sizeof(double));
  cudaMalloc(&d_c, N*sizeof(double));

  //copy data from the host to the device
  cudaMemcpy(d_a, h_a, N*sizeof(double), cuaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, N*sizeof(double), cuaMemcpyHostToDevice);
  
  //at his point the data is allocated and populated on the device

  int Nthreads = atoi(argv[2]); //get the num of threads per block
  int Nblocks = (N+Nthreads-1)/Nthreads;

  double deviceStart = clock(); 

  kernalAddVectors <<< , >>>(N, d_a, d_b, d_c);

  double deviceEnd = clock(); 
  double deivceTime = (deviceEnd-deviceStart)/(double) CLOCKS_PER_SEC;

  printf("The device took %f seconds to add a and b \n", deviceTime);
  printf("The device was %d times faster \n", hostTime/deviceTime);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);


  free(h_a);
  free(h_b);
  free(h_c);

}
