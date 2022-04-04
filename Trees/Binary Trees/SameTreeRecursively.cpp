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
bool isSameTree(BinaryTreeNode*p, BinaryTreeNode* q)
{
    if(p == NULL && q == NULL)
    return true;
    if(p == NULL || q == NULL)
    return false;
    return(p->data == q-> data &&
    isSameTree(p->left,q->left)&&
    isSameTree(p->right,q->right));
}
int main()
{
    cout << "Enter details of Tree P : \n";
    BinaryTreeNode* p = takeInput();
    cout << "Enter details for Tree Q: \n";
    BinaryTreeNode* q = takeInput();
    if(isSameTree(p,q))
    cout << "Trees are identical.\n";
    else
    cout << "Trees are not identical.\n";
    delete p;
    delete q;
}