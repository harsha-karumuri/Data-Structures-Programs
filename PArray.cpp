// SRI HARSHA KARUMURI
// 50201598
// LAB ASSIGNMENT S18-L-9

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

const int size = 250; 
void sort(int *freq, string *word); // TO SORT THE ARRAY

int find(string *word, string ch)   // TO FIND THE ELEMENT IF IT IS PRESENT
{
	for (int i = 0; i < size; i++)
    {
	if ( word[i] == "" ) // IF NOT FOUND
	{
		word[i]=ch;
		return i;
	}

    if (word[i] == ch )  // IF FOUND
		return i;
    }
}

int main()
{
	string word[size];
	int freq[size] = {0};
	string ch;
	int index=0;
    
	cout<<"\nRandomly generated strings:          (25 per line)"<<endl;
    
	for (int i = 0; i < 250; i++)  // generate 250 strings
    {
   	   
	   ch  = rand() % 26 + 65;  //  generates between A - Z (including)
	   ch  += rand() % 26 + 65; //  generates between A - Z and concats with the previous one
	   if(i%25==0) cout<<endl;
	   cout << ch << ", " ;
	   index = find(word,ch);
	   freq[index]++;
    }
    cout << endl;
		
	sort(freq,word);
    
    cout<<"\n\nTop three high frequency strings and their frequencies :\n";
	for(int i=0;i<3;i++)
    cout<<"\n"<<word[i]<<" --> "<<freq[i];
    cout<<endl<<endl<<endl;
	return 0;
}

void sort(int *freq, string *word)     // to sort array
{
	int temp1=0;
	string temp2;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size-1; j++)
		{
			if(freq[j]<freq[j+1])
			{
				temp1 = freq[j];
				freq[j] = freq[j+1];
				freq[j+1] = temp1;
				
				temp2 = word[j];
				word[j] = word[j+1];
				word[j+1] = temp2;
			}
		}
	}
}
