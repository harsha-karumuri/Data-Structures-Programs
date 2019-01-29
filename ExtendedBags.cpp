// SRI HARSHA KARUMURI  - Feb 19, 2018

// CWID: 50201598

// Compiler: GNU C++, Eclipse C++

// Assignment S18-L-2

/* This program is based on the bag implementation by using some bag functionalities like Add, Remove, Has, Show, Max, Min, Avg etc.. */

#include<iostream>
#include<string>
using namespace std;
#define N 10

/* This is the class where we initialize all functions and parameters which we use in the program */

class Bag
{
	public:
		Bag();
		bool add (int a);
		bool remove (int a);
		bool has(int a);
		void ShowItems();
		float AveOfItems();
		int MinOfItems();
		int MaxOfItems();
		
	
	private:
		int items[N];
		unsigned int size;
};


/* This is the constructor of the class "Bag".. this will be called automatically when the object is istantiated in the main method.. 
   Here we will initialize all parameters */

Bag::Bag()
{
	cout<< "A bag with " << N << " is ready!!" << endl;
	size=0;
}


/* This function shows all the items in the bag if present.. */

void Bag::ShowItems()
{
	if(size==0)
	cout<<"Bag is empty!!";
	else
	{
	for(int i=0; i<size; i++)
	cout<<"  "<<items[i]<<"  ";
	cout<<endl;
    }
}


/* This function adds an element in to the bag.. 
   Checks if any element can fit into the array by comparing size and number of elements..
   If vacancy is present then size of the array gets incremented by 1 and 
   the argument value stores into that last index */

bool Bag::add(int a)
{
	if(size == N)
	{
		return false;
	}
	items[size++] = a;
	return true;
}


/* This function tells if the specified element is present in the array or not
   The element comes from the argument and gets compared with every element of the array
   If item is present then it tells the location and returns true.. If not returns flase.. */

bool Bag::has(int a)
{
	for(int i=0; i<size; i++)
	{
		if(items[i]==a)
		{
		cout<<"Yeahh.. "<<a<<" is present in location "<<i+1<<" !!"<<endl;
		return true;
	    }
	}
	cout<<"Sorry.. "<<a<<" is not present!!"<<endl;
	return false;
}


/* This function removes an element from bag if it is present..
   The value from arguemnt gets compared with every element in the array..
   If matches.. the last element of the array comes into the position of the matched element.. and the size gets reduced..
   If doesn't match.. element is not present in the array */

bool Bag::remove(int a)
{
	short NumDel=0;
	for(int i=0;i<size;i++)
	{
		if(items[i]==a)
		{

			items[i]=items[--size];
			i--;
			NumDel++;
		}
	}
	
	if(NumDel>0)	
	return true;
	else
	{
	return false;
	}

}


/* This function returns the average of all the elements in the array..
   All elements in the array gets added up.. and then gets divided by the size of the array.. 
   Then we will get the average of the bag elements..
   This returns the float value because.. avg of int items results float value.. */

float Bag::AveOfItems()
{
	float sum=0 , average;
	
	for(int x=0 ; x<size ; x++)
	{
		sum= sum+items[x];
	}
	
	average= sum/size;
	return average;
}


/* This function returns the Maximum element present in the bag..
   First we will consider the first element of array as the Maximum number..
   Then we will compare each element of array with the Max.. 
   if the element is larger than the previous one then.. it will be considered as largest..
   Then we will return the larger element */

int Bag::MaxOfItems()
{
	int maximum= items[0];
	
	for(int x=0; x<size; x++)
	{
		if(items[x]>maximum)
		maximum = items[x];
	}
	return maximum;
}


/* This function returns the Minimum element present in the bag..
   First we will consider the first element of array as the Minimum number..
   Then we will compare each element of array with the Min.. 
   if the element is smaller than the previous one then.. it will be considered as smallest..
   Then we will return the smallest element */

int Bag::MinOfItems()
{
	int minimum= items[0];
	
	for(int x=0; x<size; x++)
	{
		if(items[x]<minimum)
		minimum = items[x];
	}
	return minimum;
}


/* Main method is the method where the program gets started..
   The object of bag gets instantiated and functions will be called using that object */

int main()
{
	Bag abag;
	cout<<"ADD 10: " <<abag.add(10)<<endl;
	cout<<"ADD 20: " <<abag.add(20)<<endl;
	cout<<"ADD 30: " <<abag.add(30)<<endl;
	cout<<"ADD 40: " <<abag.add(40)<<endl;
	cout<<"ADD 50: " <<abag.add(50)<<endl;
	cout<<"ADD 60: " <<abag.add(60)<<endl;
	cout<<"ADD 70: " <<abag.add(70)<<endl;
	cout<<"ADD 80: " <<abag.add(80)<<endl;
	cout<<"ADD 90: " <<abag.add(90)<<endl;
	cout<<"ADD 100: " <<abag.add(100)<<endl;
	cout<<"ADD 110: " <<abag.add(110)<<endl<<endl;
	
	abag.ShowItems();
	cout<<endl;
	abag.has(20);
	cout<<endl;
	abag.has(45);
	
	cout<<endl <<"REMOVE 20: "<< abag.remove(20) <<endl;
	abag.ShowItems();
	cout<<endl <<"REMOVE 75: "<< abag.remove(75) <<endl;
	abag.ShowItems();
	cout<<endl;
	
	cout<<"Average of the items present in the bag is: "<< abag.AveOfItems() <<endl;
	cout<<"Maximum of the items present in the bag is: "<< abag.MaxOfItems() <<endl;
	cout<<"Minimum of the items present in the bag is: "<< abag.MinOfItems() <<endl;
}
