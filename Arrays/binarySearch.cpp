//#include<iostream>
//using namespace std;
//int main()
//{
//	///binary search demands that the given array must be sorted first
//
//
//	int a[10] = { 2,5,1,8,45,78,32,23,6,4 };
//	int size = 10;
//	int key = 78; ///element to search
//
//
//	///bubble sorting the array in ascending order
//	for (int i = 0; i < size; i++)
//		for (int j = 0; j < size - 1 - i; j++)
//			if (a[j] > a[j + 1])swap(a[j], a[j + 1]);
//
//
//	//for (int i = 0; i < size; i++)
//		//cout << a[i] << " ";
//
/////---------------------------------------------------------------BINARY SEARCH----------------------------------------------------------///
//
///// look for element in mid of array
///// if it is not in middle, then check if that middle element is greater or smaller than our key
///// if it is smaller, it means our key should be somewhere between middle index and end index, so our end will remain same but we will increment our start
///// if it is greater, it means our key is somewhere between start and middle index, so we will decrement the end to check the left half or array
//
//	int start = 0, end = size - 1;
//
//	cout << endl;
//	for (int i = start; start <= end; i++)
//	{
//		int mid = (start + end) / 2; ///formula to calculate mid
//		if (a[mid] == key)
//		{
//			cout << "Key " << key << "  found at index " << mid;
//			break;
//		}
//		else if (a[mid] > key) end--;
//
//		else start++;
//	}
//
//
///*
//
//suppose we have array   1  2  3  4  5  6  7  8  9
//we have to find 3
//first we check mid element which is 5; as 5 is not equal to 3, and 5 is greater than 3, it means our key is at left side of 5
//so our end will become end=3, and start is still =0, means we have to find key in this portion of array -> 1  2  3  4
//now mid index will be 0+3/2=1.5=1
//it will check element 2 at index 1
//as 2 is not equal to 3 and 2<3, it means our key is somewhere between 3-4 
//so we will set start=2 and end is still at 3
//our next mid index will be 2+3/2 =2.5=2
//the element at index to is 3, hence found :)
//
//
//*/
//
/////TASK -> modify above code to show msg of not found if element doesnt exist in array
/////Hint: use bool
//
//	return 0;
//}