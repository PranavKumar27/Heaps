/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 typedef pair<int,ListNode*> pi;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int sz = lists.size();

        bool throwError = true;
         for(int i=0;i<sz;i++)
        {
            if(lists[i]!=nullptr)
                throwError = false;
        }

        if(throwError)
            return nullptr;

        if(sz>=1)
        {
            priority_queue<pi,vector<pi>,greater<pi>> heap; // Max_heap

        vector<int> Ans;
        vector<ListNode*> RootNodes;
        for(int i=0;i<sz;i++)
        {
            RootNodes.push_back(lists[i]);
        }

        bool RootExhausted = true;
        for(int i=0;i<sz;i++)
            {
                if(RootNodes[i]!=nullptr)
                {
                    cout << RootNodes[i]->val << "," ;
                    heap.push(make_pair(RootNodes[i]->val,RootNodes[i]));
                
                    if(RootNodes[i]->next!=nullptr)
                        cout << " next =" <<  RootNodes[i]->next->val << endl;
               }
            }

            do
            {
                for(int i=0;i<sz;i++)
                {
                    if(RootNodes[i]!=nullptr)
                    {
                        cout << RootNodes[i]  << "," ;
                        cout << RootNodes[i]->val << "," ;
                        //heap.push(make_pair(RootNodes[i]->val,RootNodes[i]));
                        if(RootNodes[i]->next!=nullptr)
                            cout << " next =" <<  RootNodes[i]->next->val << endl;
                    }
                }
                int small_val = heap.top().first;
                ListNode* start = heap.top().second;
                cout << "size=" << heap.size() << endl;
                heap.pop();
                cout << "Removed from Heap" << " size=" << heap.size() << endl;
                Ans.push_back(small_val);
                cout << "small_val=" << small_val << endl;
                cout << "start=" << start << endl;
                auto itr = find(RootNodes.begin(),RootNodes.end(),start);
                int idx = -1;
                if(itr!=RootNodes.end())
                {
                    idx = itr-RootNodes.begin();
                }
                cout << "idx=" << idx << endl;
                if(idx!=-1)
                {
                    ListNode* next_ptr = RootNodes[idx]->next;
                    RootNodes[idx] = next_ptr;
                    if(idx!=-1 && next_ptr!=nullptr)
                        heap.push(make_pair(RootNodes[idx]->val,next_ptr));
                    cout << "Pushing " << next_ptr << endl;
                }
                RootExhausted=true; 
                for(int i=0;i<sz;i++)
                {
                    if(RootNodes[i]!=nullptr)
                    {
                        RootExhausted=false; 
                        break;
                    }
                }
            }while(RootExhausted==false);

            ListNode* root1=nullptr;
            int n = Ans.size();
            cout << "n=" << n << endl;
            for(int i=0;i<n;i++)
            {
                cout <<  Ans[i] << ",";
                ListNode* newNode = new ListNode(Ans[i]);
                cout << "address=" << newNode << " val=" << newNode->val << endl;
                ListNode* temp = root1;
                if(root1==nullptr)
                {
                    root1 = newNode;
                }
                else
                {
                    while(temp->next!=nullptr)
                    {
                        temp=temp->next;
                    }
                    temp->next = newNode;
                }
            }
            return root1;
        }
        else
            return nullptr;
        
        
    }

};
