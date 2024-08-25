//#include<iostream>
//using namespace std;
//int main()
//{
//
/////-----------------------------SORTING ARRAY IN INCREASING ORDER-------------------------//
//
//	///bubble sort is the most easiest way to sort an array
//
//	int a[10] = { 4,2,22,11,65,43,2,0,5,7 };
//	int s = 10;
//
//	for (int i = 0; i < s-1; i++)
//	{
//		if (a[i + 1] < a[i]) ///if next element is smaller, swap them
//		{
//			int temp = a[i + 1];
//			a[i + 1] = a[i];
//			a[i] = temp;
//		}
//	}
//
///// now run the program without looking the next part of the code, just check if output is correct or not and close the console
//	for (int i = 0; i < s; i++)
//		cout << a[i] << " ";
//
//	cout << "\n\n";
///// ye to ghalat output a gye? oops
///// the above code only compares the two element side by side and not one element with all other, so we need another loop
///// 	putting the above code in another loop
//
//	/// now it will run n*n times and sort them in increasing order
//	for (int j = 0; j < s; j++)
//	{
//		for (int i = 0; i < s - 1; i++)
//		{
//			if (a[i + 1] < a[i]) ///if next element is smaller, swap them
//			{
//				int temp = a[i + 1];
//				a[i + 1] = a[i];
//				a[i] = temp;
//			}
//		}
//	}
//
//	///uncomment the code below to see output
//
//
//	///for (int i = 0; i < s; i++)
//		///cout << a[i] << " ";
//		
//
//	///noice hogya na kaam? now write code to sort in decreasing order :)
//
//}