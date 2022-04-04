#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode*right;
    BinaryTreeNode* next;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
void connectNext(BinaryTreeNode<int>* root)
{

}
BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "\nEnter root : ";
    cin >> rootData;
    if(rootData == -1)
    return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "\nEnter left child of " << front -> data << " : ";
        int leftChild;
        cin >> leftChild;
        if(leftChild != -1)
        {
            BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftChild);
            front -> left = leftChildNode;
            pendingNodes.push(leftChildNode);
        }
        cout << "\nEnter right child of " << front -> data << " : ";
        int rightChild;
        cin >> rightChild;
        if(rightChild != - 1)
        {
            BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightChild);
            front -> right = rightChildNode;
            pendingNodes.push(rightChildNode);
        }

    }
    return root;
}
int main()
{
    BinaryTreeNode<int>* root = takeInput();
    
    
}