//Left and Right dhorey dhorey compare korey thake..left<right holey left fixed dhorey right-- kora hoy..
//left>right holey swap kora hoy..
//swap korar por right rtakey fixed dhorey left++ kora hoy..
//swap korar por sliding direction change hoye jabey..
//divide and conquer method use korey sort kora hoy.
//left=right hoye geley amra pivot point peye gechi..
//pivot er left side er sublist er shob element pivot er ceye choto..
//pivot er right side er shob element pivot er ceye boro.
//left=right same index hoye geley(ektai element pivot er left or right side e) return korey dibo..beacuse tokhn array ta sorted..

#include<bits/stdc++.h>
#define sz 1000
using namespace std;
int partition(int arr[], int left, int right)
{
	bool r = true;
	while (left < right)
	{
		if (arr[left] > arr[right])
		{
			swap(arr[left], arr[right]);
			r ^= 1; //x-or korey dicchi..if(r)r=false,else if (!r)r=true;
		}
		if (r)
			right--;
		else
			left++;

	}
	return left;
}
void quickSort(int arr[], int left, int right)
{
	if (left >= right)return;
	int p = partition(arr, left, right); //kon position e dita vage vag korlo shei position ta..pivot position
	
	quickSort(arr, left, p - 1);
	
	quickSort(arr, p + 1, right);

}
int main()
{
	int n, i, arr[sz];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	cout << "The Array After QuickSOrt : " << endl;
	for (i = 0; i < n; i++)
		cout << arr[i] << " \n"[i == n - 1];
}
/**
12
44 33 -11 55 77 90 40 60 99 22 88 66
*/