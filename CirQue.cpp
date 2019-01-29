
// SRI HARSHA KARUMURI  - Feb 26, 2016

// CWID: 50201598

// Compiler: Visual Studio, GNU C++, MinGW etc.

// Lab Assignment: S18-L-3

 

// This program is works as a bank with 2 tellers.. 
//It has many functions like entering into the queue.. coming out of the queue.. List the values in the queue..

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h> 

using namespace std;
#define MAX 10

class CQue
{
public:
    CQue();  // Init Circular Queue with fix int items
    bool isFull1();
    bool isFull2();
    bool isEmpty1();
    bool isEmpty2();
    int countQ1();
    int countQ2();
    void enqueue1(unsigned short item);
    void enqueue2(unsigned short item);
    void show1();
    void show2();
    unsigned short dequeue1(); 
    unsigned short dequeue2();
private:
    int first1;
    int first2;
    int last1;
    int last2;
    int count1, count2;
    int que1[MAX];
    int que2[MAX];
  };

CQue::CQue() //Initalize Circular Queue
{
    first1 = first2 = last1 = last2 = count1 = count2 = 0;
}

bool CQue::isFull1() //To check queue1 is full or not
{
    if( count1 == MAX )
        return true;
    else
        return false;
}

int CQue::countQ1()  // returns the count of the queue1
{
	return count1;
}

int CQue::countQ2()  // returns the count of queue2
{
	return count2;
}

bool CQue::isFull2() //To check queue2 is full or not
{
    if( count2 == MAX )
        return true;
    else
        return false;
}

void CQue::show1()  // Show the Circular Queue items of queue1.
{
    cout<<endl<< count1 << " Customer(s) found in Queue 1 --> ";
    int ind = first1;
    for (int i = 1; i <= count1 ; i++, ind = (ind+1) % MAX)
        cout << que1[ind] << " ";
    cout << endl;
}

void CQue::show2()  // Show the Circular Queue items of queue2.
{
    cout <<endl<< count2 << " Customer(s) found in Queue 2 --> ";
    int ind = first2;
    for (int i = 1; i <= count2 ; i++, ind = (ind+1) % MAX)
        cout << que2[ind] << " ";
    cout << endl;
}

void CQue::enqueue1(unsigned short item) //Insert item into circular queue1.. makes sure that entered customer id is not in the queue.. and checks queue overflow!!
{
    if( isFull1() )
    {
        cout<<"\n Queue Overflow!! Maximum 10 per queue!!\n";
        return;
    }
    
    for(int i=0; i<count1 ; i++)
    	if(que1[i]==item)
		{
			cout<<endl<<"Please re-enter valid customer id!! We already have that customer in queue 1 !! "<<endl;
			return;
	    }

	
	for(int i=0; i<count2 ; i++)
    	if(que2[i]==item)
    	{
    	    cout<<endl<<"Please re-enter valid customer id!! We already have that customer in queue 2 !! "<<endl;
    	    return;
    	}
    
    que1[last1] = item;
    last1= (last1+1) % MAX;  // iterate to next location
    count1++;
}

void CQue::enqueue2(unsigned short item) //Insert item into circular queue.. makes sure that entered customer id is not in the queue.. and checks overflow as well..
{
    if( isFull2() )
    {
        cout<<"\n Queue Overflow!! Maximum 10 per queue!!\n";
        return;
    }
	
	for(int i=0; i<count1 ; i++)
    	if(que1[i]==item)
		{
		    cout<<endl<<"Please re-enter valid customer id!! We already have that customer in queue 1 !! "<<endl;
	        return;
		}

	
	for(int i=0; i<count2 ; i++)
    	if(que2[i]==item)
		{
    		cout<<endl<<"Please re-enter valid customer id!! We already have that customer in queue 2 !! "<<endl;
    		return;
    	}
    
    que2[last2] = item;
    last2= (last2+1) % MAX;  // iterate to next location
    count2++;
}

bool CQue::isEmpty1()  // check if queue1 is empty or not
{
    if( count1 == 0 )
        return true;
    else
        return false;
}

bool CQue::isEmpty2()  // check if queue2 is empty or not
{
    if( count2 == 0 )
        return true;
    else
        return false;
}

unsigned short CQue::dequeue1() //delete item from first in queue1 and return
{
    if( isEmpty1() )
    {
        cout<<"\nEmpty Queue...\n";
        return -1;
    }
    unsigned short item = que1[first1];
    first1 = (first1+1) % MAX; // iterate to next one
    count1--;
    return item;
}

unsigned short CQue::dequeue2() //delete item from first in queue2 and return
{
    if( isEmpty2() )
    {
        cout<<"\nEmpty Queue...\n";
        return -1;
    }
    unsigned short item = que2[first2];
    first2 = (first2+1) % MAX; // iterate to next one
    count2--;
    return item;
}

int main()
{
    CQue CQ = CQue();
    int sel=0,a,b,c;
    unsigned short CustId;
    
    while(sel!=4)
    {
    cout<<"Choose one: 1) List queued customers , 2) enqueue 3) dequeue 4) exit : ";
    cin>>sel;
    
    if(sel==1)
    {
    	cout<<endl<<" Which queue do you want to see: 1) first 2) second : ";
    	cin>>a;
    	if(a==1)
    	CQ.show1();
    	if(a==2)
    	CQ.show2();
    	cout<<endl;
	}
	
	if(sel==2)
	{
		cout<<endl<<"To which queue do you want to get in?"<<endl<<endl;
		cout<<"Queue1 count : "<<CQ.countQ1()<<"   Queue2 count : "<<CQ.countQ2()<<"  (Enter 1 or 2 to select queue) : ";
		cin>>b;
		cout<<endl<<"Please enter the 2 digit Customer Id: ";
		cin>>CustId;
		if(CustId>0 && CustId<100)
		{
		if(b==1)
		CQ.enqueue1(CustId);
		if(b==2)
		CQ.enqueue2(CustId);
		cout<<endl;
	    }
	    else
	    cout<<"\nPlease enter valid 2 digit Customer ID!!\n\n";
	}
	
    if(sel==3)
    {
    	cout<<endl<<"Dequeue from queue number 1 or 2: ";
    	cin>>c;
    	if(c==1)
    	if(CQ.isEmpty1())
    	cout<<endl<<"Queue 1 is empty!!"<<endl;
    	else
    	cout<<endl<<CQ.dequeue1()<<" got deleted!!"<<endl;
    	if(c==2)
    	if(CQ.isEmpty2())
    	cout<<endl<<"Queue 2 is empty!!"<<endl;
    	else
    	cout<<endl<<CQ.dequeue2()<<" got deleted!!"<<endl;
    	cout<<endl;
	}
}
}

