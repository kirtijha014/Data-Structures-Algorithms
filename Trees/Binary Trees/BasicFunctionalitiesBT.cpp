#include<iostream>
#include<queue>
#include<math.h>
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

int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return 0;
    int leftTree = height(root -> left);
    int rightTree = height(root-> right);
    int height = max(leftTree,rightTree) + 1;
    return height;

}
int sum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftSum = sum(root -> left);
    int rightSum = sum(root -> right);
    int totalSum = leftSum + rightSum + root -> data;
    return totalSum;

}
int size(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return 0;
    int leftSize = size(root -> left);
    int rightSize = size(root -> right);
    int totalSize = leftSize + rightSize + 1;
    return totalSize;
}
int maxNode(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return INT_MIN;
    int leftMax = maxNode(root -> left);
    int rightMax = maxNode(root -> right);
    int maximum = max(root->data, max(leftMax,rightMax));
    return maximum;

}
int minNode(BinaryTreeNode<int> * root)
{
    if(root == NULL)
    return INT_MAX;
    int leftMin = minNode(root -> left);
    int rightMin = minNode(root -> right);
    int minimum = min(root->data,min(leftMin,rightMin));
    return minimum;
}
BinaryTreeNode<int> *takeInputBFS()
{

    int rootData;
    cout << "Enter Data : ";
    cin >> rootData;
    if (rootData == -1)
       return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // Queue of BinaryTreeNode data type because it will help us to make the connection from node to node.
    queue<BinaryTreeNode<int> *> pendingNodes;
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
void printBinaryTree(BinaryTreeNode<int> *root)
{
   // if (root == NULL)
       // return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
            cout << "LeftChild : " << front->left->data << " ";
        }
        if (front->right != NULL)
        {
            cout << "RightChild : " << front->right->data << " ";
            pendingNodes.push(front->right);
        }
        if (front->left == NULL && front->right == NULL)
            cout << "Leaf Node";

        cout << endl;
    }
}
//50 82 75 12 36 25 30 -1 -1 87 -1 70 76 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    BinaryTreeNode<int> *root = takeInputBFS();
    printBinaryTree(root);
    cout << "\nHeight : " << height(root);
    cout << "\nSum : " << sum(root);
    cout << "\nSize : " << size(root);
    cout << "\nMaximum : " << maxNode(root);
    cout << "\nMinimum : " << minNode(root);
    delete root;
}