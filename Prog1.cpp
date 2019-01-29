#include<iostream>
#include<String>

using namespace std;

struct Cls
{
	string name;
	int cap;
};

struct Student
{
	string FN;
	string LN;
	Cls *FC;
	Cls *SC;
};

int main()
{
	Student Stu[3];
	Cls Catalog[3];
	
	Stu[0].FN = "Tom"; Stu[0].LN = "Apple";
	Stu[1].FN = "Karen"; Stu[1].LN = "Orange";
	Stu[2].FN = "Kelly"; Stu[2].LN = "Green";
	
	Catalog[0].name = "CSCI 151"; Catalog[0].cap= 25;
	Catalog[1].name = "CSCI 152"; Catalog[1].cap= 25;
	Catalog[2].name = "CSCI 153"; Catalog[2].cap= 25;
	
	Stu[0].FC= &Catalog[0];
	Stu[0].SC= &Catalog[1];
	Stu[1].FC= &Catalog[1];    
	Stu[1].SC= &Catalog[2];   
	Stu[2].FC= &Catalog[1];
	Stu[2].SC= &Catalog[2];   // Stu[2].SC= Stu[1].SC;
	
	cout<< "First Class of " << Stu[0].FN << " is " << Stu[0].FC->name << endl;
	cout<< "Second Class of " << Stu[0].FN << " is " << Stu[0].SC->name<< endl;
	
	cout<< "First Class of " << Stu[1].FN << " is " << Stu[1].FC->name<< endl;
	cout<< "Second Class of " << Stu[1].FN << " is " << Stu[1].SC->name<< endl;
	
	cout<< "First Class of " << Stu[2].FN << " is " << Stu[2].FC->name<< endl;
	cout<< "Second Class of " << Stu[2].FN << " is " << Stu[2].SC->name << endl;

}

