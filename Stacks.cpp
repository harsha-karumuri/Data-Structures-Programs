 //PROGRAM TO VERIFY WHETHER EXPRESSION IS BALANCED OR NOT
 //SRI HARSHA KARUMURI
 //50201598
 //S18-L-4   LAB ASSIGNMENT
 
 #include<iostream>
 #include<string.h>
 using namespace std;
 
#define MAX 50      // Maximum characters allowed for the expression 

class Stack      // class is built here for the stack
{   
    private:
		char *expr;             // expression used to check whether it got balanced or not!!  (dynamic array)
		unsigned short size;    // size of the stack
	
	public:
		Stack();               //constructor which initializes the variables
		bool push(char ch);    //function uses character ch to push into the stack 
		char pop();            //pops the element which gets inserted at the last
		bool isEmpty();        //checks if stack is empty
		bool isFull();         //checks if stack is full
};

Stack::Stack()  
{
	size = 0;                //initializes to 0
	expr = new char[MAX];    //dynamic array is initialized here
}

bool Stack::push(char ch)
{
	if(isFull())             //if stack is full.. then we cannot add element in to stack
	    return false;
    else                     //increase the size of array and store value into stack
	{
		expr[ size++ ] = ch;            
        return true;
	}
	
}

char Stack::pop()
{
	if(isEmpty())             //if empty.. there is no variable to pop 
	    return NULL;  
	else                      //decrement the array to pop the element      
	{
		char z = expr[--size];;
        return z;
	}
	
}

bool Stack::isEmpty()         //checks if stack is empty
{
	if(size==0)
	return true;
	else
	return false;
}

bool Stack::isFull()          //checks if stack is full
{
	if(size == MAX-1)
	return true;
	else 
	return false;
}

bool checkCharMatch(char x, char y)           //checks if the characters of the expression got matched
{
	bool result = false;
	if( (x=='}' && y=='{') || (x==']' && y=='[') || (x==')' && y=='(') || (x=='>' && y=='<') )     //if matched then true
	  result = true;
	return result;	
}

bool checkIfBalanced(char exp[])            //checks whether expression is balanced or not
{
    int l = strlen(exp);
    bool result = true;
    Stack S;                                //initializes stack(class) object
    for(int i=0;i<l;i++)
    {
        if( (exp[i] == '[') || (exp[i] == '{') || (exp[i] == '(') || (exp[i] == '<') )          //if matched push element into the stack
        {
            S.push(exp[i]);
        }
        else if( (exp[i] == ']') || (exp[i] == '}') || (exp[i] == ')') || (exp[i] == '>') )     //if matched compare pop element and the element matched
        {
            if( checkCharMatch( exp[i], S.pop() ) == false )
            {
                result = false;
                break;
            }
        }
        else 
        {
        cout<<endl<<"Enter valid expression which contain { [ ( < > ) ] } "<<endl;
        return false;
        }
    }
    
    if(S.isEmpty()== false)
        result = false;

    return result;
    
}

int main(int argc, const char * argv[]) {


	char* temp;
	temp = new char[MAX];           //initialize dynamic array
	int cont=1;
	while(cont!=0)
	{		
    	cout <<endl<< "Enter the expression to check whether it is balanced :  ";
    	cin >> temp;

    	if(checkIfBalanced(temp)==true)                              //checks whether expression is balanced!!
            cout<<endl<<"True!! Expression is balanced!!"<<endl;
    	else
        	cout<<endl<<"False!! Expression is not balanced!!"<<endl;
	
	cout<<endl<<"Do you want to continue(1).. exit(0)..   ";
	cin>>cont;
    }
    return 0;
}
