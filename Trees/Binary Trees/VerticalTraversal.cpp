#include<iostream>
#include<queue>
#include<iterator>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};
Node* takeInput()
{
    int rootData;
    cout << "Root data : " ;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    Node* root = new Node(rootData);
    queue<Node*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        Node* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "Left Child " << front -> data << " : ";
        cin >> leftChild;
        if(leftChild!= -1)
        {
            Node* left = new Node(leftChild);
            front -> left = left;
            pendingNodes.push(left);
        }
        int rightChild;
        cout << "Right Child " << front -> data << " : ";
         cin >> rightChild;
        if(rightChild!= -1)
        {
            Node* right = new Node(rightChild);
            front -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}
vector<int> verticalTraversal(Node* root)
{
     map<int,map<int,vector<int>>>Nodes;
        queue<pair<Node*,pair<int,int>>>pendingNodes;
        vector<int>ans;
        if(root == NULL)
        return ans;
        pendingNodes.push(make_pair(root,make_pair(0,0)));
        while(!pendingNodes.empty())
        {
            pair<Node*,pair<int,int>> temp = pendingNodes.front();
            pendingNodes.pop();
            Node* front = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            Nodes[hd][level].push_back(front -> data);
            if(front -> left)
            {
                pendingNodes.push(make_pair(front->left,make_pair(hd-1,level+1)));
            }
            if(front -> right)
            {
                pendingNodes.push(make_pair(front->right,make_pair(hd+1,level+1)));
                
            }
        }
        for(auto i:Nodes)
        {
            for(auto j : i.second)
            {
                for(auto k : j.second)
                
                ans.push_back(k);
            }
            
        }
        return ans;
}
int main()
{
    Node* root = takeInput();
    vector<int> ans = verticalTraversal(root);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]<< " ";
    }
    delete root;
    return 0;
}