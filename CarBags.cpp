//CARBAGS
//KARUMURI SRI SAI CHAITANYA
//CWID:50170235

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <time.h>
using namespace std;

struct Car
{
	unsigned short price;
	unsigned short year;
	string owner;
	string Vin;
	Car *next;

};
int Menu();
unsigned short randprice();
unsigned short randomyear();
string randowner();
string generateVin();
class Bag
{
public:
	Bag();
	bool addCar();
	bool has(string str);
	void remove(string str);
	void removelast();
	void emptyBag();
	void ListBag();
	unsigned short getSize();
	bool hadcar(string vin);

private:
	Car *head;
	Car *last;
	unsigned short size;
};
Bag::Bag()
{
	size = 0;
	head = NULL;
	last = NULL;
	cout << "A bag was created with 0 items" << endl;
}
void Bag::emptyBag()
{
	Car *Del = head;

	while (Del != NULL) {
		
		head = head->next;
		delete Del;
		
		Del = head;
	}
	
	last = head = NULL;
	size = 0;
	cout << "removed all the cars from bag" << endl;
}
void Bag::removelast()
{
	
	if (head == NULL)
	{
		cout << "the bag is empty" << endl;
		return;
	}
		

	if (head->next == NULL)
	{
		cout << "removed : " << head->Vin << endl;
		delete head;
		size=0;
		head = NULL;
		last = NULL;
		return;
	}

	Car *currNode = head;
	while (currNode->next && currNode->next->next != NULL)
	{
		currNode = currNode->next;
	}
	cout << "removed : " << currNode->next->Vin << endl;
	size--;
	delete currNode->next;
	currNode->next = NULL;
}
bool Bag::hadcar(string vin)
{
	Car *it = head;
	while (it != NULL)
	{
		if (it->Vin == vin)return true;
		it = it->next;
	}
	return false;
}
bool Bag::addCar()  //Adds an item to the bag
{string vin= generateVin();
while (hadcar(vin))
{
	vin = generateVin();
}
	Car *addItem = new Car;
	if (addItem == NULL)return false;
	addItem->owner = randowner();
	addItem->price = randprice();
	addItem->Vin = vin;
	addItem->year = randomyear();

	addItem->next = NULL;
	
	size++;
	if (last == NULL)
	{
		head = last = addItem;

	}
	else
	{
		last->next = addItem;
		last = addItem;
	}
	cout << "car added with vin" << vin << endl;
	return true;


}
void Bag::ListBag()
{
	Car *it = head;
	while (it != NULL)
	{
		cout << it->Vin << " ";
		it = it->next;
	}
	cout << endl;
}
unsigned short Bag::getSize()
{
	return size;
}
bool Bag::has(string str)
{
	Car *it = head;
	while (it != NULL)
	{
		if (it->Vin == str)
		{
			cout << endl;
			cout << "Vin :" << it->Vin<<endl;
			cout << "Owner :" << it->owner << endl;
			cout << "Price :" << it->price << endl;
			cout << "Year :" << it->year << endl;
			return true;
		}
		it = it->next;
	}
	cout << "There is no car with Vin: " << str << endl;
	return false;
}

void Bag::remove(string str)
{
	if (head == NULL)
	{
		cout << "the bag is empty";
		return;
	}
	Car *it = NULL, *tbd = NULL;
	if (head->Vin == str)
	{

		tbd = head;

		head = tbd->next;
		cout << endl << "removed : " << tbd->Vin<<" from the bag" << endl;
		size--;
		delete tbd;
		return;
	}
	it = head;
	tbd = head->next;

	while (tbd != NULL)
	{
		if (tbd->Vin == str)
		{
			it->next = tbd->next;
			if (tbd == last)
			{
				last = it;
			}
			cout << endl << "removed : " << tbd->Vin<<" from the bag" << endl;
			delete tbd;
			size--;
			break;
		}
		it = tbd;
		tbd = tbd->next;

	}
}

int main()
{
	Bag *bigBag=NULL;
	string str;
	int option = Menu();
	while(option != 9)
	{
		if (option == 1)
		{
			if (bigBag == NULL)
			{
				bigBag = new Bag();
			}
			else
			{
				cout << "bag is already created" << endl;
			}
		}
		else if (option == 2)
		{
			if (bigBag == NULL)
			{
				cout << "please create a bag first" << endl;
			}
			else
			{
				bigBag->addCar();
			}
		}
		else if (option == 3)
		{
			if (bigBag == NULL)
			{
				cout << "please create a bag first" << endl;
			}
			else
			{
				string st;
				cout << "enter the vin number to search" << endl;
				cout << "Vin :";
				cin >> st;
				bigBag->has(st);
			}
		}
		else if (option == 4)
		{
			if (bigBag == NULL)
			{
				cout << "please create a bag first" << endl;
			}
			else
			{
				string	vin;
				string st;
				cout << "enter the vin number to remove" << endl;
				cout << "Vin :";
				cin >> st;
				
				cout << endl;
				bigBag->remove(st);
			}
		}
		else if (option == 5)
		{
			if (bigBag == NULL)
			{
				cout << "please create a bag first" << endl;
			}
			else
			{
				bigBag->removelast();
			}
		}
		else if (option == 6)
		{
			if (bigBag == NULL)
			{
				cout << "please create a bag first" << endl;
			}
			else
			{
				bigBag->emptyBag();
			}
		}
		else if (option == 7)
		{
			if (bigBag == NULL)
			{
				cout << "please create a bag first" << endl;
			}
			else
			{
				cout <<"Number of cars in the bag : " <<bigBag->getSize() << endl;
			}
		}
		else if (option == 8)
		{
			if (bigBag == NULL)
			{
				cout << "please create a bag first" << endl;
			}
			else
			{
				bigBag->ListBag();
			}
		}
		else
		{
			break;
		}
		

		option = Menu();

	}
	
	cout << "thank you";
	
	cin.get();
	return 0;
}
int Menu()
{
	int option;
	cout << "1) Create a bag"<<endl;
	cout << "2) Add a car" << endl;
	cout << "3) search a car" << endl;
	cout << "4) remove a car" << endl;
	cout << "5) remove the last car" << endl;
	cout << "6) remove all cars from the bag" << endl;
	cout << "7) get the number of cars added" << endl;
	cout << "8) list all cars" << endl;
	cout << "9) exit" << endl;
	cin >> option;
	return option;
}

string generateVin()
{
	srand(time(0));
	string vin[15];
	string vin1;
	string VIN_TEMPLATE = "nlnlnlnnnnnnnnn";
	for (int i = 0; i<15; i++)
	{
		if (VIN_TEMPLATE[i] == 'n')
		{

			vin[i] = std::to_string(rand() % 10);
		}
		else
		{
			vin[i] = rand() % 26 + 65;
		}
	}
	for (int i = 0; i<15; i++)
	{
		vin1 = vin1 + vin[i] + "";
	}

	return vin1;
}
unsigned short randomyear()
{
	srand(time(0));
	unsigned short year;
	year = rand() % 118 + 1900;
	return year;
}
unsigned short randprice()
{
	srand(time(0));
	unsigned short price;
	price = rand() % 9999;
	return price;
}
string randowner()
{
	string s = "abcd";
	s[0]= rand() % 26 + 65;
	s[1]= rand() % 26 + 97;
	s[2]= rand() % 26 + 97;
	s[3]= rand() % 26 + 97;
	return s;
}

