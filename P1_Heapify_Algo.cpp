#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& Arr,int idx)
{
    int sz = Arr.size()-1;
    int lchild_idx = 2*idx+1;
    int rchild_idx = 2*idx+2;

    /*
    if(lchild_idx>sz && rchild_idx>sz)
    return;
    */

    /*
    if(lchild_idx<=sz && rchild_idx<=sz &&
       Arr[idx]>Arr[lchild_idx] && Arr[idx]>Arr[rchild_idx])
        return ;
    */

    int largest = idx;

    if(lchild_idx<=sz && Arr[largest]<Arr[lchild_idx])
        largest = lchild_idx;
    if(rchild_idx<=sz && Arr[largest]<Arr[rchild_idx])
        largest = rchild_idx;

    if(largest!=idx)
    {
        swap(Arr[idx],Arr[largest]);
        heapify(Arr,largest);
    }
    else
        return;

}

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}
int main()
{
    vector<int> Arr = {1,14,10,8,7,9,3,2,4,6};
    int idx = 0;
    cout << "Before Heapify" << endl;
    print_1D_v(Arr);
    heapify(Arr,idx);
    cout << "After Heapify" << endl;
    print_1D_v(Arr);

    return 0;
}
