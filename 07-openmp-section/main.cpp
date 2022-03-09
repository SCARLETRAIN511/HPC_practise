#include <iostream>
using namespace std;
#include <omp.h>
#include <iomanip>
#include <iostream>

int main()
{
	const int N = 10;
	int i;
	float a[N], b[N], c[N], d[N];
	
	for (int i = 0;i<N;i++){
		a[i] = i * 1.0;
		b[i] = i + 2.0;
	}
	
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			for (int i = 0;i<N;i++){
				c[i] = a[i] + b[i];
			}
	
			#pragma omp section
			for (int i = 0;i < N;i++){
				d[i] = a[i] * b[i];
			}
		}
	}
	

	
	for (i = 0;i < N;i++){
		cout << setw(10) << a[i] << setw(10) << b[i] << setw(10) << c[i] << setw(10) << d[i] <<endl;
	}
	

}
