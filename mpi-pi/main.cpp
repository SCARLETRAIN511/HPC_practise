#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <mpi.h>
using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int rank = 0;
	int size = 0;
	double pi_loc = 0.0;
	double pi = 0.0;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if (rank == 0){
		string input;
		cout << "Enter the number of intervals: ";
		cin >> input;
		n = stoi(input);
	}
	
	MPI_Bcast(&n,1,MPI_INT, 0, MPI_COMM_WORLD);
	
	double dx = 1.0/n;
	int r = n % size;
	int k = (n-r)/size;
	
	int start = 0;
	int end = 0;
	if (rank < (n%size)){
		k++;
		start = k * rank;
		end = k*(rank + 1);
	}else{
		start = (k+1)*r + k*(rank - r);
		end = (k+1)*r + k*(rank-r+1);
	}
	
	
	double x1 = 0.0;
	double x2 = 0.0;
	for (int i = start;i < end;i++){
		x1 = i*dx;
		x2 = (i+1)*dx;
		pi_loc += 0.5*(1.0/(1.0+x1*x1) + 1.0/(1.0+x2*x2))*dx;
	}
	pi_loc *= 4.0;
	
	cout << "Rank: "<<rank<<", chunks: "<< k << ", contributes: " << pi_loc << endl;
	
	MPI_Reduce(&pi_loc, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (rank == 0){
		cout << "Pi esitmate: " << setprecision(8) << pi << endl;
	}
	
	MPI_Finalize();
	return 0;
}
