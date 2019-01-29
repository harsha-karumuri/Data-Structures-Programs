
// Mutlu Mete 
// Recursive Merge Sort in Randomly genereated integer array

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  5

using namespace std;

bool small(int a, int b);


bool small(int a, int b)
{
    if (a < b) return true;
    return false;
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

void sort(int a[], int aux[], int lo, int hi)
{
    if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
	//cout << lo << "\t" << mid << "\t" << hi << endl;
    sort(a, aux, lo, mid);
    sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort(int a[])
{
    int *aux = new int[N];
    sort(a, aux, 0, N-1);
}

void swap(int A[], int i, int min);
bool small(int a, int b);
void print(int A[]);
void fillRandom(int A[], int size);
void merge(int arr[], int l, int m, int r);


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

int main(int argc, const char * argv[])
{
    int  A[N]={0};
    fillRandom(A,N);
    print(A);
	cout << endl << "lo" << "\t" << "mid" << "\t" << "hi" << endl;
    sort(A);
    print(A);
}


