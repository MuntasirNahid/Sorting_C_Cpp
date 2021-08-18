/*
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
The array is virtually split into a sorted and an unsorted part.
Values from the unsorted part are picked and placed at the correct position in the sorted part.
Algorithm:
To sort an array of size n in ascending order:
1: Iterate from arr[1] to arr[n] over the array.
2: Compare the current element (key) to its predecessor.
3: If the key element is smaller than its predecessor, compare it to the elements before.
Move the greater elements one position up to make space for the swapped element.
*/
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j]; //1 step dane niye gelam big element takey.
			j--;
		}
		arr[j + 1] = key; //j er man komtey komtey thik jaygay ashley key takey boshaya dibo.
	}
}

int main()
{
	int n, m;
	int arr[] = {12, 11, 13, 5, 6};
	n = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, n);
	cout << "The Array After Insertion Sort:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " \n"[i == n - 1];//if(i==n-1)
}

/*
Insertion sort takes maximum time to sort if elements are sorted in reverse order.
And it takes minimum time (Order of n) when elements are already sorted.

Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
*/
