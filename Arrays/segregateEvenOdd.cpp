//#include<iostream>
//using namespace std;
//int main()
//{
//	
//	int arr[7] = { 12,34,45,9,8,90,3 };
//	int size = 7;
//	
//	int even = 0, o = 0;
/////=====================================================================================
//	///this piece of code can be optimized by using just one loop, try it in the end
//
//	for (int i=0;i<size ;i++)    
//	{
//		for (int j = i + 1; j<size; j++)
//		{
//			if (arr[i] % 2 != 0 && arr[j] % 2 == 0)
//				swap(arr[i], arr[j]);		
//		}
//	}
/////=====================================================================================
//
//
//	cout << "Even at left and odd at right:\n";
//	for (int i = 0; i < size; i++)cout << arr[i] << "  ";
//
/////now sort even and odd in ascending order
//	
//	for (int i = 0; i < size; i++)  ///count number of even/odd elements
//	{
//		if (arr[i] % 2 == 0)even++;
//		///here odd can also be calculated by size-even
//		else o++;
//	}
//	///elements from 0 to even-1 are even and from even to size are odd
//
//	for (int i = 0; i < even-1; i++) ///sorting even
//	{
//		for (int j = i + 1; j < even; j++)
//			if (arr[i] > arr[j])swap(arr[i], arr[j]);
//	}
//
//
//	for (int i = even; i < size-1; i++)///sorting odd 
//	{
//		for (int j = i + 1; j < size; j++)
//			if (arr[i] > arr[j])swap(arr[i], arr[j]);
//	}
//
//	cout << "\n\nIn Ascending Order\n";
//	for (int i = 0; i < size; i++)cout << arr[i] << "  ";
//
//	return 0;
//}