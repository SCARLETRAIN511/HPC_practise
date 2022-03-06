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
	void F77NAME(dsyev)(const char &v, const char &ul, const int &n,
						double *a, const int &lda, double *w,
						double *work, const int &lwork, int *info);
}

void printMatrix(int &M, int &N, double *A){
	for (int i = 0;i < M;i++){
		for (int j = 0;j < N;j++){
			cout<< A[j*M + i] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printVector(int n, double *f){
	for(int i = 0; i < n;i++){
		cout << f[i] << endl;
	}
	cout << endl;
}

void solveMatrixCompare(){
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


void eigenEx(){
	int n = 10;
	int lda = n;
	int info = 0;
	int lwork = -1;
	double wkopt;
	double *A = new double[n*n];
	double *w = new double[n];
	double *work;
	
	
	srand(time(0));
	for (int i = 0;i < n;i++){
		for (int j = i;j<n;j++){
			A[i*n + j] = A[j*n + i] = (double)(rand())/RAND_MAX;
		}
	}
	
	for (int i = 0; i< n;i++){
		for (int j = 0;j < n;j++){
			cout << A[j*n + i] << " ";
		}
		cout << endl;
	}
	
	printMatrix(n,n,A);
	
	F77NAME(dsyev)('V','U',n,A,lda,w,&wkopt,lwork,&info);
	lwork = (int)wkopt;
	work = new double[lwork];
	
	//compute the eigen values;
	F77NAME(dsyev)('V','U',n,A,lda,w,work,lwork,&info);
	

	printVector(n,w);
}

int main()
{
	eigenEx();

}
