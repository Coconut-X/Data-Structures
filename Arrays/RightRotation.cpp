//#include<iostream>
//using namespace std;
//int main()
//{
//
//	cout << "SHIFTING ALL ELEMENTS TO RIGHT ONCE\12\12";
//	///we will shift all elements to right once
//	///				  ------------------
//	///				  \/			   |   //move last element to begin 
//	     int a[5] = { 1,  2,  3,  4,  5 };
/////output will be	 5	  1	  2	  3	  4
//		 int size = 5;
//
//		///to move last element to begin, we will hold it in temporary variable
//		int temp = a[size - 1];
//
//	///loop will start shifting from end of array and use decrement
//	for (int i = size - 1; i > 0; i--) ///start from i=size-1 bcz we will shift the last element to first index(a[0]) manually
//	{
//		///now every next element will get value of its previous element 
//
//		a[i] = a[i-1]; 
//
//	}
//	///after loop is complete we will now assign value to zero index
//	a[0] = temp; ///last element moved to beginning
//
//
/////-----DISPLAY-----///
//
//	for (int i = 0; i < size; i++)
//		cout << a[i] << " ";
//
//	cout << endl << endl << endl;
//
/////---------------------------------------------------------------------SHIFTING MORE THAN ONCE--------------------------------------------------------------///
//
//	///now we have shifted all elements to right by one index, what if we want to shift them twice or more?
//	///we will put the above code in another loop which will control how many times we want to shift
//	
//	int numberOfRotations;
//	cout << "SHIFTING MORE THAN ONCE\12\12";
//	cout << "How many times you want to shift: ", cin >> numberOfRotations;
//
//	numberOfRotations = numberOfRotations % size;  ///this is fun part :) explained in end
//
//		//int size = 5;
//		int b[5] = { 1,  2,  3,  4,  5 };
//	for (int rot = 1; rot <= numberOfRotations; rot++)
//	{
//		
//		int temp = b[size - 1];
//
//		for (int i = size - 1; i > 0; i--) 
//		{
//			b[i] = b[i - 1];
//		}
//		///after loop is complete we will now assign value to zero index
//		b[0] = temp; ///last element moved to beginning
//	}
//
//	for (int i = 0; i < size; i++)
//		cout << b[i] << " ";
//
//	///as size is 5, now if u rotate it 5 times it will become the same array as initialized, and the outermost rot loop will run 5 times
//	///it means that the array will repeat itself after every 5 rotations, so if we take mod with size, we will get to now how many times we need to rotate, now if
//	/// i ask it to rotate 5 times, it will take mode 5%5=0, it means we dont have to rotate it and rot loop will not run and display array as it is
//	/// another example rotating the array 7 times is same as rotating it 2 times as 7%5=2, so by taking mod with size we can achieve rotation in less loops :)
//
//	return 0;
//}