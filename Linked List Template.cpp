#include<iostream>
using namespace std;

//this is just demonstration of how to make linked list generic using templates, you can copy other function from singlyLinkedList.cpp 
// https://github.com/Coconut-X/Data-Structures/blob/master/singlyLinkedList.cpp
//just replace int data to T data to use the function :)

template<typename T> class list
{
public:
	T data;
	list* next;

	using node = list<T>;

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


	void insertAtEnd(node*& head, T data)
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

	void insertAtBeginning(node*& head, T data)
	{
		node* newNode = new node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}


	int lengthOfList(node* head)
	{
		if (head == NULL) return 0;
		int length = 0;
		for (; head != NULL && (head = head->next); length++);

		return length + 1;
	}

	void deleteLastNode(node*& head)
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
		while (currentHead->next != nullptr)
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

};


int main()
{
	list<string>l;
	list<string>* head = nullptr;
	l.insertAtEnd(head, "Ali");
	l.insertAtEnd(head, "Ahmed");
	l.insertAtEnd(head, "Asad");
	l.insertAtBeginning(head, "Ahsan");
	l.displayList(head);

	l.deAllocateMemory(head);


	list<int>l2;
	list<int>* head2 = nullptr;
	l2.insertAtEnd(head2, 1);
	l2.insertAtEnd(head2, 2);
	l2.insertAtEnd(head2, 3);
	l2.insertAtBeginning(head2, 0);
	l2.displayList(head2);

	l2.deleteFirstNode(head2);
	l2.deleteLastNode(head2);
	l2.displayList(head2);

	l2.searchNode(head2, 2);
	l2.searchNode(head2, 5);

	l2.deAllocateMemory(head2);

	return 0;
}
