// Bag implementation using linked list, A dynamic data container
// CSCI 520 F16

//

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
	item(string x, item* t) { // constructor	
		data = x; next = t;
	}
};

typedef item * link;

// A class to represent Bag, which can hold and strings in an linked list
// The items (strings) are not sorted in the list.
class Bag
{
public:
    Bag();							// Construction
    bool add (string str);			// Adds a new item to bag
    bool has (string str);			// Check if Bag has this item
	bool remove (string str);		// Delete the str from the bag
    unsigned short getCapacity ();	// get the capacity of the Bag. Is there any capacity
    void ListBag();					// List all items of Bag.
    unsigned short getSize();		// How many items  the Bag has
private:
    link head;						// A pointer to show the first node
    link last;						// A pointer to show the last node
    unsigned short size;			// how many items Bag has
};
Bag::Bag() // Initialize an instance of the class
{
    size = 0;
    head= last= NULL; // At the beginning both, head and last are null    
    cout << "A new bag with  " <<  getCapacity()  << " was created...!" << endl ;
}

bool Bag::add(string str)
{
	int count=0;
	link it = head;
    for (int i=0; i < size; i++)
    {
        if ( it->data == str) count++;
        it = it->next;
    }
    
    if(count==3) return false;
    
    link AddItem = new item(str,NULL);			//  dynamically create a new struct/item
    if ( AddItem == NULL) return false; 		// not enought memory

    if ( last == NULL )  head= AddItem;				// first item to be added        
    else last->next = AddItem;			// add to the end of array
	
    last = AddItem;	  // last = last -> next;
	size++;
    return true;	// Yeah, added.
}

bool Bag::remove(string str)		// Delete the str from the bag
{
	link back;
	link front;
	if (head == NULL) return false;
	back = front = head;
	
	if(head->data == str) // delete this
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
		if (front->data == str) 
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

void Bag::ListBag()	// List, print out, all items in the arrays, // make 5 coloumns
{
	cout << size << ": " ;
    link it = head;   // it means iterator, visit all items one by one.
	int i=0;  			// i is used to format the outpur
    while (it != NULL) {
        cout << it->data << "   ";
        it = it -> next;
        
		if ( (i+1)%5 == 0) cout << endl;   // this is just to maintain 5 items per line 
		i++;
    }
	cout << endl;
}
// How many items the Bag has
unsigned short Bag::getSize ()
{
    return size;    
}

bool Bag::has(string str)   // Check if the bag has item "str", // You can return bool too
{
    link it = head;
    for (int i=0; i < size; i++)
    {
        if ( it->data == str) return true;
        it = it->next;
    }
    return false;
}

unsigned short Bag::getCapacity ()
{
    return 30000; // A made-up number.
}

int main(int argc, const char * argv[]) {
    Bag bigBag;
	string tempStr;
	char sel = ' ';
	while (sel != 'e')
	{
		cout << "(i)nsert, (d)elete, (s)earch, (e)xit:   ";
		cin >> sel;
		switch(sel)
		{
			case 'i':
					cout << "\nString to be inserted:";
					cin >> tempStr;
					bigBag.add (tempStr);
					bigBag.ListBag();
					break;
			case 'd':
					cout << "\nString to be deleted: ";
				    cin >> tempStr;        
					bigBag.remove(tempStr);
					bigBag.ListBag();	
					break;
			case 's':
					cout << "\nString to be searched: ";
				    cin >> tempStr;        
					cout << bigBag.has(tempStr) << endl;					
					break;
			default:			
					break;
		}
	}
	
}


