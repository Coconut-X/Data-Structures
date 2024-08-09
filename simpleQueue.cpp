//simple queue
#include <iostream>
#include <string>
using namespace std;

class Queue {
	int front, rear, size, cap;
	int* arr;

public:
	Queue(int cap) : front(-1), rear(-1), size(0), cap(cap) {
		arr = new int[cap];
	}

	bool isEmpty()
	{
		return size == 0;
	}

	bool isFull()
	{
		return size == cap;
	}

	void enqueue(int data)
	{
		system("cls");
		if (isFull())
		{
			cout << "Queue is full" << endl;
			return;
		}

		if (front == -1)
			front = 0;

		arr[++rear] = data;
		size++;

		display();
	}
	//0 1 2 3 4
	//  b c d e
	void dequeue() {
		system("cls");
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return;
		}	

		if (front == rear)
		{
			front = rear = -1;
			size = 0;
			return;
		}
		
		for (int i = 0; i < rear; i++)
			arr[i] = arr[i + 1];

		rear--;
		size--;
		display();
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Queue: ";
		for (int i = front; i <= rear; i++)
			cout << arr[i] << " ";
		cout << endl << endl;
	}

	void peek()
	{
		system("cls");
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Front: " << arr[front] << endl << "Rear: " << arr[rear] << endl;
	}
};


int main(){


	Queue q(5);
	int choice, data;

	do
	{
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Peek" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter data: ";
			cin >> data;
			q.enqueue(data);
			
			break;
		case 2:
			q.dequeue();

			break;

		case 3:
			q.peek();
			break;

		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 4);

	return 0;

}
