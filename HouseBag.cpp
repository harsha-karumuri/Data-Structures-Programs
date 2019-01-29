// SRI HARSHA KARUMURI  - MAR 07, 2018

// CWID: 50201598

// Compiler: Visual Studio, GNU C++, etc.

// HOMEWORK Assignment Bags.... 

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

using namespace std;

// A struct to keep items of house
struct house  
{
    long int price;
    enum color {red=1, blue, white, black, gray, green, yellow};         //color of enum type
    string ID;                   //positive whole number, 10 chars, should have three A-to-Z chars.
    int year;                    // between 1910-2017
    string owner;                // one string which starts with capital and rest are small
    house *next;                 // pointer to maintain linked list 
    string color;                // take the value from enum Color
    
    house(float a, string b, string c, unsigned short d, string e, house* f)
    {
    	price=a; color=b; ID=c; year=d; owner=e; next=f;
	}

};

typedef house * link;

float randomprice();              // to generate random price
unsigned short randomyear();      // to generate random year
string randowner();               // to generate random owner
string randomid();                // to generate random id

float randomprice()
{

	float pri;
    pri = (float(1000.00 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(999999.99-1000.0)))));
	return pri;
}

unsigned short randomyear()
{

	float yr;
	yr = rand() % (2017 - 1910) + 1910;
	return yr;
}

string randowner()
{

	string s = "abcdefgh";
	s[0]= rand() % 26 + 65;
	s[1]= rand() % 26 + 97;
	s[2]= rand() % 26 + 97;
	s[3]= rand() % 26 + 97;
	s[4]= rand() % 26 + 97;
	s[5]= rand() % 26 + 97;
	s[6]= rand() % 26 + 97;
	s[7]= rand() % 26 + 97;
	return s;
}

string randomid()
{

	string str="";

		str+=rand() % 26 + 65;
		str+=rand() % 26 + 65;
		str+=rand() % 26 + 65;
	 	str+=std::to_string(rand() % 10);
	 	str+=std::to_string(rand() % 10);
	 	str+=std::to_string(rand() % 10);
	 	str+=std::to_string(rand() % 10);
	 	str+=std::to_string(rand() % 10);
	 	str+=std::to_string(rand() % 10);
	 	str+=std::to_string(rand() % 10);

return str;
}

class Bag
{
public:
    Bag();						            	// Construction
    bool Add ();   		                        // Adds a new house to bag
    bool SearchHouseWithID (string ID);			// Check if Bag has this item
	bool ListIdByColor (string clr);            // Lisy ID by Color
	bool ListIdByOwner (string owner);          // Lisy ID by Owner
    bool RemoveHouse(string ID);                // Remove house by ID
    bool RemoveAllHouses();                     // Remove all houses
    bool RemoveLastHouse();                     // Remove last house
    unsigned short GetNoOfHouses();             // Get number of houses

private:
    link head;					              	// A pointer to show the first node
    link last;					              	// A pointer to show the last node
    unsigned short size;	            		// how many items Bag has
};

Bag::Bag() // Initialize an instance of the class
{
    size = 0;
    head= last= NULL; // At the beginning both, head and last are null
    cout << "A new bag was created...!" << endl ;
}


bool Bag::Add()  //float a, string b, string c, unsigned short d, string e
{
	string b;

	enum color{red, blue, white, black, gray, green, yellow};
	int r= rand()%7;
	if(r==red) b="red";                           // Checks value from enum and stores in string
	if(r==blue) b="blue";
	if(r==white) b="white";
	if(r==black) b="black";
	if(r==gray) b="gray";
	if(r==green) b="green";
	if(r==yellow) b="yellow";


    float a=randomprice();
	unsigned short d=randomyear();
	string e=randowner();
	string c=randomid();

	link AddHouse = new house(a,b,c,d,e,NULL);
	if ( AddHouse == NULL) return false; 	         	// not enought memory

	if ( last == NULL )  head= AddHouse;				// first item to be added
    else last->next = AddHouse;			                // add to the end of array

    last = AddHouse;	                                // last = last -> next;
	size++;
	cout<<endl<<" price:"<<a<<" color:"<<b<<" ID:"<<c<<" year:"<<d<<" owner:"<<e<<endl;
    return true;                                     	// Yeah, added.


}

bool Bag::SearchHouseWithID(string str)
{
    link it = head;
    for (int i=0; i < size; i++)
    {
        if ( it->ID == str) return true;
        it = it->next;
    }
    return false;
}

