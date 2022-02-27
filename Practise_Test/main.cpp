#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cblas.h>
using namespace std;

void printMatrix(int &M, int &N, double *A){
	for (int i = 0;i < M;i++){
		for (int j = 0;j < N;j++){
			cout<< A[j*M + i] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printVector(int n, double* f){
	for(int i = 0; i < n;i++){
		cout << f[i] << endl;
	}
	cout << endl;
}

void fillMatrix(double *A, int &N){
	
}

void fillVector(double *y, int&N){
	for (int i = 0;i<N;i++){
		y[i] = i;
	}
}

void fillMatrix(int &N, double *A){
	//fill the A matrix
	int j = 0;
	for (int i = 1;i < N;i++){
		A[(j + 0) * N + i] =0.5;
		A[(j + 1) * N + i] =1.0;
		A[(j + 2) * N + i] =0.5;
		j = j + 1;
		if (j == (N - 2)){
			break;
		}
	}
	
	A[(0 + 0) * N + 0] = 1.0 ;
	A[(0 + 1) * N + 0] = 0.5;
	
	A[(N-2 + 0) * N + (N-1)] = 0.5;
	A[(N-2 + 1) * N + (N-1)] = 1.0;
}

void fillMatrixBanded(int &N, double *A){
	const int ldh = 2;
	A[1] = 1.0;
	for (int i = 1;i<N;i++){
		A[i*ldh] = 0.5;
		A[i*ldh + 1] = 1.0;
	}
}

void printBanded(int &N, double *A){
	const int ldh = 2;
	for (int i = 0;i < ldh;i++){
		for (int j = 0;j < N; j++){
			cout << A[j*ldh + i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	
	int N = 20;
	double *y = new double[N];
	double *A = new double[N*N];
	double *b = new double[N];
	double alpha = 0.9;
	
	//initilize y
	fillVector(y,N);
	
	//fillMatrixBanded(N,A);
	fillMatrix(N,A);
	printMatrix(N,N,A);

	//cblas_dsbmv(CblasColMajor, CblasUpper, N, 1, 1.0, A, 1, y,1,0.0,b,1);
	cblas_dgemv(CblasColMajor, CblasNoTrans,N,N,1.0,A,N,y,1,0.0,b,1);// b = Ay
	
	//check the answer for b
	printVector(N,b);
	
	//data initialization for iteration
	double *x = new double[N];
	double *bIter = new double[N];
	cblas_dcopy(N,y,1,x,1);//x_0 = y_0;
	int iter = 0;

	while (iter < 1000){
		//generate the b for the iteration;
		cblas_dgemv(CblasColMajor, CblasNoTrans,N,N,1.0,A,N,y,1,0.0,bIter,1);// b = Ay
		cblas_dgemv(CblasColMajor, CblasNoTrans,N,N,-1.0,A,N,x,1,1.0,bIter,1);//b = b-Ax
		cblas_daxpy(N,alpha,bIter,1,x,1);// x = x + alpha(b-Ax);
		
		iter ++;
	}
	
	//calculate Ax
	double *ax = new double[N];
	cblas_dgemv(CblasColMajor, CblasNoTrans,N,N,1.0,A,N,x,1,0.0,ax,1);//ax = A*x;

	printVector(N,ax);
	//get the norm
	cblas_daxpy(N,-1.0,ax,1,b,1);//(b-ax)
	double norm = cblas_dnrm2(N,b,1);
	cout << norm << endl;
}
