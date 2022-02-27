#include <iostream>
#include <cstdlib>
#include <cblas.h>
using namespace std;

void printMatrix(const double *A, const int &M, const int &N){
	for (int i = 0;i < M;i++){
		for (int j = 0;j < N;j++){
			cout<< A[j*M + i] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{  
	//columns
	const int N = 8;
	//rows
	const int M = 6;
	
	double *A = new double[N*M];
	double *x = new double[N];
	double *y = new double[M];
				
	for (int i = 0;i < N;i++){
		for (int j = 0;j < M;j++){
			 A[i*M+j] = double(rand())/RAND_MAX;
		}
		x[i] = double(rand())/RAND_MAX;
	}
	
	cblas_dgemv(CblasColMajor, CblasNoTrans,M,N,1.0,A,M,x,1,0.0,y,1);
	printMatrix(A,M,N);
	printMatrix(x,N,1);
	printMatrix(y,M,1);
}                       
