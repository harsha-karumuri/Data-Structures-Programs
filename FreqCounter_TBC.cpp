 // Frequency counter for A-Z in parallel arrays

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>      // std::setw

using namespace std;

const int SIZE = 26; // Keeps only 26 chars in unordered list

int find(char *ch, char cch)
{
	for (int i = 0; i < SIZE; i++)
   {
	if ( ch[i] == 0 ) // not found
	{
		ch[i]=cch;
		return i;
	}

    if (ch[i] == cch )
		return i;
   }
}

int main()
{
	char ch[SIZE] = {0};
	int fre[SIZE] = {0};
	char cch;
	int index=0;

   for (int i = 0; i < 50; i++)  // generate 50 chars
   {
	   cch  = rand() % 26 + 65;  //  generates between 65 - 90 (including)
	   cout << cch << ", " ;
	   index = find(ch,cch);
	   fre[index]++;
   }
   cout << endl;

   for (int i = 0; i < SIZE; i++)
   {
	   	cout <<  i << " " << ch[i] << " ->" << fre[i]  << endl;
   }



}
