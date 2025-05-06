#include<iostream>
using namespace std;

class Hashtable
{	public:
	int key;
	int index;
};

class Hashing
{	private:
	Hashtable H[10];
	
	public:
	Hashing()
	{
		for (int i=0;i<10;i++)
		{
			H[i].key=-1;
			H[i].index=i;
		}
	}
	void display();
	void insert(int);
	int LinearProbing(int pos);
	long int QuadraticProbing (int pos);
};

void Hashing::display()
{
	cout<<"Hash Table \n";
	for (int i=0;i<10;i++)
	{
		cout<<H[i].key<<"\t"<<H[i].index;
		cout<<"\n";
	}
}

void Hashing::insert(int Probechoice)
{
	int pos,n;
	cout<<"Enter the telephone number:";
	cin>>n;
	pos=n%10;
	if (H[pos].key==-1)
		{
			H[pos].key=n;
		}
	else if (Probechoice==1)
		{	int temppos=LinearProbing(pos);
			H[temppos].key=n;
		}
	else if (Probechoice==2)
	{	int temppos=QuadraticProbing(pos);
		H[temppos].key=n;
	}
}

int Hashing::LinearProbing(int pos) 
{	for (int i=1; i<10;i++) 
    {
        int newPos=(pos + i)%10; 
        if (H[newPos].key==-1) 
        {
            return newPos;
        }
    }
    return -1; 
}

long int Hashing::QuadraticProbing(int pos) 
{	for (int i = 0; i < 10; i++) 
    {
        int newPos = (pos + i * i) % 10; 
        if (H[newPos].key == -1)
        {
            return newPos;
        }
    }
    return -1; 
}

int main()
{
	int choice,n;
	Hashing h;
    do
    {
        cout<<"\nMENU";
        cout<<"\n1.Insert ";
        cout<<"\n2.Display ";
        cout<<"\n3.Exit";
        cout<<"\nEnter your choice :";
        cin>>choice;
        switch(choice)
        {
        	case 1:
        		cout<<"\n1.Linear Probing \n2.Quadratic probing";
        		cout<<"\nEnter choice :";
        		cin>>n;
        		if (n==1||n==2)
        		{	h.insert(n);
        		}
        		else
        			cout<<"Wrong choice!!Try again..";
        		break;
        	
        	case 2:
        		h.display();
        		break;
        	
        	case 3:
        		cout<<"Exit!!";
        		break;
        }
      }while(choice!=3);
      return 0;
}
