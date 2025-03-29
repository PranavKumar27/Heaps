#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// TC --> O(LogN)
// SC --> O(1)

int increaseValAtKey(vector<int>& Arr,int val,int key)
{
    int sz = Arr.size();
    if(key>sz)
    {
        cout << "Heap UnderFlow" << endl;
        return -1;
    }

    // Percolate Algo
    Arr[key] = val;

    int i = key;
    int parent = ceil(i/2.0)-1;
    while(i>0 && Arr[parent] < Arr[i])
    {
        swap(Arr[parent],Arr[i]);
        i = parent;  // update i
        parent = ceil(i/2.0)-1; // update parent
    }

    return val;
}

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

int main()
{
    vector<int> Arr = {9,8,7,6,5,4,3};
    cout << "Before Increase of Value " << endl;
    print_1D_v(Arr);
    int val = 50;
    int key = 4; // index in Arr
    //cout << "key=" << key << " Arr[key]=" << Arr[key] << endl;

    cout << "Val increased from = " << Arr[key] ;

    int val_inc = increaseValAtKey(Arr,val,key);

    cout << " to new value = " << val_inc << endl;

    cout << "After Increase of Value " << endl;
    print_1D_v(Arr);


    return 0;
}
