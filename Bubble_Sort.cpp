
/*
The bubble sort is one of the simplest sorting algorithms, but not one
of the most efficient.
It puts a list into increasing order by successively comparing adjacent
elements, interchanging them if they are in the wrong order.
To carry out the bubble sort, we perform the basic operation, that is, interchanging
a larger element with a smaller one following it, starting at the beginning of the list,
for a full pass. We iterate this procedure until the sort is complete.

*/
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(float arr[], int n)
{
	for (int i = 0; i < n - 1; i++) //last element sorted hoye jay 1 iteration er por por e..
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				float temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n, m;
	float arr[] = {1, 2.30, 3.45, 4, 1, -2, 29, 9.0};
	n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	cout << "The Array After Bubble Sort:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " \n"[i == n - 1];//if(i==n-1)then '\n' will execute..else ' '(blank space)will execute.


}
