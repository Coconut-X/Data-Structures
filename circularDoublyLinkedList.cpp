#include<iostream>
using namespace std;

struct node {
public:
	int data;
	node* next;
	node* prev;
	node(int data) : data(data), next(nullptr), prev(nullptr) {}
	node() {}
};


void displayList(node* head)
{
	if (head == nullptr)
	{
		cout << "List is empty" << endl;
		return ;
	}
	node* current = head;
	do 
	{
		cout << current->data << ((current->next != head) ? ", " : "\n\n");
		current = current->next;
	} while (current != head);
}

void insertAtBeginning(node*& head, int data)
{
	node* newNode = new node(data);

	if (head == nullptr)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		head = newNode;
		return;
	}

	node* tail = head->prev;

	newNode->next = head;
	newNode->prev = tail;
	head->prev = newNode;
	tail->next = newNode;
	head = newNode;
}

void insertAtEnd(node*& head, int data)
{
	node* newNode = new node(data);
	///a	b	 c	  d		e
	head->prev->next = newNode;
	newNode->prev = head->prev;
	head->prev = newNode;
	newNode->next = head;
}

void deleteFirstNode(node*& head)
{
	if (head == nullptr)
	{
		cout << "List Is Empty" << endl;
	}
	if (head->next == head)
	{
		delete head;
		head = nullptr;
	}

	node* temp = head;
	node* tail = head->prev;
	head = head->next;
	tail->next = head;
	head->prev = tail;

	delete temp;
}

void deleteLastNode(node*& head)
{
	if (head == nullptr)
	{
		cout << "List Is Empty" << endl;
	}
	if (head->next == head)
	{
		delete head;
		head = nullptr;
	}

	node* tail = head->prev;
	node* secondLast = head->prev->prev;
	head->prev = secondLast;
	secondLast->next = head;
	delete tail;
}

int main()
{

	node* head = new node;
	head = nullptr;
	insertAtBeginning(head, 3);
	insertAtBeginning(head, 2);
	insertAtBeginning(head, 1);
	insertAtEnd(head,4);
	insertAtEnd(head,5);
	insertAtEnd(head,9);
	insertAtEnd(head,8);
	
	displayList(head);
	deleteFirstNode(head);
	deleteFirstNode(head);
	displayList(head);

	deleteLastNode(head);
	deleteLastNode(head);

	displayList(head);




	return 0;
}
