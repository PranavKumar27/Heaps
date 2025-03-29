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


void heapify(vector<int>& Arr,int idx)
{
    //cout << __FUNCTION__ << endl;
    int sz = Arr.size();
    int lchd = 2*idx+1;
    int rchd = 2*idx+2;

    int largest = idx;

    if(lchd<sz && Arr[lchd]>Arr[largest])
        largest = lchd;


    if(rchd<sz && Arr[rchd]>Arr[largest])
        largest = rchd;

    if(largest!=idx)
    {
        swap(Arr[largest],Arr[idx]);
        heapify(Arr,largest);
    }
    else
    {
        return;
    }
}

vector<int> HeapSort(vector<int>& Arr)
{
    cout << __FUNCTION__ << endl;
    int sz = Arr.size();
    vector<int> SortedArray;
    for(int i=sz-1;i>=1;i--)
    {
        int largest = Arr[0];
        swap(Arr[0],Arr[i]);
        SortedArray.push_back(largest);
        int siz = Arr.size();
        Arr.resize(siz-1);

        heapify(Arr,0);
    }
    SortedArray.push_back(Arr[0]);
    print_1D_v(SortedArray);
    return SortedArray;
}

void buildHeap(vector<int>& Arr)
{
    cout << __FUNCTION__ << endl;
    int sz = Arr.size();
    for(int idx=1;idx<sz;idx++)
    {
        int parent = ceil(idx/2.0)-1;
        while(idx>0 && Arr[parent]<Arr[idx])
        {
            swap(Arr[parent],Arr[idx]);

            idx=parent;
            parent = ceil(idx/2.0)-1;
        }
    }
}

int main()
{
    vector<int> Arr = {5,7,9,2,1,3,4,8,6};

    // Build Max Heap
    // Remove Max and swap with Last Element
    // At the end Array will be Sorted

    cout << "<<<<<<-------HeapSort------>>>>>>" << endl;

    buildHeap(Arr);

    print_1D_v(Arr);

    HeapSort(Arr);


    return 0;
}
