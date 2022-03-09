#include <iostream>
using namespace std;
#include <omp.h>

int main(int argc, char *argv[])
{
	int nthreads = 0;
	int threadid = 0;
	
	#pragma omp parallel private(nthreads, threadid)
	{
	threadid = omp_get_thread_num();
	cout << "Hello World from thread: " << threadid << endl;
	
	if (threadid == 0){
		nthreads = omp_get_num_threads();
		cout << "Num of threads" << nthreads << endl;
		}
	}
	
}
