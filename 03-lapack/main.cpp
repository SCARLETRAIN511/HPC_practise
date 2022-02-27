#include <iostream>
#include <cstdlib>
using namespace std;

#define F77NAME(x) x##_
extern "C"{
	void F77NAME(dgesv)(const int& n, const int& nrhs, const double *A,
						const int& lda, int *ipiv, double *B,
						const int& ldb, int& info);
	void F77NAME(dgemv)(const char& trans, const int& m,
						const int& n, const double& alpha, 
						const double *A, const int& lda, 
						const double *x, const int& incx, 
						const double& beta, double *y, 
						const int& incy);
}

int main()
{
	const int n = 10;
	const int nrhs = 1;
	int info = 0;
	
	double* A = new double[n*n];
	double* x = new double[n];
	double* y = new double[n];
	int* ipiv = new int[n];
	
	for (int i = 0; i< n*n;i++){
		A[i] = (double)(rand())/RAND_MAX;
	}
	
	for (int i = 0;i < n;i++){
		x[i] = (double)(rand())/RAND_MAX;
	}
	
	F77NAME(dgemv)('N',n,n,1.0,A,n,x,1,0.0,y,1);
	
	F77NAME(dgesv)(n,nrhs,A,n,ipiv,y,n,info);
	
	for (int i = 0;i < n;i++){
		cout << x[i]<<","<<y[i] << endl;
	}
}
