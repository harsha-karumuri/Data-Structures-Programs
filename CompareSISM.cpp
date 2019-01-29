// SRI HARSHA KARUMURI
// 50201598
// S18-L-7  LAB ASSIGNMENT


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>    // used to caluculate the time
#include<iomanip>    // used for precision %.4f

using namespace std;

void swap(int A[], int i, int min);      // this function is used to swap the numbers
bool small(int a, int b);                // this function is used to compare two numbers
void print(int A[], int size);           // this function is used to print all the numbers ---> 25 per line
void fillRandom(int A[], int size);      // this is used too fill the random numbers between 0 to 100

void selSort(int A[], int size);         // SELECTION SORT
void insSort(int A[], int size);         // INSERTION SORT
void shellSort(int A[], int size);       // SHELL SORT
void mergeSort(int a[], int size);       // MERGE SORT

void merge(int arr[], int l, int m, int r);
void mergeSort(int a[], int aux[], int lo, int hi);


int main(int argc, const char * argv[]) 
{
	clock_t start, end;
    double total;
    int N;
    cout<<"  RUNNING TIME COMPARISONS FOR SORTING ALGORITHMS (IN SECONDS)\n\n";
    cout<<"             selection   insertion      shell     merge\n";
    for(int j=0;j<3;j++)
    {
    	
    if(j==0){ N=2000; cout<<"    2K   ";}
    if(j==1){ N=4000; cout<<"    4K   ";}
    if(j==2){ N=8000; cout<<"    8K   ";}
    
    // SELECTION SORT
	int A[N]={0};
	fillRandom(A,N);
	start = clock();
    selSort(A,N);
    end = clock();
    total = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"     ";
    cout<<fixed<<setprecision(4)<<total;

    // INSERTION SORT
    A[N]={0};
	fillRandom(A,N);
//	print(A,N);
	start = clock();
    insSort(A,N);
    end = clock();
    total = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"      ";
    cout<<setprecision(4)<<total;

	// SHELL SORT
	A[N]={0};
	fillRandom(A,N);
//	print(A,N);
	start = clock();
    shellSort(A,N);
    end = clock();
    total = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"       ";
    cout<<setprecision(4)<<total;

    // MERGE SORT
    A[N]={0};
	fillRandom(A,N);
//	print(A,N);
	start = clock();
    mergeSort(A,N);
    end = clock();
    total = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"     ";
    cout<<setprecision(4)<<total;
    cout<<"\n";

    }
}

void selSort(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		for (int j = i+1; j < N; j++)
		{
			if ( small(A[j], A[min]) == true) min = j;
		}
		swap(A, i, min);
	}
//	print(A,N);
}

void insSort(int A[], int N)
{
	for (int i = 0; i < N; i++)
    {
        for (int j = i; j > 0; j--)
            if ( small(A[j], A[j-1]) == true) // compare
                swap(A, j, j-1); // exchange or swap
            else break;
    }
//    print(A,N);
}

void shellSort(int A[], int N)
{
	// Shelll sort
	// Sort a[] into increasing order.

	int h = 1;
	while (h < N/3) h = 3*h + 1; // 1, 4, 13, 40, 121, 364, 1093, ...
	while (h >= 1)
	{ // h-sort the array.
//		cout << "h=" << h << endl; 
		for (int i = h; i < N; i++)
		{   // Insert a[i] among a[i-h], a[i-2*h], a[i-3*h]... .
			for (int j = i; j >= h && small(A[j], A[j-h]); j -= h)
			swap(A, j, j-h);
		}
//		print(A,N);
	h = h/3;
	}	

//	print(A,N);
}

void merge(int a[], int aux[], int lo, int mid, int hi) {
    
    for (int k = lo; k <= hi; k++)      aux[k] = a[k];
        
        int i = lo, j = mid+1;
        
        for (int k = lo; k <= hi; k++)
        {
            if(i > mid)                      a[k] = aux[j++];
            else if (j > hi)                 a[k] = aux[i++];
            else if (small(aux[j], aux[i]))  a[k] = aux[j++];
            else                             a[k] = aux[i++];
        }
}

void mergeSort(int a[], int aux[], int lo, int hi)
{
    if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
    mergeSort(a, aux, lo, mid);
    mergeSort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

void mergeSort(int a[], int N)
{
    int *aux = new int[N];
    mergeSort(a, aux, 0, N-1);
}

void swap(int A[], int i, int min)
{
	int tmp= A[i];
	A[i]=A[min];
	A[min]=tmp;	
}

void fillRandom(int A[], int N)
{	
	for (int i = 0; i < N; i++)
		A[i]=( rand() % 99 ) + 1;	
}

void print(int A[], int N)
{	
    int j=0;
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << ", ";
		j++;
		if(j==25)               //25 per line
		{
			cout<<endl;
			j=0;
		}
	}
	cout << endl;
}

bool small(int a, int b)
{
  if (a < b) return true;
  return false;
}
