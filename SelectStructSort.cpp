//Sri Harsha Karumuri
//50201598
//S18-L-5

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  20

using namespace std;

struct city     //Structure of city
{
    unsigned int population;
    unsigned short founded;
    string major;
};

unsigned int RandPopulation();  //returns random population 1,000 - 50,000
unsigned short RandFounded();   //returns random year found 1700-2010
string RandMajor();             //reutrns random major of 3 upper case letters

void swap(city A[], int i, int min);     //All swapping is done here
bool smallPop(city A[], int a, int b);   //sorting of population is done in this function
bool smallFou(city A[], int a, int b);   //sorting of year founded is done in this function
bool smallMaj(city A[], int a, int b);   //sorting of major is done in this function
void print(city A[]);                    //printing of structure is done here
void fillRandom(city A[], int size);     //fits all randomly created values in this function

int main(int argc, const char * argv[]) 
{
	cout<<"20 Random cities created: \n\n";
	cout<<"population  year_founded  major\n";
	cout<<"----------  ------------  -----\n";
	city *A = new city[N];
	fillRandom(A,N);
	print(A);
	cout<<"-------------------------------\n";
	
	cout<<"\nSort cities over population: \n\n";
	cout<<"population  year_founded  major\n";
	cout<<"----------  ------------  -----\n";
	for (int i = 0; i < N; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		for (int j = i+1; j < N; j++)
		{
			if ( smallPop(A, j, min) == true) min = j;
		}
		swap(A, i, min);
	}
	print(A);
	cout<<"-------------------------------\n";
	
	cout<<"\nSort cities over year founded: \n\n";
	cout<<"population  year_founded  major\n";
	cout<<"----------  ------------  -----\n";
	for (int i = 0; i < N; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		for (int j = i+1; j < N; j++)
		{
			if ( smallFou(A, j, min) == true) min = j;
		}
		swap(A, i, min);
	}
	print(A);
	cout<<"-------------------------------\n";
	
	cout<<"\nSort cities over major: \n\n";
	cout<<"population  year_founded  major\n";
	cout<<"----------  ------------  -----\n";
	for (int i = 0; i < N; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		for (int j = i+1; j < N; j++)
		{
			if ( smallMaj(A, j, min) == true) min = j;
		}
		swap(A, i, min); 
	}
	print(A);
	cout<<"-------------------------------\n";
    return 0;	
}

void swap(city A[], int i, int min)
{
	city tmp = A[i];
	A[i]=A[min];
	A[min]=tmp;	
}

void fillRandom(city A[], int size)
{	
	for (int i = 0; i < size; i++)
	{
		A[i].population=RandPopulation();
		A[i].founded=RandFounded();
		A[i].major=RandMajor();
	}
}

void print(city A[])
{	
	for (int i = 0; i < N; i++)
	{
		cout << "  "<< A[i].population << "        " << A[i].founded << "        " << A[i].major;
	    cout << endl;
    }
}

bool smallPop(city A[],int a, int b)
{
  if (A[a].population < A[b].population) return true;
  return false;
}

bool smallFou(city A[],int a, int b)
{
  if (A[a].founded < A[b].founded) return true;
  return false;
}

bool smallMaj(city A[],int a, int b)
{
  if (A[a].major < A[b].major) return true;
  return false;
}

unsigned int RandPopulation()
{
	unsigned int pop;
	pop = rand() % (50000 - 1000) + 1000;
	return pop;
}

unsigned short RandFounded()
{
	unsigned short fou;
	fou = rand() % (2010 - 1700) + 1700;
	return fou;
}

string RandMajor()
{
	string maj="ABC";
	maj[0] = rand() % 26 + 65;
	maj[1] = rand() % 26 + 65;
	maj[2] = rand() % 26 + 65;
	return maj;
}
