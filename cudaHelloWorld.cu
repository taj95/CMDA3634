#include <stdio.h>
#include <stdlib.h>

#include "cuda.h"

// This is my deviece function
// __global__ means this function is visible to the host
__global__ void kernelHelloWorld() {
	printf("Hello World!\n");
}

int main(int argc, char** argv) {

	int Nblocks = 10; // number of blocks
	int Nthreads = 3; //number of threads per block

	// run the function "kernelHelloworld" on the device
	kernelHelloWorld <<< Nblocks, Nblocks >>> ();
}
