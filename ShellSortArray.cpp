#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  10

using namespace std;


void swap(int A[], int i, int min);
bool small(int a, int b);
void print(int A[]);
void fillRandom(int A[], int size);

int main(int argc, const char * argv[]) 
{
	int  A[N]={0};
	fillRandom(A,N);
	print(A);
	
	// Shelll sort
	// Sort a[] into increasing order.

	int h = 1;
	while (h < N/3) h = 3*h + 1; // 1, 4, 13, 40, 121, 364, 1093, ...
	while (h >= 1)
	{ // h-sort the array.
		cout << "h=" << h << endl; 
		for (int i = h; i < N; i++)
		{   // Insert a[i] among a[i-h], a[i-2*h], a[i-3*h]... .
			for (int j = i; j >= h && small(A[j], A[j-h]); j -= h)
			swap(A, j, j-h);
		}
		print(A);
	h = h/3;
	}	

	print(A);
}

void swap(int A[], int i, int min)
{
	int tmp= A[i];
	A[i]=A[min];
	A[min]=tmp;	
}

void fillRandom(int A[], int size)
{	
	for (int i = 0; i < N; i++)
		A[i]=rand() % 50;	
}

void print(int A[])
{	
	for (int i = 0; i < N; i++)
		cout << A[i] << ", ";
	cout << endl;
}

bool small(int a, int b)
{
  if (a < b) return true;
  return false;
}





