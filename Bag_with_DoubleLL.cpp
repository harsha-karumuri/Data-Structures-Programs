// Mutlu Mete, Oct 12, 2016
// Bag implementation using double linked list, A dynamic data container
// CSCI 520 F16

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

// A struct to keep items
struct item
{
    string data;
    item *next;
	item *pre;
};

// A class to represent Bag, which can hold and strings in an linked list
// The items (strings) are not sorted in the list.
class Bag
{
public:
    Bag();							// Construction
    bool add (string str);			// Adds a new item to bag
	bool del(string str);			// Deletes the first occurance of item "str" 
    string has (string str);		// Check if Bag has this item
    unsigned short getCapacity ();	// get the capacity of the Bag. Is there any capacity
    void List();					// List all items of Bag.
	void ListReverse();				// List all items of Bag in reverse order.
    unsigned short getSize();		// How many items  the Bag has
private:
    item *head;						// A pointer to show the first node
    item *last;						// A pointer to show the last node
    unsigned short size;			// how many items Bag has
};

// Initialize the class
Bag::Bag()
{
    size = 0;
    head = NULL; // At the beginning both, head and last are null
    last = NULL;
    cout << "A new bag with  " <<  getCapacity()  << " was created...!" << endl ;
}


bool Bag::add(string str)
{
    item *AddItem = new item;			//  dynamically create a new struct/item
    if ( AddItem == NULL) return false; //  not enought memory, insufficient right,  or some other problem, 

    AddItem->data = str;  				// we append, add to end of list
    AddItem->next = NULL;
	AddItem->pre = NULL;
    size++;

    if ( last == NULL) 					// first item to be added
    {
        head = last = AddItem;
    }
    else
    {
        last->next = AddItem;
		AddItem->pre = last;
        last = AddItem;
    }	
    return true;	// Added.
}

bool Bag::del(string str) // Remember three cases, deleting 1) the first, 2) a middle 3) the last node
{
	item *it  = NULL; 	
	it = head;
	bool found = false;
    
    while (it != NULL) {  // meaning that, if at least one item in the list, or it == NULL, nothing to do
        if (it->data == str ) // found, delete now
		{
			if (it == head) // there is at least one node, the first node will be deleted
			{
				head = head->next; 
				if( head->next != NULL) // there is at least two nodes				
					head->pre = NULL;				
				// else // there is only one node
			}	
			else // not  "the first" node, maybe middle or last #2 or #3
				it->pre->next = it->next;
				if (it->next != NULL)  // #2
				{
					it->next->pre = it->pre;
				}
				else // #3, the last, update last. There is nothing on the right side of last node.
				{
					last = it->pre;
				}
			delete it;
			found = true;
			break;
		}
		else  it = it->next;
    }
	
	if (found) 
	{
		cout <<  str << " deleted...." <<endl;
		return true;
	}
	  else  
	  { 		
		cout <<  str << " could not deleted.." <<endl;	
		return false;
	  }    
	
}

// List, print out, all items in the arrays
// make 5 coloumns
void Bag::List()
{    
    item *it = head;   // it means iterator, visit all items one by one.
	
	int i=0; 			// just for the formatting
    while (it != NULL) {
        cout << it->data << "   ";
        it = it->next;
		if ( (i+1)%5 == 0) cout << endl;
		i++; 
    }
}

// List, print out, all items in the arrays
// make 5 coloumns

void Bag::ListReverse()
{    
    item *it = last;   // it means iterator, visit all items one by one.
	
	int i=0; 			// just for the formatting
    while (it != NULL) {
        cout << it->data << "   ";
        it = it->pre;
		if ( (i+1)%5 == 0) cout << endl;
		i++; 
    }
}

unsigned short Bag::getCapacity ()
{
    return 30000; // A made-up number.
}

// Check if the bag has item "str"
// You can return bool too
string Bag::has(string str)
{
    last = head;
    for (int i=0; i < size; i++)
    {
        if (last->data == str) return "YES";
        last = last->next;
    }
    return "NO";
}

string RandomStr();  // A function to randomly generate 10  chars strings.

int main(int argc, const char * argv[]) {

    Bag bigBag;   
    string AddMe;
    for (int i=0; i< 20; i++) { // Add 100 items.
        AddMe=RandomStr();
        if ( bigBag.add (AddMe) == false) cout << "problem\n";
        cout << "."; 
    }
    cout << endl;    		  bigBag.List();
	cout << endl << endl;     bigBag.ListReverse();
    while (true) // a loop to search strings. "exit" exits the program
    {
        cout << "\n\nCheck a  string: ";
        string Checkme;
        cin >> Checkme;
        if (Checkme == "exit") break;
        cout << bigBag.has(Checkme) << endl;
    }
	 while (true) // a loop to search strings. "exit" exits the program
    {
        cout << "\n\nDelete a  string: ";
        string Checkme;
        cin >> Checkme;
        if (Checkme == "exit") break;
        cout << bigBag.del(Checkme) << endl;
		cout << endl;    		 bigBag.List();
		cout << endl << endl;    bigBag.ListReverse();
    }	
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
