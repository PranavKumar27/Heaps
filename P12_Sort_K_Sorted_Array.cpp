
// The Problem : Arr {6 5 3 2 8 10 9}  at max after sort elements are either (x-k)  to (x+k) distance
// eg : After Sort   {2 3 5 6 8 9 10} 
//  Indexs            0 1 2 3 4 5  6

// old - new index of 2 = 3- 0  =  3  <=k
// old - new index of 3 = 2 - 1 = 2 <=k
// old - new index of 5 = 1 - 2 = 1 <=k
// old - new index of 6 = 0 - 3 = 3 <=k
// old - new index of 8 = 4 - 4 = 0 <=k
// old - new index of 9 = 6 - 5 = 1 <=k
// old - new index of 10 = 5 - 6 = 1  <=k

// Sol 1: Using standard Sorting in stl sor(arr.begin(),arr.end());
// Sol 2: Use Min Heap of Size k
// First insert k+1 elements
// Find min at top remove 
// and again insert remaining elements one by one till n elements
// Pop last k+1 elements from Heap and update in Array

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// TC : O(k*LogN)
int main()
{
  vector<int> arr = {6 5 3 2 8 10 9};
  int k = 3;
// code
        priority_queue<int,vector<int>,greater<int>> heap;
        int n = arr.size();
        for(int i=0;i<=k;i++)
        {
            heap.push(arr[i]);
        }
        
        int idx;
        
        for(idx=k+1;idx<n;idx++)
        {
            int el = heap.top();
            //cout << "el=" << el << endl;
            heap.pop();
            
            arr[idx-k-1] = el;
            heap.push(arr[idx]);
        }
        
        while(!heap.empty())
        {
            arr[idx-k-1] = heap.top();
            heap.pop();
            idx++;
        }
return 0;
}
