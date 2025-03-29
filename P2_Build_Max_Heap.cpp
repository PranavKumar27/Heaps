#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void Max_Heapify(vector<int>& Arr,int idx)
{
    int n = Arr.size();
    int lchild_idx = 2*idx+1;
    int rchild_idx = 2*idx+2;

    int largest = idx;

    if(lchild_idx<n && Arr[lchild_idx]>Arr[largest])
        largest = lchild_idx;
    if(rchild_idx<n && Arr[rchild_idx]>Arr[largest])
        largest = rchild_idx;

    if(largest!=idx)
    {
        swap(Arr[largest],Arr[idx]);
        Max_Heapify(Arr,largest);
    }
    else
        return;
}

void buildMax_Heap(vector<int>& Arr)
{
    int n = Arr.size();
    int InternalNode_idx = floor(n/2) - 1;
    for(int i=InternalNode_idx;i>=0;i--)
    {
        Max_Heapify(Arr,i);
    }
}

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

int main()
{
    vector<int> Arr = {3,6,5,0,8,2,1,9};
    cout << "Before Max Heap build" << endl;
    print_1D_v(Arr);
    buildMax_Heap(Arr);
    cout << "After Max Heap build" << endl;
    print_1D_v(Arr);


    return 0;
}
