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

// TC --> O(logN)
// SC --> O(1)

bool Insert_in_Heap(vector<int>& Arr,int val)
{
    int sz = Arr.size();

    Arr.resize(sz+1);
    Arr[sz] = val;

    int i = sz;
    int parent = ceil(i/2.0)-1;

    // Percolate Up
    while(i>0 && Arr[parent]<Arr[i])
    {
        swap(Arr[parent],Arr[i]);
        i = parent;
        parent = ceil(i/2.0)-1;
    }
    return true;
}



int main()
{
    vector<int> Arr = {20,9,8,7,6,5,4,3};

    int val = 12;

    cout << "Before Insert Heap --> " << endl;
    print_1D_v(Arr);

    bool ans = Insert_in_Heap(Arr,val);

    cout << "After Insert Heap --> " << endl;
    print_1D_v(Arr);


    return 0;
}
