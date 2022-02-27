#include <iostream>
#include <cstdlib>
#include <cblas.h>
using namespace std;

void multiplyBLAS(int n, double *A, double *B, double *C){
	cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans,n,n,n,1.0,A,n,B,n,0.0,C,n);
}

void multiply(int n, double *A, double *B, double *C){
	for (int i = 0;i < n;i ++){
		for (int j = 0;j<n;j++){
			C[j*n+i] = 0.0;
			for (int k = 0;k < n;k++){
				C[j*n + i] += A[k*n+i] * B[j*n+k];
			}
		}
	}
}

void printMatrix(const int &M, const int &N, double *A){
	for (int i = 0;i<M;i++){
		for (int j = 0; j < N;j++){
			cout << A[j*M+i] << " ";
		}
		cout << endl;
	}
}

void ex1(){
	const int n = 100;
	double *x = new double[n];
	
	for (int i = 0; i < n;i++){
		x[i] = (double)(rand())/RAND_MAX;
	}
	
	//get the norm and the maximum
	double norm = cblas_dnrm2(n,x,1);
	
	double sum = cblas_dasum(n,x,1);
	
	int max = cblas_idamax(n,x,1);
	
	cout << norm << endl;
	cout << sum << endl;
	cout << max << endl;
}

void ex2(){
	const int n = 2;
	const int range = 5.0;
	double *A = new double[n*n];
	double *B = new double[n*n];
	
	double *c1 = new double[n*n];
	double *c2 = new double[n*n];
	for (int i = 0; i < n*n;i++){
		A[i] = (double) rand()/RAND_MAX * range;
		B[i] = (double) rand()/RAND_MAX * range;
	}
	
	multiplyBLAS(n,A,B,c1);
	multiply(n,A,B,c2);
	
	printMatrix(n,n,c1);
	printMatrix(n,n,c2);
	cblas_daxpy(n*n,-1.0, c2, 1, c1,1);
	double eps = cblas_dnrm2(n*n,c1,1);
	cout << eps << endl;
}

int main()
{
	ex2();

}
