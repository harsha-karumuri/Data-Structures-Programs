#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  4000
#define M  8000

using namespace std;


void swap(int A[], int i, int min);
bool small(int a, int b);
void print(int A[]);
void fillRandom(int A[], int size);
	

int main(int argc, const char * argv[]) 
{
	int  A[N]={0},B[N]={0};
	fillRandom(A,N);
    fillRandom(B,N);
    int  C[M]={0},D[M]={0};
	fillRandom(C,M);
    fillRandom(D,M);

    int swaps=0;
	long int comps=0;
	int assignments=0;
	// Selection sort for 4000 elements
	for (int i = 0; i < N; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		
		for (int j = i+1; j < N; j++)
		{
			comps++;
			if ( small(A[j], A[min]) == true) {
			min = j;    
			assignments++;  }        //compare           
		}
		swap(A, i, min);      //swap
        swaps++;
	}
	cout<<"Selection Sort Analysis for "<<N<<" elements : "<<endl;
	cout<<"----------------------------------------------";
	cout<<endl<<"Assignements: "<<assignments<<endl;
	cout<<endl<<"Swaps: "<<swaps<<endl;
	cout<<endl<<"Comparisons: "<<comps<<endl;
	cout<<endl<<endl;

    swaps=0;
	comps=0;
	assignments=0;
	// Selection sort for 8000 elements
	for (int i = 0; i < M; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		
		for (int j = i+1; j < M; j++)
		{
			comps++;
			if ( small(C[j], C[min]) == true) {
			min = j;    
			assignments++;  }        //compare           
		}
		swap(C, i, min);      //swap
        swaps++;
	}
	cout<<"Selection Sort Analysis for "<<M<<" elements : "<<endl;
	cout<<"----------------------------------------------";
	cout<<endl<<"Assignements: "<<assignments<<endl;
	cout<<endl<<"Swaps: "<<swaps<<endl;
	cout<<endl<<"Comparisons: "<<comps<<endl;
		cout<<endl<<endl;

    int swapss=0;
	int compares=0;	
	// Insertion sort for 4000 elements
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j > 0; j--)
        {
        	compares++;
            if ( small(B[j], B[j-1]) == true) // compare
                {swap(B, j, j-1); 
                swapss++;
				}// exchange or swap
            else break;
        }
    }
	cout<<"Insertion Sort Analysis for "<<N<<" elements : "<<endl; 
   	cout<<"----------------------------------------------";
    cout<<endl<<"Swaps: "<<swapss<<endl;
	cout<<endl<<"Comparisons: "<<compares<<endl;
		cout<<endl<<endl;
	
    swapss=0;
	compares=0;	
	// Insertion sort for 8000 elements
    for (int i = 0; i < M; i++)
    {
        for (int j = i; j > 0; j--)
        {
        	compares++;
            if ( small(D[j], D[j-1]) == true) // compare
                {swap(D, j, j-1); 
                swapss++;
				}// exchange or swap
            else break;
        }
    }
	cout<<"Insertion Sort Analysis for "<<M<<" elements : "<<endl; 
	cout<<"----------------------------------------------";
    cout<<endl<<"Swaps: "<<swapss<<endl;
	cout<<endl<<"Comparisons: "<<compares<<endl;
	cout<<endl<<endl;
	
}

void swap(int A[], int i, int min)
{
	int tmp= A[i];
	A[i]=A[min];
	A[min]=tmp;	

}

void fillRandom(int A[], int size)
{	
	for (int i = 0; i < size; i++)
		A[i]=(rand() % 199)-99;	
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
