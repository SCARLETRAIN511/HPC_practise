#include <iostream>
#include <cblas.h>
#include <mpi.h>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int rank = 0;
	int size = 0;
	
	int err = MPI_Init(&argc, &argv);
	if (err != MPI_SUCCESS){
		cout << "Failed" << endl;
		return -1;
	}
	
	//get the rank of the process
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if (1024 % size){
		if (rank == 0){
			cout << "Error"<<endl;
		}
		MPI_Finalize();
		return 0;
	}
	
	n = 1024/size;
	double *x = new double[n];
	double *y = new double[n];
	srand(time(0)+rank);
	for (int i = 0;i < n;i++){
		x[i] = (double)rand()/RAND_MAX;
		y[i] = (double)rand()/RAND_MAX;
	}
	
	double dot = cblas_ddot(n,x,1,y,1);
	double nrmx = cblas_ddot(n,x,1,x,1);
	double nrmy = cblas_ddot(n,y,1,y,1);
	
	cout << "The rank is :" << rank << endl;
	cout << "dot product:" << dot << endl;;
	cout << "Norm x:" << sqrt(nrmx)<< endl;
	cout << "Norm y" << sqrt(nrmy)<< endl;
	cout << endl;
		
	double dot_r;
	double nrmx_r;
	double nrmy_r;
	
	MPI_Reduce(&dot, &dot_r, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&nrmx, &nrmx_r, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&nrmy, &nrmy_r, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	
	if (rank == 0){
		cout << "dot product:" << dot_r << endl;;
		cout << "Norm x:" << sqrt(nrmx_r)<< endl;
		cout << "Norm y" << sqrt(nrmy_r)<< endl;
	}
	
	MPI_Finalize();
	return 0;
}
