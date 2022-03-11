#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
     T data;
     BinaryTreeNode *left;
     BinaryTreeNode *right;

     BinaryTreeNode(T data)
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

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!= 0)
    {
        BinaryTreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front -> left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout << "Enter right child of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1)
        {
            BinaryTreeNode<int>*rightChild = new BinaryTreeNode<int>(rightChildData);
            front -> right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
     return root;
}

void printBinaryTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        BinaryTreeNode<int>* leftChild = front -> left;
        BinaryTreeNode<int>* rightChild = front -> right;
        if(leftChild != NULL)
        {
            pendingNodes.push(leftChild);
            cout << "LeftChild : " << leftChild -> data << " ";
        }
        if(rightChild != NULL)
        {
            pendingNodes.push(rightChild);
            cout << "rightChild : " << rightChild -> data << " ";
        }
        if(leftChild == NULL || rightChild == NULL)
        {
            cout << "Leaf Node";
        }
        cout << endl;
    }
}

int NumberOfNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return 0;

    return 1 + NumberOfNodes(root->left) + NumberOfNodes(root-> right);

}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printBinaryTree(root);
    cout << "No. of Nodes : " << NumberOfNodes(root) << endl;
}