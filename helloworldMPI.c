#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char** argv) {
	//Every MPI program must start with an intialize
	MPI_Init(&argc, &argv);

	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank==0) {
		int N=10;
		int destRank = 1;
		int tag = 1;
		
		MPI_Send(&N, 	//pointer to the data we're sending
			1, 	//number of entries to send
			MPI_INT, //data type of each entry
			destRank, //rank of destination
			tag, 	//tags the message with an indetifier
			MPI_COMM_WORLD); //flag to full MPI network
	}
	else if (rank == 1) {
		int N;
		int sourceRank = 0;
		int tag = 1;
		MPI_Status status;

		MPI_Recv(&N, 1, MPI_INT, sourceRank, tag, MPI_COMM_WORLD, &status);
		printf("Rank %d received a message from rank %d: value = %d\n", rank, sourceRank, N);
	}

	//if (rank<5) printf("Hello World from rank %d of %d!\n", rank, size);
	//else printf("Hello again from rank %d of %d!\n", rank, size);
	
	//All MPI programs must end with a finalize
	MPI_Finalize();
	return 0;
}
