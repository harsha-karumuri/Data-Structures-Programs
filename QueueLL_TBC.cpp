// Mutlu Mete, Feb 14, 2017
// Queue implementation using linked list, A dynamic data container
// CSCI 520 

// FIFO structure

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
//#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html

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

// A class to represent Queue, where we enqueue and dequeue items.
// The items (strings) are not sorted in the list.
class Queue {
public:
    Queue();						// Construction
    bool enqueue(string str);		// Adds a new item to Queue
    bool dequeue ();				// remove the first item (the least recently added item)
    bool isEmpty ();				// check if we have any item added.
    void takeOut (string str);		// delete an arbitrar item in the queue, Not so common
    void ListAll();					// List all items of Queue, starting with the first ITEM
    bool has(string str);			// Check if Queue has this item
    string top();                   // Return (do not removed) the item on the end, the most recently 'enqueue'ed
    string bottom();                // Return the item at the bottom, the least recently 'enqueue'ed
    unsigned short getSize();		// How many items  he Queue has
private:
    link first;					// A pointer to show the first node, the one will be dequeued
    link last;                     // A pointer to show the last node
    unsigned short size;			// how many items Queue has
};

// Initialize the class
Queue::Queue() {
    size = 0;
    first = last = NULL;
    cout << "A queue was created...!" << endl ;
}
// How many items the Stack has
unsigned short Queue::getSize () 
{
    return size;
}

void Queue::takeOut(string str) {
    link it  = NULL;
    link prev = NULL;
	if (first == NULL) 
	return;
	
    it = first; 
    while (it != NULL) {
        if (it->data == str ) { // found, delete now
            if (it == first)    // first item of queue is being taken out
                first = first->next;
            else
                prev->next = it->next;
            delete it;
            size--;				//  update the size
            break;
        }
        prev=it;
        it = it->next;
    }        
}

bool Queue::enqueue(string str) {			// Adds a new item to Queue
    
	link  NewItemPtr = new item(str, NULL);//  dynamically create a new struct/item
		
    if ( NewItemPtr == NULL) return false;  // not enought memory
      
    if ( first == NULL) {				// first item to be added
        first = last = NewItemPtr;
    } else {
        last->next = NewItemPtr;
        last=NewItemPtr;
    }
	size++;				//  update the size
    return true;	//  added.
}

bool Queue::dequeue () {			// remove the first item (the least recently added item)
    if ( first == NULL ) { 			// Check if there is an item in the queue
        return false;
    } else {
        link FirstItemPtr = first;
        first = first->next;
        delete FirstItemPtr;
        size--;				//  update the size
        return true;
    }
    // if(first==NULL) last=NULL;       Optional!!
	// Question: What happens to "last" pointer if last item is dequeued.
}

bool Queue::isEmpty() {		// check if we have any item added.
    if (size == 0 ) return true;	
    return false;
	
	 // alternatively if (! ?? )
	 
}
void Queue::ListAll() {			// List all items of Queue, starting with the first ITEM
    link it = first;
	cout << size << ": ";
    while (it != NULL) {
        cout << it->data << "   ";
        it = it->next;
    }
    cout << endl;
}

bool Queue::has(string str) {		// Check if Queue has this item
    link it = first;
    for (int i=0; i < size; i++) {
        if (it->data == str) return true;
        it = it ->next;
    }
    return false;
}

string Queue::top() {   // Return the item on the end, the most recently 'enqueue'ed
    if (last == NULL)  return " ";
    return last->data;
}

string Queue::bottom() {   // Return the item on the end, the least recently 'enqueue'ed
    if (first == NULL)  return " ";
    return first->data;
}

int main(int argc, const char * argv[]) {

    Queue Q;
    string tempStr;
	char sel = ' ';
	while (sel != 'x')
	{
		cout << "(e)nQ, (d)eQ, (s)earch, (t)akeout e(x)it:   ";
		cin >> sel;
		switch(sel)
		{
			case 'e':
					cout << "\nString to be EnQueued:";
					cin >> tempStr;
					Q.enqueue(tempStr);
					Q.ListAll();
					break;
			case 'd':					
					Q.dequeue();
					Q.ListAll();	
					break;
			case 's':
					cout << "\nString to be searched: ";
				    cin >> tempStr;        
					cout << Q.has(tempStr) << endl;					
					break;
			case 't':
					cout << "\nString to be taken out: ";
				    cin >> tempStr;        
					Q.takeOut(tempStr);	
					Q.ListAll();					
					break;
			default:			
					break;
		}
	}
	
}
