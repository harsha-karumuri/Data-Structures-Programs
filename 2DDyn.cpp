#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
int *headcol[2], a;

do
{

cout<<endl<<"Enter second dimension: ";
cin>>a;
	
if(a>9 || a<0)
{
cout<<"Enter second dimension with in 10 !!";
return 0;
}
        
if(a==0)
{
cout<<"bye bye!!";
return 0;
}
	
headcol[0]= new int[a];
headcol[1]= new int[a];
    
for(int i=0; i<2; i++)
{
 for(int j=0; j<a; j++)
  {
   headcol[i][j]= rand() % 11;
  }
}
			   
for(int i=0; i<2; i++)
{
 for(int j=0; j<a; j++)
  {
   cout<<headcol[i][j]<<"   ";
  }
  cout<<endl;
}
    
delete [] *headcol;

}while(!(a==0));

}



