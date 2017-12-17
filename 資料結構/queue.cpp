#include <iostream>
#define MAX 5
using namespace std;
void enqueue();
void dequeue();
void list();
int front = MAX -1;
int rear = MAX -1;
char item [MAX][20];

int main(){
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
				enqueue();
				break;
			case 3 :
				dequeue();
				break;
			case 4 :
				exit(0);
			default :
				cout << "Please input number 1 to 4 ." << endl;
		}
	}	
	return 0;
} 

void enqueue()
{
	rear = (rear + 1) % MAX;
	if(rear == front)
	{
		if(rear == 0)
			rear = MAX - 1;
		else
			rear = rear - 1;
		cout << "The queue is full" << endl;
		
	}
	else
	{
		cout << " Please input a data: ";
		cin >> item[rear];
	}
}

void dequeue()
{
	if(front == rear)
		cout << "The queue is empty" << endl;
	else
	{
		front = (front + 1) % MAX;
		cout << "Deleted " << item[front] << " from the queue" << endl;
	}
}

void list()
{
	int count = 0;
	if (front == rear)
		cout << "The queue is empty" << endl;
	else
	{
		cout << "Item" << endl;
		cout << "-------------------" << endl;
		for(int i = front + 1; i <= rear; i++)
		{
			cout << item [i] << endl;
			count ++;
		}
		cout << "--------------------" << endl;
		cout << "total item: " << count << endl;
	}
}
