#include <iostream>
using namespace std;
#include <omp.h>

int main(int argc, char *argv[])
{
	const int n = 100;
	const int chunk = 10;
	int i = 0;
	double dot = 0.0;
	double norm_a = 0.0;
	double prod_b = 1.0;
	double a[n], b[n];
	
	for (i = 0;i<n;i++){
		a[i] = i * 1.0/n;
		b[i] = (i+1) * 2.0/n;
	}
	
	#pragma omp parallel for reduction(+:dot,norm_a) reduction(*:prod_b) schedule(static, chunk)
	for (i = 0;i<n;i++){
		cout << omp_get_thread_num()<<endl;
		dot = dot + (a[i] * b[i]);
		norm_a = norm_a + (a[i] * a[i]);
		prod_b = prod_b * b[i];
	}
	
	cout << "Final dot: " << dot<< endl;
	cout << "Final norm_a = "<< norm_a << endl;
	cout << "Final prod_b = "<< prod_b << endl;

}
