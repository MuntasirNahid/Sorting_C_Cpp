#include<bits/stdc++.h>
using namespace std;
void  countSort(vector<int>&arr)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1,i;
	vector<int>count(range), output(arr.size());

	for (i = 0; i < arr.size(); i++)
		count[arr [i] - min ]++; //0 based indexing for negetive number

	for (i = 1; i <= range; i++)
		count[i] += count[i - 1];

	for (i = arr.size() - 1; i >= 0; i--)
	{
		output[count[arr[i] - min] - 1] = arr[i]; //arr er i th element -1 jei number ta..count array er oi number element.
		--count[arr[i] - min];
	}
	for (i = 0; i < arr.size() ; i++)
		arr[i] = output[i];
}

int main()
{
	int n, m;
	vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };
	countSort(arr);
	cout << "The Array After Count Sort:" << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " \n"[i == arr.size() - 1];//if(i==n-1)
}