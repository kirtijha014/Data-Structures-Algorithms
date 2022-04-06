#include<iostream>
#include<queue>
using namespace std;

class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode* takeInput()
{
    int rootData;
    cout << "Root data : " ;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "Left Child " << front -> data << " : ";
        cin >> leftChild;
        if(leftChild!= - 1)
        {
            BinaryTreeNode* left = new BinaryTreeNode(leftChild);
            front -> left = left;
            pendingNodes.push(left);
        } 
        int rightChild;
        cout << "Right Child " << front -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1)
        {
            BinaryTreeNode* right = new BinaryTreeNode(rightChild);
            front -> right = right;
            pendingNodes.push(right);
        }
        cout << endl;
    }
    return root;
}
vector<int> zigzagTraversal(BinaryTreeNode* root)
{
    vector<int>result;
    if(root == NULL)
    return result;
    queue<BinaryTreeNode*>pendingNodes;
    pendingNodes.push(root);
    bool leftRight = true;
    while(!pendingNodes.empty())
    {
        int size = pendingNodes.size();
        vector<int>ans(size);
        
        // for level traversal
        for(int i = 0; i < size; i++)
        {
            BinaryTreeNode* front = pendingNodes.front();
            pendingNodes.pop();
            int index = leftRight ? i : size - i - 1;
            ans[index] = front -> data;
            if(front -> left)
            {
                pendingNodes.push(front->left);
            }
            if(front -> right)
            {
                pendingNodes.push(front->right);
            }
        }
         // change direction
            leftRight = !leftRight;
            for(auto i: ans)
            {
                result.push_back(i);
            }
    }
    return result;
}
int main()
{
    BinaryTreeNode *root = takeInput();
    vector<int> ans = zigzagTraversal(root);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    delete root;
    return 0;
}