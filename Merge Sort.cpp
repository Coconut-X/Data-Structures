#include<iostream>
using namespace std;

int* merge(int* &arr, int l, int m, int r,int s) {
	int k = 0;

	if (arr[l] > arr[m + 1])
	{
		int* temp = new int[s];

		for (int i = m + 1; i <= r; i++)
		{
			temp[k++] = arr[i];
		}

		for (int i = l; i <= m; i++)
		{
			temp[k++] = arr[i];
		}

		//copy remaining as it is
		/*for (int i = r + 1; i < s; i++)
		{
			temp[k++] = arr[i];
		}*/
		//updated: no need to copy remaining :)

    //copy back to arr and delete temp
		for (int i = l; i <= r; i++) {
			arr[i] = temp[i - l];
		}

		delete[] temp;


	}

		return arr;

}

void mergeSort(int* &arr, int l, int r,int s) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m,s);
		mergeSort(arr, m + 1, r,s);
		arr=merge(arr, l, m, r,s);
	}

}

void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << (i != n - 1 ? ", " : "\n\n");
	}
}

int main()
{
	int* arr = new int[10] { 5, 4, 3, 2, 1, 10, 9, 8, 7, 6 };
	mergeSort(arr, 0, 9, 10);
	print(arr, 10);

	delete[] arr;
	return 0;
}
