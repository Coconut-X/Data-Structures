//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[22] = { 4,6,8,1,5,2,8,0,2,4,2,6,5,10,9,6,2,6,8,10,0,14 };
//	int s = 22;
//
/////OUR APPROACH
/////-->bubble sort them in ascending order
/////-->pick one element
/////-->iterate through the array until new element is found, and if element is same, increment its frequency
/////-->set frequency=0 for each new integer
//
//	for(int j=0;j<s;j++)
//		for (int i = 0; i < s-1; i++)
//			if (a[i + 1] < a[i]) swap(a[i + 1], a[i]);
//
//	cout << "After Sorting\n";
//
//	for (int i = 0; i < s; i++)
//		cout << a[i] << " ";
//	cout << "\n\n";
//
/////take two arrays to store unique elements and their frequency respectively
//	int unique[22], freq[22];
//	int index = 0, frequency = 1; ///each element will have atleast one frequency, so dont initialize it to 0 :)
//
//
//	for (int i = 0; i < s-1; i++)
//	{
//		if (a[i] == a[i + 1]) 
//		{
//			frequency++;
//		}
//		if (a[i] != a[i + 1])	///if next element is new element, store the old element in unique and its frequency in freq, increment index and set frrequency =1 again
//		{
//			unique[index] = a[i];
//			freq[index++] = frequency; ///store frequency in array increment the index
//			frequency = 1;
//		}
//
//	}
//
//	/// handle the last element
//	unique[index] = a[s - 1];
//	freq[index] = frequency;
//
//	/*
//	->	We loop through the array elements until the second last element (i < s - 1) because we compare each element with the next one (a[i + 1]).
//	->	Inside the loop, when we find a new unique element (i.e., when a[i] != a[i + 1]), we store the unique element and its frequency in the unique and freq arrays, respectively.
//	->	After the loop, we handle the last element separately. 
//	->	We assign the last unique element (a[s - 1]) to the unique array at the index position and its corresponding frequency to the freq array at the same position.
//	->	This ensures that the last element is properly handled and its frequency is correctly counted
//	*/
//
//	cout << "Elements	Frequency\n";
//
//	for (int i = 0; i <=index; i++)
//	{
//		cout << unique[i] << "\t\t" << freq[i] << endl << "---------------------\n";
//	}
//
//		
//	///------INTEGER WITH MAX FREQUENCY----------///
//
/////-> take variable 
/////->traverse the frequency array
/////->find max frequency and store its index in variable
/////->print the corresponding element at index of unique array
//
//	int maxIndex = 0;
//	for (int i = 0; i < index; i++) 
//		if (freq[i] > freq[maxIndex]) 
//			maxIndex = i;
//		
//	cout << "\n\nElement with max frequency is " << unique[maxIndex] << " with frequency of " << freq[maxIndex];
//
//
/////notice that both 2 and 6 have highest frequency of 4, but only 2 is printed
/////modify the above code that solve this problem :_)
/////Hint--> take an array maxElement and maxFreq 
//
//	return 0;
//}