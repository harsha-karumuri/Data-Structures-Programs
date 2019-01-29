// Mutlu Mete, Feb 10, 2017
// Stack implementation using A dynamic data container (Not linked List)
// CSCI 520 
// http://jcsites.juniata.edu/faculty/kruse/cs240/stackapps.htm
// https://www.quora.com/What-are-some-real-world-applications-of-a-stack-data-structure

// Reverse a work using a stack

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html

using namespace std;

// A class to represent Stack, where we push and pop items.
// The items (strings) are not sorted in the list.
class Stack
{
public:
	Stack(int n);				// Construction
	void push(char ch);			// Adds a new item to stack
	char pop();					// remove the head guy (the most recently added item)
	bool isEmpty();				// check if we have any item added.
	void reverse();					// List all items of stack.    
	unsigned short getSize();		// How many items  the stack has
private:
	char *word;						// A pointer to show the head node
	unsigned short size;			// how many items stack has
};

// Initialize the class
Stack::Stack(int n)
{
	size = 0;
	word = new char[n];
}
// How many items the Stack has
unsigned short Stack::getSize()
{
	return size;
}
// add an item as the head one in the stack
void Stack::push(char ch)
{
	word[ size++ ] = ch;
}
char Stack::pop()
{
	return word[--size];
}
void Stack::reverse()
{
	while (size > 0) 
		cout << pop() << ", ";
}
bool Stack::isEmpty()
{
	return size;
}

int main(int argc, const char * argv[]) {

	Stack S(30);
	string tempStr;
	cout << "Enter a string:";
	cin >> tempStr;

	for (int i = 0; i < tempStr.length(); i++)
		S.push(tempStr[i]);
	S.reverse();
}


// Assg:  Randomly Generate a maze with in 15x15 grid and solve with stacks




