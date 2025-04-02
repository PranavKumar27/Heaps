#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int>> minHeap;

double findMedian(int num)
{
    cout << __FUNCTION__ << endl;
    // Assumption that MaxHeap size >= 1+minHeap.size
    int leftSize = maxHeap.size();
    int rightSize = minHeap.size();

    cout << "At Start leftSize=" << leftSize << " rightSize=" << rightSize << endl;

    if(leftSize ==0)
        maxHeap.push(num);

    else if(leftSize==rightSize)
    {
        if(num<minHeap.top())
            maxHeap.push(num);
        else
        {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
            minHeap.push(num);
        }
    }
    else
    {
        if(minHeap.size()==0)
        {
            if(num>maxHeap.top())
            {
                minHeap.push(num);
            }
            else
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                maxHeap.push(num);
            }
        }
        else
        {
            if(num>minHeap.top())
                minHeap.push(num);
            else
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                maxHeap.push(num);
            }
        }

    }

    leftSize = maxHeap.size();
    rightSize = minHeap.size();

    cout << "At End leftSize=" << leftSize << " rightSize=" << rightSize << endl;
    double ans = 0.0;
    if(leftSize>rightSize)
    {
        ans = maxHeap.top();
    }
    else
    {
        ans = (maxHeap.top() + minHeap.top())/2.0;
    }
    //cout << "Median=" << ans << endl;
    return ans;
}

int main()
{
    int val;
    cout << "Median of Data Stream Enter -1 to stop" << endl;
    do
    {
        cin >> val;
        double med = findMedian(val);
        cout << "Median So far=" << med  << endl;
    }while(val != -1);

    return 0;
}
