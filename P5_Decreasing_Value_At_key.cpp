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

// TC --> O(LogN)
// SC --> O(LogN)

int decreaseValAtKey(vector<int>& Arr,int new_val,int key)
{
    int sz = Arr.size();
    if(key>sz)
    {
        cout << "Heap UnderFlow" << endl;
        return -1;
    }

    Arr[key] = new_val;

    // Percolate Down
    Max_Heapify(Arr,key);

    return new_val;
}

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

int main()
{
    vector<int> Arr = {9,8,7,6,5,4,3,2,1};
    cout << "Before Decrease Value Applied" << endl;
    print_1D_v(Arr);
    int key = 1;
    int new_val = 0;
    cout << "Val decreased from = " << Arr[key] ;

    int val_dec = decreaseValAtKey(Arr,new_val,key);

    cout << " to new value = " << val_dec << endl;


    cout << "After Decreasing Value Applied" << endl;
    print_1D_v(Arr);


    return 0;
}
