#include <iostream>
#include "cblas.h"
#include <cmath>
using namespace std;

void fillMatrix(int n ,double *M){
	for (int i = 0;i<n;i++){
		for (int j = 0;j<n;j++){
			M[j*n + i] = (double)rand()/(RAND_MAX/2.0)-1.0;
		}
	}
}

void fillVector(int n, double *X){
	for (int i = 0;i < n;i++){
		X[i] = (double)rand()/(RAND_MAX/2.0)-1.0;
	}
}

void printMatrix(int n, double *H){
	for (int i = 0;i<n;i++){
		for (int j = 0;j<n;j++){
			cout << H[j*n + i] << " ";
		}
		cout << endl;
	}
}

void printVector(int n, double *f){
	for (int i = 0;i<n;i++){
		cout << f[i] << endl;
	}
}

void solveConjugateGradient(int n, double *A, double *b, double *x){
	double *r = new double[n];
	double *p = new double[n];
	double *t = new double[n];
	int k = 0;
	double alpha;
	double beta;
	double eps;
	double tol = 0.00001;
	
	cblas_dcopy(n,b,1,r,1); //r_0 = b
	cblas_dsymv(CblasColMajor, CblasUpper, n, -1, A,n,x,1,1.0,r,1);
	cblas_dcopy(n,r,1,p,1); //p_0 = r_0

	while (k<5000){
		cblas_dsymv(CblasColMajor, CblasUpper, n, 1.0, A, n, p,1,0.0,t,1);//t = A*p_k;
		alpha = cblas_ddot(n,t,1,p,1); //alpha = p_k^T*p_k
		alpha = cblas_ddot(n,r,1,r,1) / alpha; //compute the alpha_k
		beta = cblas_ddot(n,r,1,r,1);
		
		cblas_daxpy(n,alpha,p,1,x,1); // x_{k+1} = x_k = alpha_k * p_k;
		cblas_daxpy(n,-alpha,t,1,r,1);
		
		eps = cblas_dnrm2(n,r,1);
		cout <<"Iteration" << k << ":eps = " << eps << endl;
		
		if (eps < tol * tol){
			break;
		}
		
		beta = cblas_ddot(n,r,1,r,1)/beta;
		
		cblas_dcopy(n,r,1,t,1);
		cblas_daxpy(n,beta,p,1,t,1);
		cblas_dcopy(n,t,1,p,1);
		k++;
	}
	
	delete[] r;
	delete[] p;
	delete[] t;
}

int main()
{
	const int n = 8;
	double *M = new double[n*n];
	double *A = new double[n];
	double *x = new double[n];
	double *y = new double[n];
	double *b = new double[n];
	
	fillMatrix(n,M);
	fillVector(n,x);
	
	cblas_dsyrk(CblasColMajor, CblasUpper, CblasNoTrans, n,n,1.0,M,n,0.0,A,n);
	
	cout << "symmetric matrix M:" << endl;
	printMatrix(n,M);
	cout << "MTM :"<<endl;
	printMatrix(n,A);
	cout << "Initial vector:" <<endl;
	printVector(n,x);
	
	//compute b = A*x;
	cblas_dsymv(CblasColMajor, CblasUpper, n,1.0,A,n,x,1, 0.0,b,1);
	solveConjugateGradient(n,A,b,y);
	printVector(n,y);
}
