
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N 10

using namespace std;

// A struct to keep items
struct node
{
    string Name;
    int	ID;
};

string RandomStr();  // A function to randomly generate 6  chars strings.
void swap(node* A[], int i, int min);
bool small(node* A[], int a, int b);
void print(node* A[]);
void fillRandom(node* A[], int size);

int main(int argc, const char *argv[])
{
	srand(25);
    //node **A = new node*[N];   //Dynamic
    node* A[N];                //Static
    //int **K= new int *[N];
	//int* K[N];
	
	fillRandom(A,N);
	print(A);
	
	for (int i = 0; i < N; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		for (int j = i+1; j < N; j++)
		{
			if ( small(A, j, min) == true) min = j;
		}
		swap(A, i, min);
	}
	print(A);
}

void swap(node* A[], int i, int min)
{
	node* temp;
	temp = A[i];
	A[i] = A[min];
	A[min] = temp;
}

void fillRandom(node* A[], int size)
{	
	for (int i = 0; i < size; i++)
	{
		A[i]= new node;
		A[i]->Name=RandomStr();
		A[i]->ID=rand() % 50;	
	}
}

bool small(node* A[], int a, int b)
{
	  if (A[a]->ID < A[b]->ID) return true;
  return false;
}

string RandomStr()
{
    string AddMe="02-45-79"; // A string example  we will randomle generate
    for (int j=0; j < 8; j++)
    {
        if (j== 3 || j== 4 )
            AddMe[j]=rand() % 10 + 48;
        else if (j== 2 || j== 5)
            AddMe[j]= '-';
        else AddMe[j]=rand() % 26 + 65;
    }
    return AddMe;
}


void print(node* A[])
{	
	for (int i = 0; i < N; i++)
		cout << A[i]->Name << ":" << A[i]->ID << ", ";
	cout << endl;
}