bool Bag::ListIdByColor(string clr)
{
    link it = head;   // it means iterator, visit all items one by one.
    int i=0;
    while (it != NULL)
	{
    	if(it->color == clr)
    	{
        cout << it->ID << "   ";
        if ( (i+1)%5 == 0) cout << endl;   // this is just to maintain 5 items per line 
		i++;
        }
        it = it -> next;
        
        
    }
	cout << endl;
	return 1;
}

bool Bag::ListIdByOwner(string str)
{
    link it = head;   // it means iterator, visit all items one by one.

    while (it != NULL)
	{
		if(it->owner == str)
		{
        cout <<"ID: "<< it->ID << "   ";
		}
        it = it -> next;
    }
	cout << endl;
	return 1;
}

bool Bag::RemoveHouse(string str)
{
    link back;
	link front;
	if (head == NULL) return false;
	back = front = head;

	if(head->ID == str) // delete this
	{
		if (head == last) // there is only one item, which will be deleted
			head = last = NULL;
		else
			head = head->next;	// first of many items is being deleted
		delete front;
		size--;
		return true;
	}

	front = front->next;	// if reach this line, the first item of bag is not being deleted.

	while (front != NULL)
	{
		if (front->ID == str)
		{
			back->next = front->next;	// a mid-item is being deleted. By-pass the (front)
			if (front == last) last = back; // the last item is being deleted
			delete front;
			size--;
			return true;
		}
		back = front ;
		front = front -> next;
    }
	return	false; // if reach this line, item is not found in the list.
}

bool Bag::RemoveLastHouse()
{
    link back;
	link front;
	if (head == NULL) return false;
	back = front = head;

	if (head == last) // there is only one item, which will be deleted
	{
		head = last = NULL;
		delete front;
		size--;
		return true;
	}
	else
	{
		head = head->next;	// first of many items is being deleted
		delete front;
		size--;
		return true;
	}

	front = front->next;

	while(front != NULL)
	{
	back->next = front->next;
	if(front==last)
	{
	last=back;
	delete front;
	size--;
	return true;
	}
	}
}

bool Bag::RemoveAllHouses()
{
    while(head != NULL)
    {
	    RemoveLastHouse();
	}
    return true;
}

unsigned short Bag::GetNoOfHouses()
{
	return size;
}

int main()
{
    Bag b;
	string tempStr,ii,oo,rr,z;
	int cc;
	int sel=0;
	while (sel != 10)
	{
		cout <<endl;
		cout<<"-----------------------------\n";
	    cout<< " 1- add_house \n 2- search_with_ID \n 3- list_id_by_color \n 4- list_id_by_owner \n 5- remove_house_by_ID \n 6- remove_last_house \n 7- remove_all_houses \n 8- get_no_of_houses \n 9- add_1000_houses \n 10- exit  \n ";
	    cout<<"-----------------------------\n";
	    cout<<"option: ";
	    cin >> sel;
	    
		switch(sel)
		{
			case 1:
				   	b.Add();
					break;
			case 2:
		
				    cout<<"Search house with ID: ";
				    cin>>ii;
				    if(b.SearchHouseWithID(ii))
					cout<<"House is available with ID "<<ii<<"!!"<<endl;
					else
					cout<<"Sorry!! House is not available with ID "<<ii<<"!!"<<endl;
				    cout<<endl;
					break;
			case 3:
		
				    cout<<"List ID by color: ";
				    cout<<"\n 1-red, 2-blue, 3-white, 4-black, 5-gray, 6-green, 7-yellow : ";
				    cin>>cc;
			    	enum color{red=1, blue, white, black, gray, green, yellow};
	
                  	if(cc==red) z="red";                           // Checks value from enum and stores in string
                	if(cc==blue) z="blue";
	            	if(cc==white) z="white";
	            	if(cc==black) z="black";
	            	if(cc==gray) z="gray";
	            	if(cc==green) z="green";
	            	if(cc==yellow) z="yellow";
	            	
					b.ListIdByColor(z);
					break;
				    
			case 4:
				  
				    cout<<"List ID by owner: ";
				    cin>>oo;
				    b.ListIdByOwner(oo);
				    break;
			case 5:
              
				    cout<<"Remove house by id: ";
				    cin>>rr;
				    cout<<b.RemoveHouse(rr);
					break;
			case 6:
				    cout<<b.RemoveLastHouse();
				    break;

			case 7:
			        cout<<b.RemoveAllHouses();
					break;

			case 8:
			        cout<<b.GetNoOfHouses();
					break;
            case 9:
				    for(int i=0;i<1000;i++)
		            b.Add();
				    break;

			default:
					break;
		}
	}
}

