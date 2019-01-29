 
// Mutlu Mete, Oct 15, 2016
// Insertion Sort in Randomly genereated integer array

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N 10

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
    
    // Insertion sort
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j > 0; j--)
            if ( small(A[j], A[j-1]) == true) // compare
                swap(A, j, j-1); // exchange or swap
            else break;
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
        A[i] = (rand() % 9999) + 1;
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
