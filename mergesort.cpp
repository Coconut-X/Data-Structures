// #include<iostream>
// using namespace std;

// void merge(int arr[], int l, int m, int r) {
//     int n1 = m - l + 1;
//     int n2 = r - m;
//     int L[n1], R[n2];
//     for(int i = 0; i < n1; i++) {
//         L[i] = arr[l + i];
//     }
//     for(int i = 0; i < n2; i++) {
//         R[i] = arr[m + 1 + i];
//     }
//     int i = 0, j = 0, k = l;
//     while(i < n1 && j < n2) {
//         if(L[i] <= R[j]) {
//             arr[k++] = L[i++];
//         } else {
//             arr[k++] = R[j++];
//         }
//     }
//     while(i < n1) {
//         arr[k++] = L[i++];
//     }
//     while(j < n2) {
//         arr[k++] = R[j++];
//     }
// }


// void mergeSort(int arr[], int l, int r) {
//     if(l < r) {
//         int m = l + (r - l) / 2;
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);
//         merge(arr, l, m, r);
//     }
// }


// int main() {
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     mergeSort(arr, 0, n - 1);
//     for(int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


// Time Complexity: O(nlogn)
//because the merge sort always divides the array into two halves and takes linear time to merge two halves.    

// Space Complexity: O(n)
//because we are using extra space for the temporary arrays.

// The merge sort is a recursive algorithm and time complexity can be expressed as the following recursive relation:
// T(n) = 2T(n/2) + O(n)
// The above relation can be solved either using the Recurrence Tree method or the Master method. It falls in case II of Master Method and the solution of the recurrence is Theta(nLogn). Time complexity of Merge Sort is O(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

// Auxiliary Space: O(n)
// Algorithm is In-place: No
// Stable: Yes
// Due to the uses of extra space, this algorithm is not in-place. This is the main disadvantage of the merge sort. The merge sort is a stable sort, which means that the same element in an array maintains its position relative to the other elements with the same value.

// Applications of Merge Sort
// Merge Sort is useful for sorting linked lists in O(nLogn) time. In the case of linked lists, the case is different mainly due to the difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory. Unlike an array, in the linked list, we can insert items in the middle in O(1) extra space and O(1) time. Therefore, the merge operation of merge sort can be implemented without extra space for linked lists.

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l,int m, int r)
{
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int k = l;

    int i=0,j=0;
    int leftSize=left.size();
    int rightSize=right.size();

    while(i<leftSize and j< rightSize)                  //merge the two halves
        arr[k++]=(left[i]<=right[j]?left[i++]: right[j++]);

    while(i<leftSize)                                   //if any element left in left half
        arr[k++]=left[i++];

    while(j<rightSize)                                  //if any element left in right half
        arr[k++]=right[j++];

}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);                   //recursive call to split the left half
        mergeSort(arr, m + 1, r);               //recursive call to split the right half
        merge(arr, l, m, r);                    //merge the two halves
    }
}

int main()
{

    vector<int> arr = {12, 11, 13, 5, 6, 7, 1, 2, 3, 4, 8 };
   
    int n = arr.size();
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }



    return 0;
}
