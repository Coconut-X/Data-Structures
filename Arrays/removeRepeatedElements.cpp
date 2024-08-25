//#include<iostream>
//using namespace std;
//int main()
//{
//
//	int a[20] = { 1,5,2,7,4,9,2,4,8,3,22,54,22,7,0,2,9,12,14,51 };
//	int size = 20;
//	int nonRepeated[20]; 
//
//	int index = 0;
//
//	for (int i = 0; i < size; i++)
//	{
//		bool found = false;
//
//		for (int j = 0; j < index; j++)
//		{
//			if (a[i] == nonRepeated[j])
//			{
//				found = true;
//				break;
//			}
//		}
//		if (!found) nonRepeated[index++] = a[i];
//	}
//
//	cout << "Unique Elements: \n";
//
//	for (int i = 0; i < index; i++)
//		cout << nonRepeated[i] << " ";
//
//
//	return 0;
//}