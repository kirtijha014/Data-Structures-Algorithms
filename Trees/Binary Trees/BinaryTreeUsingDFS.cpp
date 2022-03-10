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
BinaryTreeNode<int>* takeInputDFS()
{
    int rootData;
    cout << "Enter data : " << endl;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> * leftChild = takeInputDFS();
    BinaryTreeNode<int>* rightChild = takeInputDFS();
    root-> left = leftChild;
    root-> right = rightChild;

    return root;
}

void printBinaryTree(BinaryTreeNode<int> *root)
{
    //base case :
    if(root == NULL)
    {
        return;
    }
    cout << root -> data  << " : ";
    if(root-> left != NULL)
    {
        cout << "LeftChild : " << root->left->data << " ";
    }
    if(root-> right != NULL)
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
    BinaryTreeNode<int> *root = takeInputDFS();
    printBinaryTree(root);

    delete root;

}