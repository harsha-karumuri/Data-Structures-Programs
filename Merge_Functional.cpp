//
//  main.cpp
//  MergeFunctional
//
//  Created by MM on 10/31/16.
//  Copyright © 2016 MM. All rights reserved.
//  Non- recursive, functional Merge Sort



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
void merge(int arr[], int l, int m, int r);
void sort(int a[]);
//void sort(int a[], int aux[], int lo, int hi);

int main(int argc, const char * argv[])
{
    int  A[N]={0};
    fillRandom(A,N);
    print(A);
    sort(A);
    print(A);
}

void merge(int a[], int aux[], int lo, int mid, int hi){
    
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

void sort(int a[])
{
    int *aux = new int[N];
    for (int sz = 1; sz < N; sz = sz+sz)
        for (int lo = 0; lo < N-sz; lo += sz+sz)
            merge(a, aux, lo, lo+sz-1, min(lo+sz+sz-1, N-1));
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


