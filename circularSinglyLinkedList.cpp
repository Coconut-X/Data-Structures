#include<iostream>
using namespace std;

struct node {
public:
	int data;
	node* next;
};

void displayList(node* head)
{
	if (head == nullptr)
	{
		cout << "The list is empty." << endl;
		return;
	}
	node* temp = head;
	do 
	{
		cout << temp->data << (temp->next != head ? ", " : "\n\n");
		temp = temp->next;
	} while (temp != head);
	cout << "sss" << temp->data << endl;
}

int lengthOfList(node* head)
{
	if (head == nullptr) return 0;

	int length = 0;
	node* temp = head;
	do {
		temp = temp->next;
		length++;
	} while (temp != head);

	return length;
}

void insertAtEnd(node*& head, int data)
{
	node* currentHead = head;
	node* newNode = new node;
	newNode->data = data;
	
	if (head == nullptr) ///this checks if list is initially empty
	{
		head = newNode;
		newNode->next = head;
		return;
	}

	while (currentHead->next != head)
	{
		currentHead = currentHead->next;
	}

	currentHead->next = newNode;
	newNode->next = head;
}

void insertAtBeginning(node*& head, int data)
{
	if (head == nullptr)
	{
		insertAtEnd(head, data);
		return;
	}

	node* end = head;
	do 
	{
		end = end->next;

	} while (end->next != head);

	node* newNode = new node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	end->next = head;
}

void insertAtGivenIndex(node*& head, int index, int data)
{
	if (index > lengthOfList(head) - 1)
	{
		cout << "Invalid Index" << endl << endl;
		return;
	}

	node* newNode = new node;
	newNode->data = data;
	newNode->next = nullptr;
	node* currentHead = head;

	if (head == nullptr || index == 0)
	{
		insertAtBeginning(head, data);
		return;
	}

	int i = 0;
	while (currentHead->next != nullptr && i++ < index - 1)
	{
		currentHead = currentHead->next;
	}

	if (currentHead->next == nullptr) return;

	newNode->next = currentHead->next;
	currentHead->next = newNode;
}

void deleteFirstNode(node*& head) 
{
	if (head == nullptr) {
		cout << "List Is Empty" << endl << endl;
		return;
	}

	if (head->next == head) 
	{ /// Only one node in the list
		delete head;
		head = nullptr;
		//cout << "First Node Deleted" << endl << endl;
		return;
	}

	node* temp = head;
	node* current = head;

	while (current->next != head) {
		current = current->next;
	}

	head = head->next;
	current->next = head;
	delete temp;

	//cout << "First Node Deleted" << endl << endl;
}

void deleteLastNode(node*& head)
{
	if (head == nullptr)
	{
		cout << "List Is Empty" << endl << endl;
		return;
	}

	if (head->next == nullptr) 
	{
		delete head;
		head = nullptr;
//		cout << "Last Node Deleted" << endl << endl;

		return;
	}

	node* currentHead = head;
	node* previousNode = nullptr;
	while (currentHead->next != head)
	{
		previousNode = currentHead;
		currentHead = currentHead->next;
	}

	previousNode->next = head;
	delete currentHead;
	//cout << "Last Node Deleted" << endl << endl;
}

void deleteNodeAtGivenIndex(node*& head, int index)
{
	if (index<0 || index>lengthOfList(head) - 1)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	if (head == nullptr)
	{
		cout << "List Is Empty" << endl << endl;
		return;
	}

	node* currentHead = head;

	if (index == 0)
	{
		deleteFirstNode(head);
		return;
	}

	if (index == lengthOfList(head) - 1)
	{
		deleteLastNode(head);
		return;
	}

	for (int i = 0; currentHead != nullptr && i < index - 1; ++i)
	{
		currentHead = currentHead->next;
	}
	
	node* nodeToDelete = currentHead->next;
	currentHead->next = currentHead->next->next;
	delete nodeToDelete;
	//cout << "Node Deleted" << endl << endl;

}

