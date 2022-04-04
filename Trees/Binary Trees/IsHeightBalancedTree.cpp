#include<iostream>
#include<queue>
#include<math.h>
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
    cout << "Root Data : ";
    cin >> rootData;
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
        if(rightChild != -1)
        {
            BinaryTreeNode * right = new BinaryTreeNode(rightChild);
            front->right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}
int heightTree(BinaryTreeNode* root)
{
    if(root == NULL)
    return 0;
    int leftHeight = heightTree(root -> left);
    int rightHeight = heightTree(root-> right);
    int totalHeight = max(leftHeight,rightHeight) + 1;
}
void inorderTraversal(BinaryTreeNode* root, bool& ans)
{
    if(root == NULL)
    return;
    inorderTraversal(root->left,ans);
    int leftDiff = heightTree(root->left);
    int rightDiff = heightTree(root->right);
    int difference = abs(leftDiff - rightDiff);
    if(difference > 1)
    ans = ans && false;
    inorderTraversal(root->right,ans);
}
bool isBalanced(BinaryTreeNode* root)
{
    bool ans = true;
    inorderTraversal(root,ans);
    return ans;
}
int main()
{
    BinaryTreeNode* root = takeInput();
    if(isBalanced(root))
    cout << "Tree is Height Balanced.\n";
    else
    cout << "Tree is not balanced.\n";
    delete root;
}