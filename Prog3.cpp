#include<iostream>
#include<String>

using namespace std;

int main()
{
	int A[10]= {5,6,7,8};       // static array
	
	int *ptr = new int[10];     // dynamic array
	
	ptr[0]=100; 
	ptr[1]=200;
	ptr[2]=300;
	
	cout<< ptr[0] << endl;      //100
	ptr++;                      // It will work because it is dynamic pointer.
	cout<< ptr[0] << endl;      //200

	
	cout << A[0] << endl;
	// A++;    It will not work because it is static pointer.
	cout<< A[1] << endl;
	
	
}
