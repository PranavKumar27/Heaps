#include <iostream>
#include <vector>
#include <queue>

class Node
{
public:
    int val;
    Node* next;
    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};
using namespace std;

Node* create_List(vector<int> Arr)
{
    int n = Arr.size();
    Node* root = nullptr;

    for(int i=0;i<n;i++)
    {
        Node* newNode = new Node(Arr[i]);
        if(root==nullptr)
            root = newNode;
        else
        {
            Node* temp = root;
            while(temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return root;
}

void print_List(Node* root)
{
    Node* temp = root;
    while(temp != nullptr)
    {
        cout << temp->val << ",";
        temp = temp->next;
    }
    cout << endl;
}
class Compare
{
   public:
       bool operator()(Node* a, Node* b) {
        return a->val > b->val;
    }
};

class Comp
{
    public:
    bool customComparison(Node* a, Node* b)
    {
        // Custom comparison logic
        return a->val > b->val; // it sorts in ascending order
    }
};


Node* mergeKList(vector<Node*> NodeList)
{
    priority_queue<Node*,vector<Node*>,Comp> heap; // Min Heap

    for(int i=0;i<NodeList.size();i++)
    {
        if(lists[i]!=nullptr)
            heap.push(NodeList[i]);
    }

    Node* Head = new Node(-1);
    Node* tail = dummyHead;
    while(!heap.empty())
    {
        Node* TopNode = heap.top();
        //cout << "Top =" << TopNode->val << ",";
        heap.pop();

        if(tail!=nullptr)
            tail->next = TopNode;

        tail = TopNode;

        if(TopNode!=nullptr && TopNode->next!=nullptr)
            heap.push(TopNode->next);
    }
    return Head->next;
}
int main()
{
    vector<int> v1 = {1,3,5,7};
    vector<int> v2 = {2,4,6,8};
    vector<int> v3 = {0,9,10,11};

    Node* r1 = create_List(v1);
    Node* r2 = create_List(v2);
    Node* r3 = create_List(v3);

    cout << "Sorted Linked List" << endl;
    print_List(r1);
    print_List(r2);
    print_List(r3);

    cout << "Merge K Sorted Linked List" << endl;

    vector<Node*> Nodelist = {r1,r2,r3};
    Node* mergedNodePtr = mergeKList(Nodelist);
    print_List(mergedNodePtr);

    return 0;
}
