#include <iostream>
#include <cstdlib>
#include <math.h>
#include <math.h>
using namespace std;
#include <cblas.h>

#define PI 3.1415926

//The function to print the matrix, M is the row, N is the column;
void printMatrix(const double *A, const int &M, const int &N){
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

int main()
{
	//initialization
	double h = 0.001;
	int rowNumF = 1001;
	
	double *f = new double[rowNumF];
	double *x = new double[rowNumF];
	double xVal = 0;
	for (int i = 0; i < rowNumF;i++){
		x[i] = xVal;
		f[i] = sin(xVal * PI);
		xVal = xVal + h;
	}
	
	double denom = pow(h,2);
	//generate the matrix for D
	int M = rowNumF;
	int N = rowNumF;
	double *D = new double[N*M];
	int j = 0;
	for (int i = 0;i < N;i++){
		D[(j + 0) * M + i] = 2.0/denom;
		D[(j + 1) * M + i] = -5.0/denom;
		D[(j + 2) * M + i] = 4.0/denom;
		D[(j + 3) * M + i] = -1.0/denom;
		j = j + 1;
		if (j == (N - 3)){
			break;
		}
	}
	
	D[(N-3 + 0) * M + (M-3)] = 2.0/denom;
	D[(N-3 + 1) * M + (M-3)] = -5.0/denom;
	D[(N-3 + 2) * M + (M-3)] = 4.0/denom;

	D[(N-2 + 0) * M + (M-2)] = 2.0/denom;
	D[(N-2 + 1) * M + (M-2)] = -5.0/denom;
	
	D[(N-1 + 0) * M + (M-1)] = 2.0/denom;
	
	double *b = new double[M];
	double L = 1.0;

	
	b[M - 3] = (-sin((L + h)*PI))/denom;
	b[M - 2] = (4*sin((L + h)*PI) - sin((L + 2*h)*PI))/denom;
	b[M - 1] = (-5*sin((L + h)*PI) + 4*sin((L + 2*h)*PI) - sin((L + 3*h)*PI))/denom;
	
	double *g = new double[M];
	
	cblas_dgemv(CblasColMajor, CblasNoTrans,M,N,1.0,D,M,f,1,1.0,b,1);
	printVector(rowNumF, b);
	
	
	double *fExact = new double[rowNumF];
	for (int i = 0;i<rowNumF;i++){
		fExact[i] = - pow(PI,2)*sin(x[i]*PI);
	}
	
	printVector(rowNumF, fExact);
	//printMatrix(D,M,N);
	
	cblas_daxpy(rowNumF,-1.0,b,1,fExact,1);
	double norm = cblas_dnrm2(rowNumF, fExact,1);
	
	cout << "The norm is :" << endl;
	cout << norm << endl;
}
