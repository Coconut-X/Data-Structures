#include<iostream>
#include<string>
using namespace std;

struct node {
public:
	int data;
	node* prev;
	node* next;
};

void insertAtEnd(node*& head, int data)
{
	node* currentHead = head;

	node* newNode = new node;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
		return;
	}

	while (currentHead->next != NULL)
	{
		currentHead = currentHead->next;
	}
	currentHead->next = newNode;
	newNode->prev = currentHead;
	newNode->next = nullptr;

	cout << "Value Inserted At Tail" << endl;
}

void displayList(node* head)
{
	if (head == nullptr)
	{
		cout << "List Is Empty!" << endl << endl;
		return;
	}

	while (head != nullptr)
	{
		cout << head->data << ((head->next != nullptr) ? ", " : "\n\n");
		head = head->next;
	}
}

int lengthOfList(node* head)
{
	if (head == NULL) return 0;
	int length = 0;
	for (; head != NULL && (head = head->next); length++);
	return length + 1;

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

void insertAtBeginning(node*& head, int data)
{
	node* newNode = new node;
	newNode->data = data;
	if (head != nullptr) 
	{
		head->prev = newNode;
	}
	newNode->next = head;
	newNode->prev == nullptr;
	head = newNode;
	cout << "Value Inserted At Head" << endl;
}

void insertAtGivenIndex(node*&head, int index, int data)
{
	if (index > lengthOfList(head) - 1)
	{
		cout << "Invalid Index!" << endl << endl;
		return;
	}
	if (index == 0)
	{
		insertAtBeginning(head, data);
		return;
	}
	
	node* current = head;
	node* newNode = new node;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	//cout << "here";

	for (int i = 0; i < index-1 ; i++)
	{
		current = current->next;
		//cout <<"oo"<< current->data << endl;
	}

	newNode->next = current->next;
	current->next = newNode;
	newNode->prev = current;
	cout << "Value Inserted At Given Index" << endl;
	
}

void deleteFirstNode(node*& head)
{
	if (head == NULL)
	{
		cout << "List Is Empty!" << endl;
		return;
	}

	node* temp = head;
	head = head->next;
	delete temp;
	head->prev = nullptr;
	cout << "First Node Deleted " << endl;
}

void deleteLastNode(node*& head)
{
	if (head == NULL)
	{
		cout << "List Is Empty!" << endl;
		return;
	}

	if (head->next == NULL)
	{
		deleteFirstNode(head);
		return;
	}

	node* current = head;
	node* previous = nullptr;
	while (current->next != nullptr)
	{
		previous = current;
		current = current->next;
	}

	previous->next = nullptr;
	previous->prev = current->prev->prev;
	delete current;
	
	cout << "Tail Node Deleted" << endl;
}

void displayPrevAndNext(node* head) 
{
	node* current = head;

	while (current != nullptr) {
		cout << "Previous: " << ((current->prev == nullptr) ? "NULL" : to_string(current->prev->data))
			<< "		Current: " << current->data
			<< "		Next: " << ((current->next == nullptr) ? "NULL" : to_string(current->next->data))
			<< endl;
		current = current->next;
	}
}

void deleteAtGivenIndex(node*& head, int index)
{
	int length = lengthOfList(head) - 1;
	if (index > length)
	{
		cout << "Invalid Index" << endl;
		return;
	}
	node* current = head;
	node* previous = nullptr;
	for (int i = 0; i < index; i++)
	{
		previous = current;
		current = current->next;
	}

	previous->next = current->next;
	current->next->prev = previous;
	delete current;

}

void searchNode(node* head, int key)
{
	node* temp = head;
	int i = 0;
	bool found = 0;
	while (temp != NULL)
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

void findMiddleNode(node* head) 
{
	if (head == NULL) {
		cout << "List Is Empty..!" << endl << endl;
		return;
	}

	int length = lengthOfList(head);
	node* current = head;

	for (int i = 0; i < length / 2 ; i++) 
	{
		current = current->next;
	}

	if (length % 2 == 0) 
	{
		cout << "Middle Nodes Are: " << current->prev->data << ", " << current->data << endl << endl;
	}
	else {
		cout << "Middle Node is : " << current->data << endl << endl;
	}
}

void sortList(node*& head, int type)
{
	if (head == nullptr)
	{
		cout << "List Is Empty" << endl;
		return;
	}

	int length = lengthOfList(head) ;

	for (int i = 0; i < length; i++)
	{
		bool found = 0;
		node* current = head;
		node* NextNode = head->next;

		for (int j = 0; j < length - 1 - i; j++)
		{

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

		if (!found)
		{
			cout << "List Sorted" << endl;
			return;
		}
	}
}

void isListPalindrome(node* head)
{
	node* end = head;
	node* prevEnd = nullptr;
	while (end->next != nullptr)
	{
		prevEnd = end;
		end = end->next;
	}

	end->prev = prevEnd;
	///now we have reached the end of list

	/*cout << "END: " << end->data << endl;
	cout << "PREV: " << end->prev->data << endl;*/

	int length = lengthOfList(head)-1;
	node* current = head;
	for (int i = 0; i < length / 2; i++)
	{
		if (current->data != end->data)
		{
			cout << "Not A Palindrome" << endl;
			return;
		}
		current = current->next;
		end = end->prev;
	}
	cout << "Is A Palindrome" << endl;

}

void reverseList(node*& head)
{
	node* newList = nullptr;
	//newList->prev = nullptr;

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

void findNthNodeFromEnd(node* head, int N) ///assuming 1th node from end is last node
{
	if (head == NULL)
	{
		cout << "List Is Empty!" << endl << endl;
		return;
	}
	

	int length = lengthOfList(head);
	if (N == 0 || N > length)
	{
		cout << "Invalid Index" << endl;
		return;
	}

	for (int i = 0; i < length - N   && (head = head->next); i++);

	cout << N << "th Node From End is:  " << head->data << endl << endl;

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

	if (currentHead == NULL) return;
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
	while (currentHead != NULL)
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
		while (currentHead->next != NULL)
		{
			currentHead = currentHead->next;
		}

		insertAtBeginning(head, currentHead->data);
		deleteLastNode(head);
	}
	cout << "List Rotated" << endl << endl;
}

void displayReverse(node* head)
{
	node* end = head;
	end->prev = nullptr;
	node* prevEnd = nullptr;
	while (end->next != nullptr)
	{
		prevEnd = end;
		end = end->next;
	}

	end->prev = prevEnd;

	while (end != nullptr)
	{
		cout<<end->data<< ((end->prev != nullptr) ? ", " : "\n\n");
		end = end->prev;
	}

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
	list2->prev = list1;

	return head;
}

void expandListArray(node**& lists, int& capacity)
{
	int newCapacity = capacity * 2;
	node** newLists = new node * [newCapacity];

	for (int i = 0; i < capacity; ++i) {
		newLists[i] = lists[i];
	}

	delete[] lists;
	lists = newLists;
	capacity = newCapacity;
}


int main()
{
	int capacity = 2;
	node** list = new node * [capacity];
	list[0] = nullptr;
	list[1] = nullptr;

	for(int i=0;i<=5;i++)
		insertAtBeginning(list[0], i);

	cout << "List 1" << endl;
	displayList(list[0]);

	for (int i = 6; i <= 10; i++)
		insertAtBeginning(list[1], i);

	cout << "List 2" << endl;
	displayList(list[1]);

	list[0] = mergeList(list[0], list[1]);

	cout << "Merged List: " << endl;
	displayList(list[0]);

	cout << "Reversed: " << endl;
	reverseList(list[0]);
	displayList(list[0]);


	deAllocateMemory(list[0]);
	
	//deAllocateMemory(head);

	return 0;
}
