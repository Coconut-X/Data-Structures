#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next; 
};


void displayList(node* head)
{
	/*while (head != NULL)
	{
		node* temp = head;
		head = head->next;
		cout << temp->data << endl;
	}*/

	if (head == nullptr) 
	{
		cout << "The list is empty." << endl;
		return;
	}

	node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << (temp->next != nullptr ? ", " : "\n\n");
		temp = temp->next;
	}
}


void insertAtEnd(node* &head, int data)
{
	node* currentHead = head;
	node* newNode = new node;
	newNode->data = data;
	newNode->next = nullptr;

	if (head == nullptr) ///this checks if list is initially empty
	{
		head = newNode;
		return;
	}

	while (currentHead->next != NULL)
	{
		currentHead = currentHead->next;
	}

	currentHead->next = newNode;
}

void insertAtBeginning(node*& head, int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void insertAtGivenIndex(node* head, int index, int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->next = nullptr;
	node* currentHead = head;

	if (head == nullptr || index == 0) 
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	int i = 0;

	while (currentHead->next != nullptr && i++ < index - 1)
	{
		currentHead = currentHead->next;
	}

	newNode->next = currentHead->next;
	currentHead->next = newNode;
}

void deleteLastNode(node* &head)
{
	if (head == nullptr) return;
	
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	node* currentHead = head;
	node* previousNode = nullptr;
	while (currentHead->next!=nullptr)
	{
		previousNode = currentHead;
		currentHead = currentHead->next;
	}

	previousNode->next = nullptr;
	delete currentHead;
}

void deleteFirstNode(node*& head)
{
	if (head == nullptr) return;

	node* temp = head;
	head = head->next;
	delete temp;
}

void deleteNodeAtGivenIndex(node*& head, int index)
{

	if (head == nullptr) return;														///if list is empty

	node* currentHead = head;

	if (index == 0)																		///delete first node
	{
		head = head->next;
		delete currentHead;
		return;
	}

	for (int i = 0; currentHead != nullptr && i < index - 1; ++i) 
	{
		currentHead = currentHead->next;
	}

	if (currentHead == nullptr || currentHead->next == nullptr) return;					///if out of scope 

	node* nodeToDelete = currentHead->next;
	currentHead->next = currentHead->next->next;
	delete nodeToDelete;


}


void searchNode(node* head, int key)
{
	node* temp = head;
	int i = 0;
	bool found = 0;
	while (temp != NULL )
	{
		if (temp->data == key)
		{
			cout << "Found At Index " << i << endl;
			found = 1;
		}
		temp = temp->next;
		i++;
	}

	if (!found) cout << "Not Found" << endl;

	cout << endl;
}

void deAllocateMemory(node*& head)
{
	while (head != NULL)
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}

	head = nullptr;
}



int main()
{
	node* head = nullptr;
	
	insertAtEnd(head, 5);
	insertAtEnd(head, 33);
	insertAtEnd(head, 12);
	insertAtEnd(head, -2);
	insertAtEnd(head, 0);
	insertAtEnd(head, -9);
	insertAtEnd(head, 0);

	cout << "Initial List: " << endl;
	displayList(head);

	insertAtBeginning(head, 27);
	insertAtBeginning(head, -222);

	cout << "Inserting Values At Head: " << endl;
	displayList(head);


	insertAtGivenIndex(head, 3, 22);

	cout << "Inserting 22 At Index 3: " << endl;
	displayList(head);

	deleteLastNode(head);
	deleteLastNode(head);

	cout << "Deleting Last Two Nodes " << endl;
	displayList(head);
	
	deleteFirstNode(head);

	cout << "Deleting First Node: " << endl;
	displayList(head);
	
	cout << "Deleting Node At Given Index (5)" << endl;
	deleteNodeAtGivenIndex(head,5);
	displayList(head);

	cout << "Searching for 7" << endl;
	searchNode(head, 7);

	cout << "Searching for 0" << endl;
	searchNode(head, 0);

	deAllocateMemory(head);

	

	return 0;
}
