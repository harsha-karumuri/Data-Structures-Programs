//  HomeWork Assignment - Sparse Matrix
//  SRI HARSHA KARUMURI
//  50201598


#include<iostream>
#include<string>
#include<regex>
using namespace std;

// A struct to keep items of a row
struct item
{
	unsigned int index;
	int data;
	item *next;
	item(unsigned int i, int d, item* t)
	{
		index = i; data = d; next = t;
	}
};

typedef item* link;

// A struct to maintain the all items in a matrix row
struct MatRow
{
	unsigned int size;
	link first;
	link last;
};

// Maintains index,data association for the matrix. Indexes are kept ordered.
class Matrix
{
public:
	Matrix() = default;
	Matrix(unsigned short row, unsigned short col);                 // Construction
	bool add(unsigned short row, unsigned short col, int data);		// Adds a new item to the matrix
	void show();                                                    // show all items of matrix
	Matrix operator + (Matrix&);                                    // ADD 2 Matrices
	link getfirst(int r);                                           // get first value
	Matrix Transpose();                                             // Transpose of given matrix
	unsigned short getRows();
	unsigned short getCols();
private:
	MatRow *Head;					// A pointer to show array of the "item" pointer
	unsigned short rowN;			// how many row matrix has
	unsigned short colN;		// how many col matrix has
};



// Initialize the class
Matrix::Matrix(unsigned short row, unsigned short col)
{
	rowN = row;
	colN = col;
	Head = new MatRow[row];
	for (int i = 0; i < row; i++)
	{
		Head[i].first = Head[i].last = NULL;
		Head[i].size = 0;
	}
}

unsigned short Matrix::getRows()
{
	return rowN;
}

unsigned short Matrix::getCols()
{
	return colN;
}

link Matrix::getfirst(int r)
{

	return Head[r].first;
}

Matrix Matrix::operator + (Matrix &param)  // To make  C = A + B
{
	Matrix MC(rowN, colN);

	for (int i = 0; i < rowN; i++)
	{
		link itA = Head[i].first;
		link itB = param.getfirst(i);

		while (itA != NULL || itB != NULL)
		{

			if (itB == NULL)
			{
				MC.add(i, itA->index, itA->data);
				itA = itA->next;
				continue;
			}
			if (itA == NULL)
			{
				MC.add(i, itB->index, itB->data);
				itB = itB->next;
				continue;
			}

			if (itA->index < itB->index)
			{
				MC.add(i, itA->index, itA->data);
				itA = itA->next;
			}
			else if (itA->index > itB->index)
			{
				MC.add(i, itB->index, itB->data);
				itB = itB->next;
			}
			else
			{
				MC.add(i, itA->index, itB->data + itA->data);
				itA = itA->next;
				itB = itB->next;
			}
		}
	}
	return MC;
}

void Matrix::show()         // to print values in the matrix
{
	link it;
	int a=0;
	for (unsigned short rowC = 0; rowC < rowN; rowC++)
	{
		it = Head[rowC].first;
		for (unsigned short colC = 0; colC < colN; colC++)
		{
			if (it != NULL)
			{

				if(colC >= it->index)
				{
				    if(it->data!=0)
				    {
					if(a==0)
					{
					cout << rowC << ":" << colC << " ";
					cout << it->data;
					a=1;
				    }
				    else
				    {
					cout << " , "<< rowC << ":" << colC << " ";
					cout << it->data ;
				    }
				    }
				    it = it->next;
				}
			}
		}

	}
}

bool Matrix::add(unsigned short row, unsigned short col, int data)		// Adds a new item to the matrix
{
	link Ptr = new item(col, data, NULL);			//  dynamically create a new struct/item. We append, add to end of list
	if (Ptr == NULL) return false;  // not enought memory

	if (Head[row].first == NULL) 					// first item to be added
	{
		Head[row].first = Ptr;
		Head[row].last = Ptr;
	}
	else
	{
		Head[row].last->next = Ptr;
		Head[row].last = Ptr;
	}
	Head[row].size++;
	return true;	// added.
}

