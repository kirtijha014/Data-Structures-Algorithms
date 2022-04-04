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
        this->data = data;
        left = NULL;
        right =NULL;
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
    cout << "Root data : ";
    cin >> rootData;
    cout << endl;
    if(rootData == -1)
    return NULL;

    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout <<"Left Child of " << front ->data << " : ";
        cin >> leftChild;
        cout << endl;
        if(leftChild!=-1)
        {
            BinaryTreeNode* left = new BinaryTreeNode(leftChild);
            front -> left = left;
            pendingNodes.push(left);
        }
        int rightChild;
        cout <<"Right Child of " << front ->data << " : ";
        cin >> rightChild;
        cout << endl;
        if(rightChild!=-1)
        {
            BinaryTreeNode* right = new BinaryTreeNode(rightChild);
            front -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}
BinaryTreeNode*previous = NULL;

bool isBST(BinaryTreeNode* root)
{
    if(root == NULL)
    return true;
    if(!isBST(root->left))
    return false;
    if(previous != NULL && root->data <= previous->data)
        return false;
    previous = root;
    return isBST(root->right);


}
int main()
{
    BinaryTreeNode* root = takeInput();
    if(isBST(root))
    cout << "Given tree is a Binary Search Tree.\n";
    else
    cout << "Tree is not a BST.\n";    
}