// Sol 1:  Using max Heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            heap.push(nums[i]);
        }

        int cnt = 0;
        int element = 0;
        while(cnt<k)
        {
            element = heap.top();
            //cout << "element=" << element << endl;
            heap.pop();
            cnt++;
        }
        return element;
    }
};


// Sol 2: Optimized Approach Using Min Heap

class Solution {
public:
    int findKthLargest(vector<int>& arr, int K) {
        nt n = arr.size();

    // Create a min heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> pq;

    // Iterate through the array elements
    for (int i = 0; i < n; i++) {

        // Push the current element onto the min heap
        pq.push(arr[i]);

        // If the size of the min heap exceeds K,
        // remove the largest element
        if (pq.size() > K)
            pq.pop();
    }

    // Return the Kth largest element (top of the min heap)
    return pq.top();
    }
};
