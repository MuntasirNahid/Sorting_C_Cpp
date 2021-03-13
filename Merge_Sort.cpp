//Merge Sort is a Divide and Conquer algorithm. 
//It divides the input array into two halves, calls itself for the two halves,
// and then merges the two sorted halves.

//Best,worst and average case er moddhe etar complexity = nlogn.
//n/2,duita sublist create hoy..ekota left theke including n/2,arekta (n/2)+1 theke right porjonto.
//evabe sublist bartey bartey 1 ta kore element(per sublist er moddhe) hoye jay..
//erpor merge kora start hoye jay..
//ekta pointer rekhe prottek ta sublist sort korey korey(compare korey korey) upore uthatey hobe..
//jei sublist e choto pabey shei sublist er pointer ++ korey abar compare onno sublist er pointer er sathey..
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr, int st, int en, int mid)
{
	vector<int>temp(arr.size());
	int i, j;
	for (i = 0; i < arr.size(); i++)
	{
		temp[i] = arr[i];
	}
	int n = mid - st + 1, m = en - mid, k = st;
	i = j = 0;
	while (i < n && j < m)
	{
		if (temp[st + i] <= temp[mid + 1 + j])

			arr[k++] = temp[st + i++];

		else
			arr[k++] = temp[mid + 1 + j++];

	}
	while (i < n)//baki subarray takey(jodi thakey) uthiye nibo..
		arr[k++] = temp[st + i++];
	while (j < m)//baki subarray takey(jodi thakey) uthiye nibo
		arr[k++] = temp[mid + 1 + j++];

}

void mergesort(vector<int>&arr, int st, int en)
{
	if (st >= en)return;
	int mid = (st + en) >> 1; //(en-st)/2;
	mergesort(arr, st, mid);
	mergesort(arr, mid + 1, en);

	merge(arr, st, en, mid);
}
int main()
{
	int n, i, j;
	cin >> n;
	vector<int>v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	mergesort(v, 0, n - 1);
	cout << "The Array After MergeSort :" << endl;
	for (i = 0; i < n; i++)
		cout << v[i] << " \n"[i == n - 1];

}
/**
15
98 -87 -9 0 45 345 4 323 21 12 -312 88 -999 6 9
*/