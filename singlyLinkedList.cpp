#include<iostream>
using namespace std;

class node{
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

void insertAtGivenIndex(node* &head, int index, int data)
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

	if (currentHead->next == nullptr ) return;

	newNode->next = currentHead->next;
	currentHead->next = newNode;
}


int lengthOfList(node* head)
{
	int length = 0;
	for (; head != NULL && (head = head->next); length++);

	return length;
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


void deleteNodeWithSpecificValue(node*& head,int key)
{
	///isko kal dekhtay hain
	 
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

void sortList(node*&head, int type)///type=1=ascending
{
	/*
	func(array, type)  type can be 1 or -1

	for()
	{
		for()
		{
			if(a<type*b) swap(a,b) //ye ascendin karay ga agr type 1 ho or descending agr type -1 ho
		}
	}
	
	
	*/

}

void reverseList(node*& head)
{

}

void updateNodeDataByIndex(node* head, int index, int data)
{
	node* currentHead = head;
	
	int i = 0;
	
	while (currentHead != NULL && i++ < index)
	{
		currentHead = currentHead->next;
	}

	if (currentHead == NULL ) return;

	currentHead->data = data;
}

void updateNodeDataByValue(node* head, int key, int data)
{
	if (key == data) return; ///else it will go in infinite loop

	int i = 0;
	node* currentHead = head;
	while (currentHead != NULL )
	{
		if (currentHead->data == key)
		{
			updateNodeDataByIndex(head, i, data);
			//currentHead = head;
		}
		i++;
		currentHead = currentHead->next;
	}

}


void findMiddleNode(node* head)
{
	if (head == NULL)
	{
		cout << "List Is Empty..!" << endl << endl;
		return;
	}

	int length = lengthOfList(head);
	int i = 0;
	for (; i < length / 2 && (head=head->next); i++);

	if (length & 1)
	{
		cout << "Middle Nodes Are: " << head->data << ", " << head->next->data << endl << endl;
		return;
	}

	cout << "Middle Node is : " << head->data << endl << endl;

}

void findNthNodeFromEnd(node* head,int N)
{
	if (head == NULL)
	{
		cout << "List Is Empty!" << endl << endl;
		return;
	}

	int length = lengthOfList(head);
	for (int i = 0; i < length - N && (head = head->next); i++);

	cout << N << "th Node From End is:  " << head->data << endl << endl;

}

void displayReverse(node* head)
{

}

void isListPalindrome(node* head)
{

}

void rotateListLeft(node* head, int k)
{

}

void rotateListRight(node* head, int k)
{

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

	cout << "Memory DeAllocated " << endl;
}

void deleteList(node*& head)
{
	deAllocateMemory(head);
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
	insertAtGivenIndex(head, 2, 17);
	insertAtGivenIndex(head, 4, 45);

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

	insertAtGivenIndex(head, 0, 0);
	insertAtGivenIndex(head, 3, 0); ///if i write this line, then it gets stuck somewhere in infinity loop, but this function is working as used above 
	
	cout << "Inserting 0s to check function below:" << endl;
	displayList(head);


	///========kal dekhun ga========================
	/*cout << "Deleting Nodes With Specific Value(0):" << endl; 
	deleteNodeWithSpecificValue(head, 0);
	displayList(head);*/
	///============================================


	insertAtGivenIndex(head, 12, 26);
	cout << "Inserting 26 At Index 12 Which is out of Scope(26 should not be added at end):" << endl;
	displayList(head);

	insertAtGivenIndex(head, 9, 26);

	cout << "Inserting 26 At Index 9 (26 should be added at end):" << endl;
	displayList(head);


	cout << "Changing value at index 4 and 7 by 11: " << endl;
	updateNodeDataByIndex(head, 4, 11);
	updateNodeDataByIndex(head, 7, 11);
	displayList(head);

	cout << "Changing All Values of 11 by 87:" << endl;
	updateNodeDataByValue(head, 11, 87);
	displayList(head);

	cout << "Length of List is: " << lengthOfList(head) << endl << endl;

	findMiddleNode(head);

	cout << "Adding Data To Make List Odd: " << endl;
	insertAtEnd(head, 44);
	displayList(head);


	findMiddleNode(head);

	findNthNodeFromEnd(head, 2);

	cout << "Delete List: " << endl;
	deleteList(head);


	displayList(head);

	deAllocateMemory(head);


	return 0;
}
