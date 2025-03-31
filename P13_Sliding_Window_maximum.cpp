#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*
 Arr = {1, 3, -1, -3, 5}  , Sliding window k =3
        0  1   2   3  4

 Hence windows are Arr[0..2] , arr[1..3], Arr[2...4]
 Window 1 = {1, 3, -1}   Max = 3
 Window 2 = {3, -1, -3}  Max = 3
 Window 3 = {-1, -3, 5}  Max = 5

 Hence Ans = {3,3,5}  Return Max Value in all the windows of size k=3 in Arr

 Sol 1: Using nested loop

 Sol 2: Using Max-Heap to keep track of max element and window start index/chronology

*/

void print_1D_v(vector<int>& Arr)
{
    for(auto d:Arr)
        cout << d << ",";
    cout << endl;
}

// TC --> O(n-k+1)*O(k) ~~ O(n*k)
// SC --> O(n-k+1) for res
void findMax_in_Window_Sol1(vector<int>& Arr,vector<int>& res,int k)
{
    int n = Arr.size();
    for(int i=0;i<n-k+1;i++)
    {
        int maxi = -1e9;
        for(int j=i;j<k+i;j++)
        {
            if(Arr[j]>maxi)
                maxi = Arr[j];
        }
        res.push_back(maxi);
    }
}

// TC --> O(N*LogN)+O(N-K+1)
// SC --> O(N-K+1)
void findMax_in_Window_Sol2(vector<int>& Arr,vector<int>& res,int k)
{
    int n = Arr.size();
    priority_queue<pair<int,int>> heap; // Max-Heap

    for(int i=0;i<n;i++)
    {
        heap.push(make_pair(Arr[i],i));
        if(i>=k-1)
        {
            int max_val = heap.top().first;
            int max_idx = heap.top().second;
            if(max_idx>=i-k)
                res.push_back(max_val);
            else
                heap.pop();
        }
    }

}


int main()
{

    vector<int> Arr = {1, 3, -1, -3, 5};
    vector<int> Max_In_Window_1;
    int k = 3; // window Size or width

    findMax_in_Window_Sol2(Arr,Max_In_Window_1,k);

    cout << "Maximum in Windows" << endl;
    print_1D_v(Max_In_Window_1);


    return 0;
}
