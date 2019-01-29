#include<iostream>
#include<String>

using namespace std;

struct User
{
	string name;
	User *fri;
} A, B, C;


int main()
{
	A.name="Harsha";
	B.name="Ram";
	C.name="Sam";
	
	A.fri= &B;
	B.fri= &C;
	C.fri= &A;
	
	cout<< "Friend of " << A.name << " is " << A.fri->name <<endl;
	cout<< "Friend of " << B.name << " is " << B.fri->name <<endl;
	cout<< "Friend of " << C.name << " is " << C.fri->name <<endl;
	
}
