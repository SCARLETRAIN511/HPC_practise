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
						
	void F77NAME(cgeev)(const char &jobvl, const char &jobvr, const int &n,
						double *a, const int &lda, double *w,
						double *vl, int &ldvl, double *vr, int &ldvr,
						double *work, int &lwork, double *rwork, int *info);
	void F77NAME(dgeev)(const char &jobvl, const char &jobvr, const int &n,
						double *a, const int &lda, double *wr, double *wi, 
						double *vl, int &ldvl, double *vr, int &ldvr,
						double *work, int &lwork, int *info);
}

void generateMatrix(int &n, double *A){
	srand(time(0));
	for (int i = 0;i < n;i++){
		for (int j = i;j<n;j++){
			A[i*n + j] = A[j*n + i] = (0.5-(double)(rand())/RAND_MAX)/0.5;
		}
	}
}


void printVectorComp(int n, double *A, double *B){
	for(int i = 0; i < n;i++){
		cout << A[i] << " + " << B[i] << "i" << endl;
	}
	cout << endl;
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

int getMaxIndex(int &N, double *A){
	double max = -10.0;
	int index = 0;
	for (int i = 0; i<N;i++){
		if (A[i] > max){
			max = A[i];
			index = i;
		}
	}
	
	return index;
}

int main()
{
	//create the matrix
	int N = 10;
	int lda = N;
	double *work;
	int lwork = -1;
	double wkopt;
	double *A = new double[N*N];
	generateMatrix(N,A);
	printMatrix(N,N,A);
	
	//get the eigen
	//store the eigenvalues
	int info = 0;
	double *wr = new double[N];
	double *wi = new double[N];
	
	int ldvl = N;
	double *vl = new double[N*N]; 
	int ldvr = N;
	double *vr = new double[N*N]; 
	
	// Optimize the size
	F77NAME(dgeev)('N','N',N,A,lda,wr,wi,vl,ldvl,vr,ldvr,&wkopt,lwork,&info);
	lwork = (int)wkopt;
	work = new double[lwork];
	
	//compute the eigenvalues;
	F77NAME(dgeev)('N','N',N,A,lda,wr,wi,vl,ldvl,vr,ldvr,work,lwork,&info);
	
	//print out the eigen values of the matrix
	printVectorComp(N,wr,wi);
	
	//find maximum
	int index = getMaxIndex(N,A);
	cout << "The maximum eigenval is " << wr[index] << " + " << wi[index] << "i" << endl;
}
