//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[22] = { 4,6,8,1,5,2,8,0,2,4,2,6,5,10,9,6,2,6,8,10,0,14 };
//	int s = 22;
//
//	///OUR APPROACH
//	///-->bubble sort them in ascending order
//	///-->pick one element
//	///-->iterate through the array until new element is found, and if element is same, increment its frequency
//	///-->set frequency=0 for each new integer
//
//	for (int j = 0; j < s; j++)
//		for (int i = 0; i < s - 1; i++)
//			if (a[i + 1] < a[i]) swap(a[i + 1], a[i]);
//
//	cout << "After Sorting\n";
//
//	for (int i = 0; i < s; i++)
//		cout << a[i] << " ";
//	cout << "\n\n";
//
//	///take two arrays to store unique elements and their frequency respectively
//	int unique[22], freq[22];
//	int index = 0, frequency = 1; ///each element will have atleast one frequency, so dont initialize it to 0 :)
//
//
//	for (int i = 0; i < s - 1; i++)
//	{
//		if (a[i] == a[i + 1])
//		{
//			frequency++;
//		}
//		if (a[i] != a[i + 1])	///if next element is new element, store the old element in unique and its frequency in freq, increment index and set frequency =1 again
//		{
//			unique[index] = a[i];
//			freq[index++] = frequency; ///store frequency in array increment the index
//			frequency = 1;
//		}
//	}
//
//	/// handle the last element
//	unique[index] = a[s - 1];
//	freq[index] = frequency;
//
/////now we will sort the frequency array in decreasing order and also update the corresponding elements in unique array
//
//	for (int j = 0; j < index; j++)
//		for (int i = 0; i < s - 1; i++)
//			if (freq[i + 1] > freq[i]) swap(freq[i + 1], freq[i]), swap(unique[i + 1], unique[i]); ///also swap unique as freq stores the corresponding frequency of each element in unique
//
//
/////now we have to print each element in unique array the number of times its frequency
//	cout << "\n\nSorted By Frequency\n\n";
//	for (int i = 0; i < index; i++) ///controls each unique element
//	{
//		for (int j = 0; j < freq[i]; j++)///control the number of times each element should be printed
//		{
//			cout << unique[i] << " ";
//		}
//	}
//
//	return 0;
//}