#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//THIS CODE ONLY CONTAINS THE ADDING AND SEARCHING OF ELEMENTS AS IT IS MEANT TO EXPLAIN THE BASICS AND WORKING OF HASHING

class HashTable{
public:
	int** table;
	int* rowLength;
	int size;
	int currentSize = 0;

	HashTable(int size) : size(size) {
		rowLength = new int[size];
		table = new int* [size];
		for (int i = 0; i < size; i++) {
			table[i] = new int [1];
			table[i][0] = -1;
			rowLength[i] = 0;
		}
	}

	static int hash(int key, int size) {
		return key % size;
	}

	void search(int key) {
		//using binary search in each row

		int index = hash(key, size);
		int left = 0;
		int right = rowLength[index] - 1;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (table[index][mid] == key) {
				cout << "Found at index [" << index << "][" << mid <<"]"<< endl;
				return;
			}
			else if (table[index][mid] < key) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}


	void printAll() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < rowLength[i]; j++) {
				cout << table[i][j] << " ";
			}
			cout << endl;
		}
	}


	
	void add(int key) {
		int index = hash(key, size);
		int* temp = new int[rowLength[index] + 1];
		int i = 0;
		//sort
		while (i < rowLength[index] && table[index][i] < key) {
			temp[i] = table[index][i];
			i++;
		}

		temp[i] = key;  
		while (i < rowLength[index]) {
			temp[i + 1] = table[index][i];
			i++;
		}

		delete[] table[index];
		table[index] = temp;
		rowLength[index]++;
	}


	~HashTable() {
		for (int i = 0; i < size; i++) {
			delete[] table[i];
		}
		delete[] table;
	}
};


int main()
{
// YOU CAN CREATE A MENU DIRVER FOR ADDING OR SEARCHING
	HashTable hashTable(10);
	hashTable.add(10);
	hashTable.add(11);
	hashTable.add(12);
	hashTable.add(13);
	hashTable.add(14);
	hashTable.add(15);
	hashTable.add(16);
	hashTable.add(17);
	hashTable.add(18);
	hashTable.add(28);
	hashTable.add(19);
	hashTable.add(20);
	hashTable.add(21);
	hashTable.add(22);
	hashTable.add(23);
	hashTable.add(24);
	hashTable.add(25);
	hashTable.add(26);
	hashTable.add(27);
	hashTable.add(28);
	hashTable.add(29);
	hashTable.add(30);
	hashTable.add(31);
	hashTable.add(32);
	hashTable.add(33);



	hashTable.printAll();
	hashTable.search(33);
	

	return 0;
}
