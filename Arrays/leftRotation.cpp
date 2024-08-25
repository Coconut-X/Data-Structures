//#include<iostream>
//using namespace std;
//int main()
//{
//
//	///FIRST CHECK RIGHT ROTATION CPP THEN COME TO THIS ONE
//
//	cout << "SHIFTING ALL ELEMENTS TO LEFT ONCE\12\12";
//
/////				 -----------------
/////				 |				\/
//	int a[5] = { 1  ,2  ,3  ,4  ,5 };  ///each element will get next element
/////output		 2	 3	 4	 5	 1
//	int size = 5;
//	///as we have to move first element to last, hold it in temp
//	int temp = a[0];
//	for (int i = 0; i < size - 1; i++) ///i<size-1 will not access last element bcz we will manually assign it equal to first element
//	{
//		a[i] = a[i + 1]; ///each element will get next element
//	}
//
//	///set last element to temp
//	a[size - 1] = temp;
//
//	for (int i = 0; i < size; i++)
//		cout << a[i] << " ";
//
//
//	///now rotate it multiple times yourself
//
/////----------------------------------------------------------------SHIFTING MORE THAN ONCE--------------------------------------------------///
//	///YOUR CODE HERE
//
//
//
//	return 0;
//}