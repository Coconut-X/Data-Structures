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
	vector<node*> lists; 
	int currentListIndex = -1; 
	int choice;

	while (true) 
	{
		cout << "Menu:" << endl;
		cout << "1. Create a new list" << endl;
		cout << "2. Select a list" << endl;
		cout << "3. Display current list" << endl;
		cout << "4. Insert at end" << endl;
		cout << "5. Insert at beginning" << endl;
		cout << "6. Insert at given index" << endl;
		cout << "7. Delete last node" << endl;
		cout << "8. Delete first node" << endl;
		cout << "9. Delete node at given index" << endl;
		cout << "10. Search node" << endl;
		cout << "11. Sort list" << endl;
		cout << "12. Update node data by index" << endl;
		cout << "13. Update node data by value" << endl;
		cout << "14. Find middle node" << endl;
		cout << "15. Find nth node from end" << endl;
		cout << "16. Merge with another list" << endl;
		cout << "17. Reverse list" << endl;
		cout << "18. Check if list is palindrome" << endl;
		cout << "19. Rotate list left" << endl;
		cout << "20. Rotate list right" << endl;
		cout << "21. Display list in reverse" << endl;
		cout << "22. Delete current list" << endl;
		cout << "23. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 23) break;

		if (choice == 1) {
			node* newList = nullptr;
			lists.push_back(newList);
			currentListIndex = lists.size() - 1;
			system("cls");
			cout << "New list created and selected." << endl;
		}
		else if (choice == 2) 
		{
			system("cls");
			int index;
			cout << "Enter list index (0 to " << lists.size() - 1 << "): ";
			cin >> index;
			if (index >= 0 && index < lists.size()) 
			{
				currentListIndex = index;
				cout << "List " << index << " selected." << endl;
			}
			else 
			{
				cout << "Invalid index." << endl;
			}
		}
		else if (currentListIndex == -1) 
		{
			cout << "No list selected. Please create or select a list first." << endl;
		}
		else 
		{
			node*& currentList = lists[currentListIndex];
			switch (choice) 
			{
			case 3:
			{
				system("cls");
				displayList(currentList);
				break;
			}
			case 4: 
			{
				system("cls");
				int data;
				cout << "Enter data: ";
				cin >> data;
				insertAtEnd(currentList, data);
				break;
			}
			case 5: 
			{
				system("cls");
				int data;
				cout << "Enter data: ";
				cin >> data;
				insertAtBeginning(currentList, data);
				break;
			}
			case 6: 
			{
				system("cls");
				int index, data;
				cout << "Enter index and data: ";
				cin >> index >> data;
				insertAtGivenIndex(currentList, index, data);
				break;
			}
			case 7:
			{
				system("cls");
				deleteLastNode(currentList);
			}
				break;
			case 8:
			{
				system("cls");
				deleteFirstNode(currentList);
			}
				break;
			case 9: 
			{
				system("cls");
				int index;
				cout << "Enter index: ";
				cin >> index;
				deleteNodeAtGivenIndex(currentList, index);
				break;
			}
			case 10: 
			{
				system("cls");
				int key;
				cout << "Enter key: ";
				cin >> key;
				searchNode(currentList, key);
				break;
			}
			case 11: 
			{
				system("cls");
				int type;
				cout << "Enter 1 for ascending or -1 for descending: ";
				cin >> type;
				sortList(currentList, type);
				break;
			}
			case 12: 
			{
				system("cls");
				int index, data;
				cout << "Enter index and data: ";
				cin >> index >> data;
				updateNodeDataByIndex(currentList, index, data);
				break;
			}
			case 13: {
				int key, data;
				cout << "Enter key and new data: ";
				cin >> key >> data;
				updateNodeDataByValue(currentList, key, data);
				break;
			}
			case 14:
				findMiddleNode(currentList);
				break;
			case 15: {
				int n;
				cout << "Enter N: ";
				cin >> n;
				findNthNodeFromEnd(currentList, n);
				break;
			}
			case 16: {
				int index;
				cout << "Enter index of list to merge with (0 to " << lists.size() - 1 << "): ";
				cin >> index;
				if (index >= 0 && index < lists.size() && index != currentListIndex) {
					currentList = mergeList(currentList, lists[index]);
					cout << "Lists merged." << endl;
				}
				else {
					cout << "Invalid index or cannot merge with itself." << endl;
				}
				break;
			}
			case 17:
			{
				system("cls");
				reverseList(currentList);
				cout << "List Reversed" << endl << endl;
			}
				break;
			case 18:
			{
				system("cls");
				isListPalindrome(currentList);
			}
				break;
			case 19: 
			{
				system("cls");
				int k;
				cout << "Enter k: ";
				cin >> k;
				rotateListLeft(currentList, k);
				break;
			}
			case 20: 
			{
				system("cls");
				int k;
				cout << "Enter k: ";
				cin >> k;
				rotateListRight(currentList, k);
				break;
			}
			case 21:
			{
				system("cls");
				displayReverse(currentList);
				break;
			}
			case 22:
			{
				system("cls");
				deleteList(currentList);
				cout << "Current list deleted." << endl;
				break;
			}
			default:
				cout << "Invalid choice." << endl;
				break;
			}
		}
	}

	for (auto& list : lists) 
	{
		deAllocateMemory(list);
	}

	return 0;
}
