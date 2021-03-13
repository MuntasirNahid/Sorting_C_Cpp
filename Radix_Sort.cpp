//bucket create korey korey sort korey thake..
//LSB theke sort kortey kortey MSB porjonto sort korey thake.
//Reject alada ekta bucket create korey thake..otirikto digit jegulay ache shegulake reject bucket e fele dey..
//count sort use korey kora jay...any kind of sort use kora jay..
//negative number er jonno possible na..
#include<bits/stdc++.h>
using namespace std;
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > mx)
			mx = arr[i];

	}
	return mx;
}
void countSort(int arr[], int n, int exp)
{
	int output[n];
	int i,count[10] = {0};
	for (i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}


}

void radixSort(int arr[], int n)
{
	int m = getMax(arr, n); // Find the maximum number to know number of digits

	// Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
	for (int exp = 1; (m / exp) > 0; exp *= 10)
		countSort(arr, n, exp);
}
int main()
{
	int n, m;
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	n = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, n);
	cout << "The Array After Radix Sort:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " \n"[i == n - 1];//if(i==n-1)
}

