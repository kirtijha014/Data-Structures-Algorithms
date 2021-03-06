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

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data : ";
    cin >> rootData;
    if (rootData == -1)
       return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // Queue of BinaryTreeNode data type because it will help us to make the connection from node to node.
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << " : ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << "Enter right child of " << front->data << " : ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}
int main()
{

}