#include <bits/stdc++.h>
#define sz 1000
using namespace std;

struct Heap{
    int heap[sz], cnt;//cnt=kotogula element achey..
    Heap();
    void insert_in_heap(int);
    int delete_heap_root();
    void print_heap();
};

Heap::Heap(){
    cnt = 0;
}

void Heap::insert_in_heap(int x){
    heap[++cnt] = x;//cnt er value1 theke start korchi.
    int child = cnt;//cnt means last inserted elemnt in to the heap..
    int par = child/2;//child /2 =parent er index..(1 based indexing) 

    while(par>0)
    {
        if(heap[par] < heap[child])
            swap(heap[par], heap[child]);
        else
            return;//appropriate position er moddhe ache shobgula..tai return;
        child = par;//parent takey child korey dewa..
        par = par/2;//parent er parent takey parent kore dewa.
    }
}

int Heap::delete_heap_root()
{
    if(cnt==0)//heap er moddhe kono element nai..
    {
        cout << "Underflow!" << endl;
        return -1;
    }
    int ret=-1, ind = 1, lc, rc, mx;
    swap(heap[ind], heap[cnt]);//root er sathey amra last inserted element ta swap korey dilam.
    ret = heap[cnt--];//prev root takey ret er moddhe rekhe cnt er man -- korey dilam..
    rc = lc = ind*2;//1 based indexing..rc=lc+1;
    rc++;

    while(lc<=cnt)
    {
        if(rc <= cnt)//rc exist korey
            mx = max(heap[lc], heap[rc]);//duita child jodi thakey tahole max compare
        else
            mx = heap[lc];//right child na thakley left child=max;
        if(mx > heap[ind])//mx jodi root er ceye boro hoy..
        {
            if(heap[lc] == mx)
            {
                swap(heap[lc], heap[ind]);
                ind = lc;//1 step nisey neme gelam.
            }
            else
            {
                swap(heap[rc], heap[ind]);
                ind = rc;
            }
        }
        else
            return ret;
        rc = lc = ind*2;
        rc++;
    }
    return ret;
}

void Heap::print_heap()
{
    for (int i = 1; i<=cnt; i++)
        cout << heap[i] << " \n"[i==cnt];
    return;
}


int HeapSort(int arr[], int n){
    Heap *hp = new Heap();

    for (int i = 0; i<n; i++)
        hp->insert_in_heap(arr[i]);
    cout<<"The Heap TREE:"<<endl;
    hp->print_heap();

    for (int i = 0; i<n; i++)
        arr[i] = hp->delete_heap_root();
}


int main()
{
    int n, arr[sz], m;

    cin >> n;

    for (int i = 0; i<n; i++)
        cin >> arr[i];

    HeapSort(arr,n);

    cout << "The Array After HeapSort:" << endl;

    for (int i = 0; i<n; i++)
        cout <<arr[i] <<" \n"[i==n-1];

    return 0;
}

/**
15
2 54 21 4 22 21 15 5 41 2 4 41 6 41 5
*/
