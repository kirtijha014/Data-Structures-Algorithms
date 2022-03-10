#include<iostream>
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

void printBinaryTree(BinaryTreeNode<int> *root)
{
    //base case :
    if(root == NULL)
    {
        return;
    }
    cout << root -> data  << " : ";
    if(root-> left)
    {
        cout << "LeftChild : " << root->left->data << " ";
    }
    if(root-> right)
    {
        cout << "RightChild : " << root->right->data << " ";
    }
    if(root -> left == NULL || root-> right == NULL)
    {
        cout << "Leaf Nodes";
    }
    cout << endl;
    printBinaryTree(root -> left);
    printBinaryTree(root-> right);

}
int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    root -> left = node1;
    root -> right = node2;
    printBinaryTree(root);

}