//#include<iostream>
//using namespace std;
//int main()
//{
//	int a1[5] = { 1,2,3,4,5 };
//	int a2[7] = { 1,3,5,7,9,0,5 };
//	int s1 = 5, s2 = 7;
//
//	int intersection[5]; ///max possible common elements can be equal to size of smaller array
//
//
//	///We will find elements of smaller array in bigger array
//	/// first loop will hold elements of a1 and inner loop will iterate through elements of a2 and compare them
//
//	/// we will also need another pointer to keep note of index of intersection
//
//	int interIndex = 0;
//	for (int i = 0; i < s1; i++)
//	{
//		for (int j = 0; j < s2; j++)
//		{
//			if (a1[i] == a2[j]) intersection[interIndex++] = a1[i];
//			/// no need to do this-> intersection[interIndex], interIndex++
//		}
//	}
//	///run to code to see output
//
//	cout << "Common elements are: \n";
//	for (int i = 0; i < interIndex; i++)
//		cout << intersection[i] << " ";
//
//	///the element 5 is repeated twice, write a new code to check if element already exists in intersection, if it exists...dont add it in new array
//	///hint-> add another nested loop inside the if statement and use bool
//
//	return 0;
//}