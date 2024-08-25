//#include<iostream>
//using namespace std;
//int main()
//{
//	int array[5]; ///always initialize SIZE
//
//
/////-------INPUT--------///
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "Enter element " << i + 1 << " : ", cin >> array[i];///no need to write cout and cin in two diff lines, just put ","(comma) between them in single line
//		///									 this comma
//	}
//
/////--------OUTPUT--------///
//
//	for (int j = 0; j < 5; j++)
//	{
//		cout << "Element " << j + 1 << " : " << array[j] << endl;
//	}
//
//
/////=============================================================================================================================///
//
//
//	///----TAKE INPUT TILL SPECIFIC INDEX---///
//
//
//	int arr[100]; 
//	int size=0;
//	cout << "Press -99 to stop inputting\12";  ///NEW THING TO LEARN -> \12 is equal to endl or \n;
//
//
//	for (int i = 0; i < 100 && arr[i] != -99; i++)
//	{
//		cout << "Enter element " << i + 1 << " : ", cin >> arr[i];
//		if (arr[i] != -99) size++;   ///only increment size if its not equal to -99
//		else break; /// no need to check if(array[i]==-99) separately
//	}
//
//	for(int i=0;i<size;i++) 
//		cout << "Element " << i + 1 << " : " << arr[i] << endl;
//
//
//	return 0;
//}