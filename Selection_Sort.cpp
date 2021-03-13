/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element
 (considering ascending order) from unsorted part and putting it at the beginning.
  The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.(in left end)
2) Remaining subarray which is unsorted.(in right end)

In every iteration of selection sort, the minimum element (considering ascending order)
 from the unsorted subarray is picked and moved to the sorted subarray.

 **every time min element takey khuje ber kore 1st position e boshaya dey..
*/
#include<bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_indx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_indx])
				min_indx = j;
		}
		swap(&arr[min_indx], &arr[i]);
	}
}

int main()
{
	int n, m;
	int arr[] = {12, 11, 13, 5, 6};
	n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "The Array After Selection Sort:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " \n"[i == n - 1];//if(i==n-1)
}