#include <iostream>
#include <sstream>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[])
{
	int rank = 0;
	int size = 0;
	int num = 0;
	
	int err = MPI_Init(&argc, &argv);
	if (err != MPI_SUCCESS){
		cout <<"Fail"<<endl;
		return -1;
	}
	
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if (rank == 0){
		string input;
		cout << "enter a number: " << endl;
		cin >> input;
		stringstream S(input);
		S >> num;
	}else{
		MPI_Recv(&num, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "Process " << rank << "Received " << num << "from rank "<< rank-1 << endl;
	}
	
	MPI_Ssend(&num, 1, MPI_INT, (rank + 1)%size, 0, MPI_COMM_WORLD);
	
	if (rank == 0){
		MPI_Recv(&num, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		cout << "Process " << rank << "Received " << num << "from rank "<< size-1 << endl;
	}
	
	MPI_Finalize();
	return 0;
}
