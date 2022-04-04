#include<iostream>
#include<queue>
using namespace std;

class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode*left;
    BinaryTreeNode* right;
    BinaryTreeNode( int data)
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
    cout << "Root Data : ";
    cin >> rootData;
    if(rootData == -1)
    return NULL;
    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "Left Child " << front -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1)
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
     }
    return root;
}
void mirrorTree(BinaryTreeNode* root)
{
    if(root == NULL)
    return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    BinaryTreeNode* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void inOrder(BinaryTreeNode* root)
{
    if(root == NULL)
    return;
    inOrder(root->left);
    cout << root -> data << " ";
    inOrder(root->right);
}
int main()
{
    BinaryTreeNode* root = takeInput();
    mirrorTree(root);
    inOrder(root);
    delete root;
}