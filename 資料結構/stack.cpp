#include <iostream>
#define MAX 5
using namespace std;
void push();
void pop();
void list();
char item[MAX][20]; 
int top = -1;
	
int main()
{
	int option = 0;
	while(1)
	{
		cout << " choice (1) list (2) push (3) pop (4) quit : ";
		cin >> option;
		switch (option)
		{
			case 1 :
				list();
				break;
			case 2 :
				push();
				break;
			case 3 :
				pop();
				break;
			case 4 :
				exit(0);
			default :
				cout << "Please input number 1 to 4 ." << endl;
		}
	}	
	return 0;
} 
void push()
{
	if(top == MAX - 1)
		cout << " Stack is full" << endl;
	else
		top++;
		cout << "input data into stack :" << endl; 
		cin >> item[top];
}
void pop()
{
	if(top < 0)
		cout << "Stack is empty" << endl;
	else 
	{
		cout << "Item " << item[top] << " deleted" << endl;
		top--;
	}
}
void list()
{
	int count = 0;
	if(top < 0)
	{
		cout << "Stack is empty" << endl;
	}
	else 
	{
		cout << "Item" << endl;
		cout << "-------------------" << endl;
		for(int i = top; i >= 0; i--)
		{
			cout << item[i] << endl; 
			count ++;
		}
		cout << "--------------------" << endl;
		cout << "total item: " << count << endl;
	}
}
