//
//  main.cpp
//  Temp.cpp
//
//  Created by MM on 10/20/16.
//  Copyright © 2016 MM. All rights reserved.
//
// Mutlu Mete, Sep 15, 2016
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
};

// A class to represent Bag, which can hold and strings in an linked list
// The items (strings) are not sorted in the list initially
// Then we call sort function and make it sorted.
class Bag
{
public:
    Bag();							// Construction
    bool add (string str);			// Adds a str to unsorted bag
    string has (string str);		// Check if Bag has this item
    unsigned short getCapacity ();	// get the capacity of the Bag. Is there any capacity
    void ListBag();					// List all items of Bag.
    void sort();					// Checks the bag if sorted. If not, sort the bag items with selection sort algorithm
    unsigned short getSize();		// How many items  the Bag has
    bool small(int j, int min);		// Check if ith node less than jth item
    void swap(int k, int min);		// Swaps kth and minth data in the bag
    void insert(string str);		// Adds a str to sorted bag
    bool sorted;
    
private:
    item *first;						// A pointer to show the first node
    item *last;						// A pointer to show the last node
    unsigned short size;			// how many items Bag has
};

// Initialize the class
Bag::Bag()
{
    size = 0;
    sorted = false;
    first = NULL; // At the beginning both, first and last are null
    last = NULL;
    cout << "A new bag with  " <<  getCapacity()  << " was created...!" << endl ;
}

bool Bag::add(string str)	//  Add item at the end, since the bag/list is not sorted
{
    item *AddItem = new item;			//  dynamically create a new struct/item
    if ( AddItem == NULL) return false; // not enought memory
    
    AddItem->data = str;  				// we append, add to end of list
    AddItem->next = NULL;
    size++;
    if ( last == NULL) 					// first item to be added
    {        first = last = AddItem;    }
    else
    {   last->next = AddItem;     last = AddItem;    }
    return true;	// Yeah, added.
}

// List, print out, all items in the arrays
// make 5 coloumns
void Bag::ListBag()
{
    if (sorted) cout << "\nSorted\n";
    item *it = first;   // it means iterator, visit all items one by one.
    int i=0;
    while (it != NULL) {
        cout << it->data << "   ";
        it = it->next;
        if ( (i+1)%10 == 0) cout << endl;
        i++;
    }
}

void Bag::sort()	// Checks the bag if sorted. If not, sort the bag items with selection sort algorithm
{
    if (sorted) return; // already sorted
    
    // Selection sort
    for (int i = 0; i < size; i++)
    { 								// Swap node[i] with smallest entry in a[i+1...N).
        int min = i; 				// index of minimal entr.
        for (int j = i+1; j < size; j++)
        {
            if ( small(j, min) == true) min = j;
        }
        swap(i, min); //  we make a one swap in each iteration
    }
    sorted=true;
}

// keep in mind that k <= min, or min >= k. Both k and min are indexes
void Bag::swap(int k, int min)
{
    item *it = first;   // it means iterator, visit all items one by one.
    item *temp = NULL;   // it means iterator, visit all items one by one.
    int i=0;
    string tmp;
    while (it != NULL) {
        if (i == k) temp=it;
        if (i == min)
        {
            tmp = temp->data;
            temp->data = it->data;
            it->data = tmp;
            return;
        }
        it = it->next;
        i++;
    }
    cout << "Sth wrong! ! in function swap, for "  << k << "end" << min <<endl; // this line should not be executed. Why?
}

// keep in mind that j > min, or min < j. Both j and min are indexes
bool Bag::small(int j, int min)
{
    item *it = first;   // it means iterator, visit all items one by one.
    int i=0;
    string min_data;
    string j_data;
    while (it != NULL) {
        if (i == min) min_data=it->data;
        else if (i == j)
        {
            j_data=it->data;
            if (j_data < min_data)
                return true;
            else
                return false;
        }
        it = it->next;
        i++;
    }
    cout << "Sth wrong! in function small" << endl; // this line should not be executed. Why?
    return false;
}

// How many items the Bag has
unsigned short Bag::getSize ()
{
    return size;
    //while (it != NULL) {       it++;       it = it->next;    }
}
// Check if the bag has item "str"
// You can return bool too
string Bag::has(string str)
{
    last = first;
    for (int i=0; i < size; i++)
    {
        if (last->data == str) return "YES";
        last = last->next;
    }
    return "NO";
}

void Bag::insert(string str) // Adds a str to sorted bag
{
    // we need to find there to add str. Since the bag is sorted, we will use binary search, not sequential search
    // A binary search on linked list is NOT a good idea, becuase of finding items should be carried out with iterators
    // So finding a middle is done by sequential search. Yes, it is unfortunately, but true.
    // Finding middle of list takes O(n/2)
    // So, let's do sequentail search and insert
    
    item *AddItem = new item;			//  dynamically create a new struct/item
    if ( AddItem == NULL) return; // not enought memory
    
    AddItem->data = str;  				// we append, add to end of list
    AddItem->next = NULL;
    size++;
    
    item *it = first;   // it means iterator, visit all items one by one.
    int i=0;
    while (it != NULL) {
        if (i == 0) // compare with the first
        {
            if (str < it->data || it->data == str  ) // str will be first node, added to the left
            {
                AddItem->next = first;
                first = AddItem;
                return;
            }
            else if (it->next == NULL )  // there is only one node in the bag, and str will be added at the end
            {
                first->next= AddItem;
                last=AddItem;
                return;
            }
            else if (it->next->data > str ) // Add str just after first
            {
                AddItem->next =  it->next;
                it->next= AddItem;
                return;
            }
        }
        else
        {
            if (it->next != NULL)
            {
                if (it->next->data > str) // add here, in the middle
                {
                    AddItem->next =  it->next;
                    it->next= AddItem;
                    return;
                }
            }
            else // last will be str, since it->next == NULL
            {
                last->next = AddItem;
                last = AddItem;
                return;
            }
        }
        it = it->next;
        i++;
    }
}

unsigned short Bag::getCapacity ()
{
    return 30000; // A made-up number.
}

string RandomStr();  // A function to randomly generate 10  chars strings.

int main(int argc, const char * argv[]) {
    Bag Strbag;
    string AddMe;
    for (int i=0; i< 50; i++) { // Add 100 items.
        AddMe=RandomStr();
        if (Strbag.sorted)
            Strbag.insert (AddMe);
        else
            if ( Strbag.add (AddMe) == false) cout << "problem while adding\n";
        cout << ".";
    }
    cout << endl;
    Strbag.ListBag();
    Strbag.sort();
    Strbag.ListBag();
    
    for (int i=0; i< 50; i++) { // Add 100 items.
        AddMe=RandomStr();
        if (Strbag.sorted)
            Strbag.insert (AddMe);
        else
            if ( Strbag.add (AddMe) == false) cout << "problem while adding\n";
        cout << ".";
    }
    Strbag.ListBag();
    
    while (true) // a loop to search strings. "exit" exits the program
    {
        cout << "\n\nCheck a  string: ";
        string Checkme;
        cin >> Checkme;
        if (Checkme == "exit") break;
        cout << Strbag.has(Checkme) << endl;
    }
}

string RandomStr()
{
    string AddMe="01-3"; // A string example  we will randomle generate
    for (int j=0; j < 4; j++)
    {
        if (j== 0 || j== 1 )
            AddMe[j]=rand() % 10 + 48;
        else if (j == 2)
            AddMe[j]= '-';
        else AddMe[j]=rand() % 60 + 65;
    }
    return AddMe;
}
