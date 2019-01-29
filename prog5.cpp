// Bag Implementation with Dynamic Array

#include<iostream>
#include<string>


using namespace std;

class Bag
{
	public:
		Bag();
		bool add (int a);
		bool remove (int a);
		bool has(int a);
		ShowItems();
		
	
	private:
		int *items;
		int cap;
		unsigned int size;
};


Bag::Bag()
{
	cout<<"Enter the capacity of the bag: ";
	cin>>cap;
	items = new int[cap];
	cout<< "A bag with " << cap << " is ready!!" << endl;
	size=0;
}

Bag::ShowItems()
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

bool Bag::add(int a)
{
	if(size == cap)
	{
		cout<<"The bag is full!!  Cannot add "<<a <<" !!"<< endl;
		return false;
	}
	items[size++] = a;
	cout<< "added"<<endl;
	return true;
}

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

bool Bag::remove(int a)
{
	short NumDel=0;
	for(int i=0;i<size;i++)
	{
		if(items[i]==a)
		{

			items[i]=items[--size];
			i--;
			cout<<a<<" got removed!!"<<endl;
			
			NumDel++;
		}
	}
	
	if(NumDel>0)	
	return true;
	else
	{
	cout<<a<<" is not there!!"<<endl;
	return false;
	}

}

int main()
{
	Bag abag;
	abag.add(10);
	abag.add(20);
	abag.add(30);
	abag.add(40);
	abag.add(50);
	abag.add(60);
	abag.add(70);
	abag.add(80);
	abag.add(90);
	abag.add(100);
	abag.add(110);
	abag.ShowItems();
	abag.has(20);
	abag.has(45);
	abag.remove(20);
	abag.ShowItems();
	abag.remove(75);
	abag.ShowItems();
	
}
