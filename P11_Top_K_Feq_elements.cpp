#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int,int> p_int;

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

void findTop_K_Freq_el(vector<int>& Arr,vector<int>& res,int k)
{
    // Hash and find freq of elements

    priority_queue<p_int,vector<p_int>,greater<p_int>> heap; // Min Heap
    unordered_map<int,int> mp;
    int sz = Arr.size();
    for(int i=0;i<sz;i++)
    {
        mp[Arr[i]]++;
    }

    for(auto data:mp)
    {
        pair<int,int> p = {data.second,data.first};
        heap.push(p);
        if(heap.size()>k)
            heap.pop();
    }

    while(!heap.empty())
    {
        res.push_back(heap.top().second);
        heap.pop();
    }
}

int main()
{
    vector<int> Arr = {2,2,2,3,3,1};

    vector<int> Top_K_Freq;
    int k = 2;

    findTop_K_Freq_el(Arr,Top_K_Freq,k);

    cout << "Top K Freq Elements" << endl;
    print_1D_v(Top_K_Freq);

    return 0;
}
