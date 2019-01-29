#include<iostream>
#include<time.h>
using namespace std;

int main()
{
	clock_t start, stop;
	double totalTime;
	int size = 128 * 1024 * 1024;
	int *a = new int[size];
	
	start = clock();
	for(int i=0; i<size; i++)
	    a[i] *= 2;
    stop = clock();
	
	totalTime = (stop - start) / (double) CLOCKS_PER_SEC;
	cout<<"total time = "<<totalTime<<"\n";
	delete []a;
	 
	int *b = new int[size];
	
	start = clock();
	for(int i=0; i<size; i+=16)
	    b[i] *= 2;
    stop = clock();
	
	totalTime = (stop - start) / (double) CLOCKS_PER_SEC;
	cout<<"total time = "<<totalTime;
	delete []b;  
}
