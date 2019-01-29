//
//  main.cpp
//  Priority Queue in Unsorted Array
//
//  Created by MM on 11/3/16.
//  Copyright © 2016 MM. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
// #define N  10

using namespace std;

void swap(int a, int b);
void insert(int x);
bool small(int a, int b);
void print(int A[]);
bool isEmpty();
int delMax();

int N = 0;
int *A;

int main(int argc, const char * argv[])
{
    A = new int[10];
    //print(A);
    insert(5);
    insert(53);
    insert(8);
    insert(20);
    print(A);
    cout << "Del Max: " << delMax() << endl;
    print(A);
}

bool isEmpty()
{  return N == 0; }

void insert(int x)
{  A[N++] = x;  }

int delMax()
{
    int max = 0;
    for (int i = 1; i < N; i++)
        if (small(A[max], A[i])) max = i;
    swap(max, N-1);
    return A[--N];
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

void swap(int a, int b)
{
    int tmp= A[a];
    A[a]=A[b];
    A[b]=tmp;
}

