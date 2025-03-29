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

void delete_Max(vector<int>& Arr)
{
    int sz = Arr.size();
    int largest_val = Arr[0];
    cout << "to be deleted = " << largest_val << endl;
    int new_large = Arr[sz-1];
    cout << "to be percolated Downwards = " << new_large << endl;
    // Reduce the Array size
    Arr.resize(sz-1);
    // Make leaf node as new root
    Arr[0] = new_large;
    // Percolate Downwards using Heapify
    Max_Heapify(Arr,0);
}

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

int main()
{
    vector<int> Arr = {9,8,7,5,4,3,2};
    cout << "Before Extract Max or Delete Max Algo Applied" << endl;
    print_1D_v(Arr);
    delete_Max(Arr);
    cout << "After Extract Max or Delete Max Algo Applied" << endl;
    print_1D_v(Arr);


    return 0;
}
