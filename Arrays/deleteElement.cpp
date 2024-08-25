//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int size = 10;
//
//	cout << "Your Array is \n\n";
//	for (int i = 0; i < size; i++)
//		cout << a[i] << " ";
//
//	cout << "\n\n";
//
//
//
//	int index;
//	cout << "Which index to delete(0-9): ", cin >> index;  ///note that it is index starting from 0, index 0 pr 1 para hua ha or index 9 pr 10
//
//	///now we know we cant really delete the element but we can replace it with next element and it will be overwritten
//
//	for (int i = index; i < size-1; i++)  ///start loop from where we want to delete, do size-1 bcz we will access i+1, this will prevent out of bounds
//	{
//		a[i] = a[i + 1];
//	}
//	///after the loop all elements have moved back(left shift) and the element to be deleted has been overwritten
//
//
//	///dont forget to decrement the size as one element is been deleted, if u forget to do it the number at the end of array will be printed twice
//	size--;
//	cout << "\n Array after deletion\n ";
//	for (int i = 0; i < size; i++)
//		cout << a[i] << " ";
//
//
/////TASK :  write code that asks user to input the exact number to be deleted, then loop through the array to find the element, if it is found store its index in variable
//	/// and then delete it, also check if the number doesnt exist in the array
//
//
//
//	return 0;
//}