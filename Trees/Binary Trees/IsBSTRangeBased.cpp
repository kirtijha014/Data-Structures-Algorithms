#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
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

BinaryTreeNode*takeInput()
{
    int rootData;
    cout << "Root Data : ";
    cin >> rootData;
    if(rootData == -1)
    return NULL;
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "\nLeft Child " << front -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1)
        {
            BinaryTreeNode* left = new BinaryTreeNode(leftChild);
            front -> left = left;
            pendingNodes.push(left);
        }
        int rightChild;
        cout << "\nRight Child " << front -> data << " : ";
        cin >> rightChild;
        if(rightChild != - 1)
        {
            BinaryTreeNode* right = new BinaryTreeNode(rightChild);
            front -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}
bool isBSTRange(BinaryTreeNode * root, int min, int max)
{
    if(root == NULL)
    return true;
    if(root -> data < min || root ->data > max)
    {
        return false;
    }
    return isBSTRange(root -> left,min, root-> data - 1) && isBSTRange(root -> right, root -> data + 1, max);
}
bool isBST(BinaryTreeNode* root)
{
    return isBSTRange(root,INT_MIN, INT_MAX);
}
int main()
{
    BinaryTreeNode* root = takeInput();
    if(isBST(root))
    {
        cout <<"Tree is a binary search Tree.\n";
    }
    else
    cout << "Tree is not a Binary Search Tree.\n";


}
