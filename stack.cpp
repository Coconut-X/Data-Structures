#include<iostream>
#include<string>
using namespace std;


//basic structure of stack:
/*
  Stack follows LIFO (Last In First Out)
  there are 5 tasks in stack as a,b,c,d,e
  
  e is the last task added in stack, means it will be executed first and then d, c, b, a
  when we add a task in stack, it is added at the top of stack,
  task->next contains the address of the task which is added before it, or which will be executed after current task
  when e is executed, it is popped from stack,
  so the next tast after e is d (e->next=d), so it is at the top of stack
*/

class stack {
	int data;
	stack* next;
public:
	
	stack(int data) : data(data), next(nullptr) {}

	void push(stack* &top, int data)
	{
		stack* newNode = new stack(data);
		newNode->next = top;
		top = newNode;
	}

	bool isEmpty(stack* top)
	{
		return top == nullptr;
	}

	void peek(stack* top)
	{
		cout <<( (top != nullptr) ? to_string(top->data) : "Stack is empty") << endl;
	}

	void pop(stack*& top)
	{
		stack* temp = top;
		top = top->next;
		delete temp;
	}
};


int main()
{
	stack* top = NULL;
	stack s(0);
	int choice, data;

	do
	{
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter data: ";
			cin >> data;
			s.push(top, data);
			break;

		case 2:
			if (s.isEmpty(top))
				cout << "Stack is empty" << endl;
			else
				s.pop(top);
			break;

		case 3:
			if (s.isEmpty(top))
				cout << "Stack is empty" << endl;
			else
				s.peek(top);
			break;

		case 4:
			break;

		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 4);

	return 0;
}
