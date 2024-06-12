#include<iostream>
#include<vector>
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
	cout << "Value Inserted" << endl << endl;
}


int lengthOfList(node* head)
{
	if (head == NULL) return 0;
	int length = 0;
	for (; head != NULL && (head = head->next); length++);

	return length+1;
}

void deleteLastNode(node* &head)
{
	if (head == nullptr) 
	{
		cout << "List Is Empty" << endl << endl;
		return;
	}
	
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
	cout << "Last Node Deleted" << endl << endl;
}

void deleteFirstNode(node*& head)
{

	if (head == nullptr)
	{
		cout << "List Is Empty" << endl << endl;
		return;
	}

	node* temp = head;
	head = head->next;
	delete temp;
	cout << "First Node Deleted" << endl << endl;

}


void deleteNodeAtGivenIndex(node*& head, int index)
{


	if (head == nullptr)
	{
		cout << "List Is Empty" << endl << endl;
		return;
	}												

	node* currentHead = head;

	if (index == 0)																		
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
	cout << "Node Deleted" << endl << endl;

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
	if (head == NULL) return;
	int length = lengthOfList(head);

	for (int i = 0; i < length; i++)
	{
		bool found = false;
		node* current = head;
		node* NextNode = head->next;
		
		for (int j = 0; j < length - 1- i; j++)
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



void updateNodeDataByIndex(node* head, int index, int data)
{
	if (head == NULL)
	{
		cout << "List Is Empty..!" << endl << endl;
		return;
	}
	node* currentHead = head;
	int i = 0;
	
	while (currentHead != NULL && i++ < index)
	{
		currentHead = currentHead->next;
	}

	if (currentHead == NULL ) return;
	currentHead->data = data;
	cout << "Node Updated!" << endl << endl;
}

void updateNodeDataByValue(node* head, int key, int data)
{
	if (head == NULL)
	{
		cout << "List Is Empty..!" << endl << endl;
		return;
	}

	int i = 0;
	node* currentHead = head;
	while (currentHead != NULL )
	{
		if (currentHead->data == key)
		{
			updateNodeDataByIndex(head, i, data);
		}
		i++;
		currentHead = currentHead->next;
	}
	cout << "Node Updated!" << endl << endl;
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


void deleteList(node*& head);

void deAllocateMemory(node*& head);

void reverseList(node*& head)
{
	if (head == NULL) return;
	node* newList = nullptr;
	node* currentHead = head;
	int length = lengthOfList(head);
	for (int i = 0; i < length; i++)
	{
		insertAtBeginning(newList, currentHead->data);
		currentHead = currentHead->next;
	}
	deAllocateMemory(head);
	head = newList;
}

void isListPalindrome(node*& head)
{
	if (head == NULL) return;
	node* newList = nullptr;
	node* currentHead = head;
	int length = lengthOfList(head);
	for (int i = 0; i < length; i++)
	{
		insertAtBeginning(newList, currentHead->data);
		currentHead = currentHead->next;
	}

	for (int i = 0; i < length / 2; i++)
	{
		if (head->data != newList->data)
		{
			cout << "Not A Palindrome" << endl << endl;
			return;
		}
	}
	cout << "Is A Palindrome" << endl << endl;
	deAllocateMemory(newList);
}

void rotateListLeft(node*& head, int k)
{
	int length = lengthOfList(head);
	k = k % length;
	for(int i=1;i<=k;i++)
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
		while (currentHead->next != NULL)
		{
			currentHead = currentHead->next;
		}

		insertAtBeginning(head, currentHead->data);
		deleteLastNode(head);
	}
	cout << "List Rotated" << endl << endl;
}

void displayReverse(node*& head)
{
	reverseList(head);
	displayList(head);
	reverseList(head);
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

node* mergeList(node* list1, node* list2) 
{
	if (list1 == nullptr) return list2;
	if (list2 == nullptr) return list1;

	node* head = list1;
	while (list1->next != nullptr) 
	{
		list1 = list1->next;
	}
	list1->next = list2;

	return head;
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
	insertAtGivenIndex(head, 3, 0);
	
	cout << "Inserting 0s to check function below:" << endl;
	displayList(head);

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

	cout << "Length of List is: " << lengthOfList(head) << endl << endl;


	cout << "Rotating List Left Wards by 3 Units: " << endl;
	rotateListLeft(head, 3);
	displayList(head);

	cout << "Rotating List Left Wards by length(12) Units: " << endl;
	rotateListLeft(head, 12);
	displayList(head);

	cout << "Rotating List Left Wards by length+1(13) Units: " << endl;
	rotateListLeft(head, 13);
	displayList(head);

	cout << "Rotating List Left Wards by length-1(11) Units: " << endl;
	rotateListLeft(head, 11);
	displayList(head);

	cout << "Rotating List RightWards by 12 Units: " << endl;
	rotateListRight(head, 12);
	displayList(head);

	cout << "Rotating List RightWards by 2 Units: " << endl;
	rotateListRight(head, 2);
	displayList(head);

	cout << "List Sorted In Ascending Order: " << endl;
	sortList(head, 1);
	displayList(head);

	cout << "List Sorted In Descending Order: " << endl;
	sortList(head, -1);
	displayList(head);


	cout << "Reversed List: " << endl;
	reverseList(head);
	displayList(head);

	cout << "Display Reversed Without Actually Reversing: " << endl;
	displayReverse(head);

	cout << "Check to see if above list was actually reversed(it should retain previous form)" << endl;
	displayList(head);


	///=======================================================================================================================================

	node* palindrome = nullptr;
	insertAtBeginning(palindrome, 1);
	insertAtBeginning(palindrome, 0);
	insertAtBeginning(palindrome, 0);
	insertAtBeginning(palindrome, 0);

	cout << "List to be checked Palindromic" << endl;
	displayList(palindrome);
	isListPalindrome(palindrome);

	cout << "Merged List: " << endl;
	head=mergeList(head, palindrome);
	displayList(head);

	deleteList(head);

	return 0;
}


