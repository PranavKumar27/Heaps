#include <iostream>
#include <vector>
#include <math.h>

#define buildHeap push
#define DeleteInHeap pop
#define print_1D_v display
#define HEAPSIZE 7

using namespace std;

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

void heapify(vector<int>& Arr,int idx,int sz)
{
    cout << __FUNCTION__ << endl;
    int lchild = 2*idx+1;
    int rchild = 2*idx+2;
    int largest = idx;
    if(lchild<=sz && Arr[lchild]>Arr[largest])
        largest = lchild;
    if(rchild<=sz && Arr[rchild]>Arr[largest])
        largest = rchild;

    if(largest!=idx)
    {
        cout << "Arr[largest] =" << Arr[largest] << " Arr[idx]=" << Arr[idx] << endl;
        swap(Arr[largest],Arr[idx]);
        heapify(Arr,largest,sz);
    }
    else
        return;
}

// IF we need to add single element to Heap use Percolate Up
// Else if we have Array Add by Running loop for only Internal Nodes
void buildHeap(vector<int>& Arr,int element)
{
    cout << __FUNCTION__ << endl;

    if(Arr.size()==HEAPSIZE)
    {
        cout << "HEAP OverFlow" << endl;
        return;
    }
    Arr.push_back(element);
    int sz = Arr.size();
    int idx = sz-1;
    int parent = ceil(idx/2.0)-1;

    while(idx>0 && Arr[parent]<Arr[idx])
    {
        cout << "Arr[parent] =" << Arr[parent] << " Arr[idx]=" << Arr[idx] << endl;
        swap(Arr[parent],Arr[idx]);
        idx=parent;
        parent = ceil(idx/2.0)-1;
    }

    /*
    int InternalNodes = floor(sz/2.0)-1;
    cout << "InternalNodes=" << InternalNodes << endl;

    for(int i=InternalNodes;i>=0;--i)
    {
        heapify(Arr,i,sz-1);
    }
    */
}

void DeleteInHeap(vector<int>& Arr)
{
    int sz = Arr.size();
    if(sz==0)
    {
        cout << "HEAP UnderFlow" << endl;
        return;
    }
    int largest = Arr[0];
    cout << "Element popped =" << largest << endl;
    Arr[0] = Arr[sz-1];
    Arr.resize(sz-1);
    heapify(Arr,0,sz-1);
}

int main()
{
    vector<int>Arr = {10,20};
    int option,element;

    do
    {
        cout << "<<-------------------Heap Implementation----------------->>" << endl;

        cout << "Enter\n->1 to Push\n->2 to Pop\n3-> Display\n4 to Exit   :";
        cin >> option;

        switch(option)
        {
            case 1: cout << "Enter Element to Push";
                    cin >> element;
                    push(Arr,element); // buildHeap
                    break;
            case 2: pop(Arr); // Extract Max and Reduce Array Size and then Heapify
                    break;
            case 3: display(Arr);
                    break;
            case 4: return 0;
            default:return 0;
        }
    }while(element!=4);

    return 0;
}