Matrix Matrix::Transpose()              // to transpose the matrix
{

	Matrix t(colN,rowN);
	link it;
	for (unsigned short rowC = 0; rowC < rowN; rowC++)
	{
		it = Head[rowC].first;

		for (unsigned short colC = 0; colC < colN; colC++)
		{
			if (it != NULL)
			{
				if(colC >= it->index)
				{
                    t.add(colC,rowC,it->data);
					it = it->next;
				}
			}
			else
			{
			//	Do Nothing!!
			}
		}
	}
	return t;
}

struct Mat                     // Structure of matrix and its name
{
	Matrix matrix;
	string matName;
};

int main(int argc, const char * argv[])
{
    string command="";
    int count = 0;
    regex show("[A-Z]");                                 //reg exp: A
    regex create("matrix[A-Z]\\([0-9]+,[0-9]+\\)");      //reg exp: matrixA(p,q)
    regex store("[A-Z]\\([0-9]+,[0-9]+\\)=-*[0-9]+");    //reg exp: A(a,b) = I
    regex add("[A-Z]=[A-Z]\\+[A-Z]");                    //reg exp: A=B+C
	regex transpose("[A-Z]=[T]\\([A-Z]\\)");             //reg exp: A=T(B)

	Mat *matArray = new Mat[5];                          //Create a structured array

	while(command!="exit")
	{
		getline(cin,command);
		command.erase(remove_if(command.begin(),command.end(),::isspace),command.end());  // remove blank spaces

		if(regex_match(command,create))                  // If command matches with reg exp "create"
		{
			int i,j,k;
			i=command.find("(");
			j=command.find(",");
			k=command.find(")");
			string matrixName=command.substr(6,1);
			unsigned short matrixRow = stoi(command.substr(i+1,j-i-1));
			unsigned short matrixCol = stoi(command.substr(j+1,k-j-1));
			Matrix matrix1(matrixRow,matrixCol);
			if(count<5)
			{
			matArray[count].matrix = matrix1;
			matArray[count].matName = matrixName;
			count++;
			}
			else cout<<"Limit exceeded!! Come again later!!";
		}

		if(regex_match(command,store))                   // If command matches with reg exp "store"
		{
			int i,j,k,p;
			i=command.find("(");
			j=command.find(",");
			k=command.find(")");
			p=command.find("=");
			string matrixName=command.substr(0,1);
			unsigned short matrixRow = stoi(command.substr(i+1,j-i-1));
			unsigned short matrixCol = stoi(command.substr(j+1,k-j-1));
			int value = stoi(command.substr(p+1,command.length()-p));

			Matrix matrix1;
			for(int i=0; i<count; i++)
			{
				if(matArray[i].matName==matrixName)
				{
					matrix1 = matArray[i].matrix;
					matrix1.add(matrixRow,matrixCol,value);
				}
			}
		}

		if(regex_match(command,add))                   // If command matches with reg exp "add"
		{
			string resMatName = command.substr(0,1);
			string mat1Name = command.substr(2,1);
			string mat2Name = command.substr(4,1);
			Matrix m1,m2;

			for(int i=0; i<count; i++)
			{
				if(matArray[i].matName==mat1Name)
					m1 = matArray[i].matrix;
				if(matArray[i].matName==mat2Name)
					m2 = matArray[i].matrix;
			}

	        Matrix m3(m1.getRows(),m1.getCols());
			m3=m1+m2;
			if(count<5)
				{
			matArray[count].matrix = m3;
			matArray[count].matName = resMatName;
			count++;
				}
			else cout<<"Limit exceeded!! Come again later!!";
		}

		if(regex_match(command,show))                   // If command matches with reg exp "show"
		{
			string matName = command.substr(0,1);
			Matrix m;
			for(int i=0; i<count; i++)
			{
				if(matArray[i].matName==matName)
					m = matArray[i].matrix;
			}
			m.show();
		}

		if(regex_match(command,transpose))                   // If command matches with reg exp "transpose"
		{
			string matN = command.substr(0,1);
			string mat = command.substr(4,1);
			Matrix m,m1;
			for(int i=0; i<count; i++)
				{
					if(matArray[i].matName==mat)
					    m = matArray[i].matrix;
				}
			m1=m.Transpose();
			if(count<5)
				{
			matArray[count].matrix = m1;
			matArray[count].matName = matN;
			count++;
				}
			else cout<<"Limit exceeded!! Come again later!!";
		}
	}
}

