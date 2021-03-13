/* It is similar to selection sort where we first find the maximum element
and place the maximum element at the end. We repeat the same process for the remaining elements.

2 type of heap ache..max heap and min heap..usually max heap kore thaki amra.

MaxHeap:The value of N is greater than or equal to the value at  each of the children of N.

MinHeap:The value of N is smaller than or equal to the value at  each of the children of N.
*/
/* A complete binary tree is a binary tree in which every level, except possibly the last,
 is completely filled, and all nodes are as far left as possible .
Heap er structure ta always complete binary tree er structure hobey..(left theke right puron hoye hoye ashbey)
*/

/*main goal-->Root niye kaj kora..
root tai shobceye boro element..tai root delete kortey thakley amra descending order er ekta sorted arry peye jabo..
*/
/*inserton: heap er shorto thik rekhe complete binary tree korey feltey hobe protibar..
Input data: 4, 10, 3, 5, 1
         4(0)
        /   \
     10(1)   3(2)
    /   \
 5(3)    1(4)

The numbers in bracket represent the indices in the array
representation of data.

Applying heapify procedure to index 1:
         4(0)
        /   \
    10(1)    3(2)
    /   \
5(3)    1(4)

Applying heapify procedure to index 0:
        10(0)
        /  \
     5(1)  3(2)
    /   \
 4(3)    1(4)
The heapify procedure calls itself recursively to build heap
 in top down manner.
 */

/* deleting the root of the heap:
shorboshesh node(last child complete tree er)  and root swap korbo.ager root takey(now last child e eshe geche) temp e niye delete.
 then again reheap.(protibar boro child er sathe compare korey swap).(insertion er shorto ta)
*
/* If the parent node is stored at index I, the left child can be calculated by 2 * I + 1
and right child by 2 * I + 2 (assuming the indexing starts at 0).
*/

/*
Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
3. Repeat step 2 while size of heap is greater than 1.
*/

//Time complexity of heapify is O(Logn). Time complexity of createAndBuildHeap() is O(n)
//and overall time complexity of Heap Sort is O(nLogn).

#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
	int largest = i; //initialize root as largest element
	int l = 2 * i + 1; //left child
	int r = 2 * i + 2; //right child

	// If left child is larger than root
	if (l < n  && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) //largest elemnt jodi root na hoy..
	{
		swap(arr[largest], arr[i]); //swap korey dibo

		heapify(arr, n, largest); //recursively heapify
	}

}
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = (n / 2) - 1; i >= 0; i--)
		heapify(arr, n, i);
	//One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		//move current root to end
		swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		heapify(arr, i, 0); //prev root takey bad diye heapify again.
	}
}

int main()
{
	int i, arr[] = { -2, 54 , 21 , 4 , 22 , 21 , 15 , 5 , -41 , 2 , 4 , 41, 6 , 41 , 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	cout << "The Array After HeapSort:" << endl;
	for (i = 0; i < n; i++)
		cout << arr[i] << " \n"[i == n - 1];
}
