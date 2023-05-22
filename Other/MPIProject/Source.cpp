#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv)
{
	int rank, size, resultlen;
	char name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &resultlen);
	printf("Hello world from process %d of %d at %s\n", rank, size, name);
	MPI_Finalize();
	return 0;
}