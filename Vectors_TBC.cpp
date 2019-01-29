//
//  main.cpp
//  Sparse VectorProduct
//
//  Created by MM .
//  Copyright © 201* MM. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <stdlib.h>
//#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html


using namespace std;

const int SIZE = 1000;
// A struct to keep items
struct item
{
    unsigned int index;
    int data;
    item *next;
	item(unsigned int x, int d, item* t) { // constructor
		index = x;
		data = d;
		next = t;
	}
};

typedef item* link;

// Maintains index, data association for the vector. Indexes are kept ordered.
class Vector
{
public:
    Vector();                                   // Construction
    bool add(unsigned int index, int data);		// Adds a new item to vector
    void ListAll();                             // List all items of vector, starting with the first ITEM
	unsigned short getSize();						// returns the size of the vector
	Vector operator + (Vector&);				// like a function,  define a operator on this class
	link  getFirst(); 		// returns the pointer, "first"
	void ListNonZero();   // prints non-zero indexes with data
	Vector sum(Vector &);
private:
    link first;					// A pointer to show the first node
    link last;                     // A pointer to show the last node
    unsigned short size;			// how many items vector has
    unsigned short compSize;		// non-zero items vector has
};

// Initialize the class
Vector::Vector()
{
    first = last = NULL;
    size = 0 ;
}
unsigned short Vector::getSize()
{
		return size;
}
link  Vector::getFirst()
{
	return first;
}

void Vector::ListAll()                             // List all items of vector, starting with the first ITEM
{
    link it = first;
    int  cnt = 0;

    while (it != NULL ) {

        while (cnt < it->index)
        {
            cout  << cnt << ":0 " ;
            cnt++;
        }
        cout  <<  it->index << ":" <<  it->data << " ";
        it = it ->next;
        cnt++;
    }
    cout << endl;
}

void Vector::ListNonZero()                             // List all items of vector, starting with the first ITEM
{
	link it = first;

	while (it != NULL) {
		cout << it->index << ":" << it->data << " ";
		it = it->next;
	}
	cout << endl;
}


// WHY param is pass-by-reference, not pass-by-value
Vector Vector::operator+ (Vector &param) {   // https://en.wikibooks.org/wiki/C%2B%2B_Programming/Operators/Operator_Overloading
  Vector sumVector;
  if (size != param.size) cout << " Something is wrong ..." << endl;
  cout << " Same size vectors found, summing vectors items now..." << endl;
  link itA = first;
  link itB = param.getFirst();

	while (itA != NULL && itB != NULL )
	  {
		  if (itA->index < itB->index)
		  {
			  sumVector.add(itA->index, itA->data );
			  itA = itA->next;
		  }
		  else if (itA->index > itB->index)
			  {
					sumVector.add(itB->index, itB->data );
					itB= itB->next;
		      }
		  else
		  {
			  sumVector.add(itA->index, itB->data + itA->data  );
			  itA = itA-> next;
			  itB = itB-> next;
		  }
	  }
  return sumVector;
}

bool Vector::add(unsigned int index, int data)		// Adds a new item to Vector, to the end
{
    link Ptr = new item (index, data, NULL);			//  dynamically create a new struct/item
    if (Ptr == NULL) return false;  // not enought memory

    compSize++;  // non-zero items
	size=index+1;	// last index

    if (last == NULL) 					// first item to be added
    {
        first = last = Ptr;
    }
    else
    {
        last->next = Ptr;
        last = Ptr;
    }
    return true;	// added.
}

int main(int argc, const char * argv[])
{
    Vector A,B, SumVector;
    int locA = 0, locB = 0 ;
    int data = 0;
    for (int i=0; i< 10; i++) // adds 20 items.
        {
            locA = locA + rand() % 3 + 1;
            data = rand() % 50 + 30;
            A.add(locA, data);

			locB = locB + rand() % 3 + 1;
            data = rand() % 50 + 30;
            B.add(locB, data);
        }

	A.add(locA+1, 0); // should be same size, therefore we are adding locA+1
	B.add(locA+1, 0); // should be same size, therefore we are adding locA+1

    A.ListAll(); //cout << A.getSize() << " items found..." << endl;
	B.ListAll(); //cout << B.getSize() << " items found..." << endl;
	SumVector = A + B;

	SumVector.ListAll(); cout << SumVector.getSize() << " items found..." << endl;
	SumVector.ListNonZero(); cout << SumVector.getSize() << " items found..." << endl;
}


// Practice Work: Define "*" operator to multiple two vectors.
