#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

// TC --> O(LogN)
// SC --> O(LogN)

void heapify(vector<int>& Arr,int idx,int sz)
{
    //cout << __FUNCTION__ << endl;
    int lchd = 2*idx+1;
    int rchd = 2*idx+2;

    int largest = idx;

    if(lchd<=sz && Arr[lchd]>Arr[largest])
        largest = lchd;


    if(rchd<=sz && Arr[rchd]>Arr[largest])
        largest = rchd;

    if(largest!=idx)
    {
        swap(Arr[largest],Arr[idx]);
        heapify(Arr,largest,sz);
    }
    else
    {
        return;
    }
}

// TC --> O(N*LogN)
// SC --> O(LogN) + O(N)
void HeapSort(vector<int>& Arr)
{
    cout << __FUNCTION__ << endl;
    int sz = Arr.size();
    for(int i=sz-1;i>=1;i--)  // O(N)
    {
        int largest = Arr[0];
        swap(Arr[0],Arr[i]);
        heapify(Arr,0,i-1); // O(LogN)
    }
    print_1D_v(Arr);
}

void Insert(vector<int>& Arr,int idx)
{
    int parent = ceil(idx/2.0)-1;
    while(idx>0 && Arr[parent]<Arr[idx]) // O(LogN)
    {
        swap(Arr[parent],Arr[idx]);

        idx=parent;
        parent = ceil(idx/2.0)-1;
    }
}

// TC --> O(N*LogN) by Logic but by Proof O(N)
// SC --> O(1)
void buildHeap(vector<int>& Arr)
{
    cout << __FUNCTION__ << endl;
    int sz = Arr.size();
    for(int idx=1;idx<sz;idx++) // O(N)
    {
        Insert(Arr,idx); // O(LogN)
    }
}


void buildMax_Heap(vector<int>& Arr)
{
    int n = Arr.size();
    int InternalNode_idx = floor(n/2) - 1;
    for(int i=InternalNode_idx;i>=0;i--)
    {
        heapify(Arr,i,n-1);
    }
}


int main()
{
    vector<int> Arr = {5,7,9,2,1,3,4,8,6};

    // Build Max Heap
    // Remove Max and swap with Last Element
    // At the end Array will be Sorted

    cout << "<<<<<<-------HeapSort------>>>>>>" << endl;

    //buildHeap(Arr);
    buildMax_Heap(Arr);

    print_1D_v(Arr);

    HeapSort(Arr);


    return 0;
}