void deAllocateMemory(node*& head) 
{
	if (head == nullptr) {
		cout << "Memory DeAllocated " << endl;
		return;
	}

	node* current = head;

	node* temp = nullptr;
	while (current->next != head) 
	{
		temp = current;
		current = current->next;
		delete temp;
	}

	delete current;
	head = nullptr;

	cout << "Memory Deallocated " << endl;
}

void sortList(node*& head, int type)///type=1=ascending
{
	if (head == NULL) return;
	int length = lengthOfList(head);

	for (int i = 0; i < length; i++)
	{
		bool found = false;
		node* current = head;
		node* NextNode = head->next;

		for (int j = 0; j < length - 1 - i; j++)
		{
			NextNode = current->next;
			if ((type == 1 && current->data > NextNode->data) || (type == -1 && current->data < NextNode->data))
			{
				int temp = current->data;
				current->data = NextNode->data;
				NextNode->data = temp;
				found = true;
			}
			current = NextNode;
			NextNode = NextNode->next;
		}
		if (!found) return;
	}
}

void rotateListLeft(node*& head, int k)
{
	int length = lengthOfList(head);
	k = k % length;
	for (int i = 1; i <= k; i++)
	{
		insertAtEnd(head, head->data);
		deleteFirstNode(head);
	}
	cout << "List Rotated" << endl << endl;
}

void rotateListRight(node*& head, int k)
{
	int length = lengthOfList(head);
	k = k % length;

	for (int i = 1; i <= k; i++)
	{
		node* currentHead = head;
		while (currentHead->next != head)
		{
			currentHead = currentHead->next;
		}

		insertAtBeginning(head, currentHead->data);
		deleteLastNode(head);
	}
	cout << "List Rotated" << endl << endl;
}


void searchNode(node* head, int key)
{
	node* temp = head;
	int length = lengthOfList(head) - 1;
	bool found = 0;
	
	for (int i = 0; i <= length; i++)
	{
		if (temp->data == key)
		{
			cout << "Found at Index: " << i << endl;
			found = 1;
		}
		temp = temp->next;
	}

	if (!found) cout << "Not Found" << endl;
	cout << endl;
}

void reverseList(node*& head)
{
	if (head->next == head)
		return;

	node* newNode = nullptr;
	node* current = head;

	do
	{
		insertAtBeginning(newNode, current->data);
		current = current->next;

	} while (current != head);
	
	deAllocateMemory(head);
	head = newNode;
}

node* mergeList(node* list1, node* list2) 
{
	if (list1 == nullptr) return list2;
	if (list2 == nullptr) return list1;

	node* tail1 = list1;
	while (tail1->next != list1) 
	{
		tail1 = tail1->next;
	}

	node* tail2 = list2;
	while (tail2->next != list2) 
	{
		tail2 = tail2->next;
	}

	tail1->next = list2;
	tail2->next = list1;

	return list1;
}


int main()
{
	node* head = new node;
	head = nullptr;
	insertAtBeginning(head, 99);
	insertAtEnd(head, 1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);
	insertAtEnd(head, 2);
	insertAtGivenIndex(head, 2, -2);
	
	displayList(head);

	cout << "Asc" << endl;
	sortList(head, 1);
	displayList(head);

	sortList(head, -1);
	cout << "Desc" << endl;
	displayList(head);

	cout << "Rot Right by 2: " << endl;
	rotateListRight(head, 2);
	displayList(head);

	cout << "Rot Left by 2: " << endl;
	rotateListLeft(head, 2);
	displayList(head);

	cout << "Search 2: " << endl;
	searchNode(head, 2);

	cout << "Reversed List: " << endl;
	reverseList(head);
	displayList(head);

	node* list2 = nullptr;
	insertAtEnd(list2, 1);
	insertAtEnd(list2, 2);
	insertAtEnd(list2, 3);
	insertAtEnd(list2, 4);

	cout << "Merged: " << endl;
	head = mergeList(head, list2);
	displayList(head);

	
	deAllocateMemory(head);

	//cout << "Length: " << lengthOfList(head);

	return 0;
}
