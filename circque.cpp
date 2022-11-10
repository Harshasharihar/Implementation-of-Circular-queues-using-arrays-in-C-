#include<iostream>
using namespace std;
#define max 5
#define null 0

class CirQue
{
	private :int arr[max];
			 int front,rear;
			 
			 
	public  :
			 CirQue();
			 void add_data(int);
			 int get_data();
			 void display();
			 ~CirQue();
				
};

CirQue::CirQue()
{
	cout<<"Inside constructor function\n";
	front = -1;
	rear = -1;
	for(int i = 0;i<max;i++)
	{
		arr[i] = 0;
	}
}

void CirQue::add_data(int num)
{
	if((front == 0 && rear == max-1) || ((rear+1)%max == front) )
	{
		cout<<"The queue is full..\n";
		return;
	}
	
	rear++;
	arr[rear] = num;
	
	if(front == -1)
	{
		front = 0;
	}
}

int CirQue::get_data()
{
	if(front == -1)
	{
		cout<<"The Queue is empty\n";
		return null;
	}
	
	int x = arr[front];
	arr[front] = 0;
	
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		if(front == max-1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
	}
	return x;
}

void CirQue::display()
{
	for(int i = 0 ;i< max;i++)
	{
		cout<<arr[i]<<endl;
	}
}

CirQue::~CirQue()
{
	cout<<"Inside the destructor function\n";
}

int main()
{	CirQue c;
	int num = 0,choice  = 0;
	
	while(1)
	{
		cout<<"Enter the choice\n";
		cout<<"1 to read data \n";
		cout<<"2 to gwt data \n";
		cout<<"3 to exit\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1 :cout<<"Enter the number\n";
					cin>>num;
					c.add_data(num);
					break;
			case 2 :num = c.get_data();
					cout<<"The returned data is "<<num<<endl;
					break;
			case 3 :cout<<"Exiting...\n";
					break;
			default:cout<<"Invalid Input...Try again...\n";
					break;
		}
	}
}
