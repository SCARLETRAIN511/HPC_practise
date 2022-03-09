#include <iostream>
using namespace std;
#include <sstream>
#include <mpi.h>


int main(int argc, char* argv[])
{
	int n = 0;
	int rank = 0;
	int err = MPI_Init(&argc, &argv);
	if (err != MPI_SUCCESS){
		cout << "Failed to initialize" << endl;
		return -1;
	}
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0){
		string input;
		cout << "Enter the integer: ";
		cin >> input;
		stringstream S(input);
		S >> n;
	}
	
	MPI_Bcast(&n,1,MPI_INT, 0, MPI_COMM_WORLD);
	cout << "Rank: " << rank << ", n = " << n << endl;
	MPI_Finalize();
	return 0;
	
}
