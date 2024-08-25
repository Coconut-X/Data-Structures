//#include<iostream>
//using namespace std;
//int main()
//{
//	
//	int a1[5] = { 1,2,3,4,5 };
//	int a2[7] = { 1,3,5,7,9,0,5 };
//	int s1 = 5, s2 = 7;
//
//	///int union[5 + 7]; u cant use name union as it is keyword
//
//	int Union[5 + 7]; ///max length can be sum of size of two arrays 
//
//	///transfer all elements of bigger array to Union and make sure element is not repeated
//
//	int UnionIndex = 0;
//	for (int i = 0; i < s2; i++)
//	{
//		bool found = false;/// to check wether the element is already present in Union
//		for (int j = 0; j < UnionIndex; j++)
//		{
//			if (a2[i] == Union[j])
//			{
//				found = true;
//				break;
//			}
//		}
//		if (!found) Union[UnionIndex++] = a2[i]; ///if element is not found, add it it union
//	}
//
//	///now moving elements of smaller array to union
//
//
//	for (int i = 0; i < s1; i++)
//	{
//		bool found = false;/// to check wether the element is already present in Union
//		for (int j = 0; j < UnionIndex; j++)
//		{
//			if (a1[i] == Union[j])
//			{
//				found = true;
//				break;
//			}
//		}
//		if (!found) Union[UnionIndex++] = a1[i]; ///if element is not found, add it it union
//
//	}
//
//
//	cout << "UNION OF TWO ARRAYS IS:\n";
//
//	for (int i = 0; i < UnionIndex; i++)
//		cout << Union[i] << " ";
//
//	///now apply bubble sort on union and print in ascending order
//
//
//
//	return 0;
//}