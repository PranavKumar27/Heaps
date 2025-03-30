// Link : https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    void print_1D_v(vector<int>& Arr)
    {
        for(auto d:Arr)
            cout << d << ",";
        cout << endl;
    }
    void heapify(vector<int>& Arr,int idx,int sz)
    {
        int lchild = 2*idx+1;
        int rchild = 2*idx+2;
        int largest = idx;

        if(lchild<=sz && Arr[lchild]>Arr[largest])
            largest = lchild;
        if(rchild<=sz && Arr[rchild]>Arr[largest])
            largest = rchild;

        if(largest != idx)
        {
            swap(Arr[largest],Arr[idx]);
            heapify(Arr,largest,sz);
        }
        else
        {
            return;
        }
    }
    void buildHeap(vector<int>& stones)
    {
        int sz = stones.size();
        int internalNodesIdx = floor(sz/2.0)-1;
        for(int i=internalNodesIdx;i>=0;--i)
        {
            heapify(stones,i,sz-1);
        }
    }
    void push(vector<int>& Arr,int element)
    {
        int sz = Arr.size();
        Arr.push_back(element);
        int idx = sz;
        int parent = ceil(idx/2.0)-1;

        while(idx>0 && Arr[parent]<Arr[idx])
        {
            swap(Arr[parent],Arr[idx]);
            idx = parent;
            parent = ceil(idx/2.0)-1;
        }
    }
    int pop(vector<int>& Arr)
    {
        int sz = Arr.size();
        int largest=0;
        if(sz==0)
        {
            // No Element
        }
        else if(sz==1)
        {
            largest = Arr[0];
            Arr.resize(sz-1);
        }
        else
        {
            largest = Arr[0];
            Arr[0]=Arr[sz-1];
            Arr.resize(sz-1);
            heapify(Arr,0,sz-1);
        }

        return largest;
    }
    int lastStoneWeight(vector<int>& stones) {
        
        buildHeap(stones); 
        
        int s = 0;
        do
        {
            if(stones.size()==1)
                break;
            int element_1 = pop(stones);
            int element_2 = pop(stones);
            print_1D_v(stones);
            int diff = abs(element_1-element_2);
            cout << "diff=" << diff << endl;
            if(diff!=0)
                push(stones,diff);
            print_1D_v(stones);
            s++;
        }while(stones.size()>1);

    if(stones.size()==1)
        return stones[0];
    else
        return 0;
    }
};
