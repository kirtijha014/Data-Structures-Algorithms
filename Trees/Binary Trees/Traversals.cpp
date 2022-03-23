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
            this-> data = data;
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
    cout << "\nEnter root data : ";
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
        int leftData;
        cout << "\nEnter left child of " << front->data << " : ";
        cin >> leftData;
        if(leftData != -1)
        {
            BinaryTreeNode<int>* left = new BinaryTreeNode<int>(leftData);
            front -> left = left;
            pendingNodes.push(left);
        }
        int rightData;
        cout << "\nEnter right child of " << front -> data << " : ";
        cin >> rightData;
        if(rightData != -1)
        {
             BinaryTreeNode<int>*right = new BinaryTreeNode<int>(rightData);
             front -> right = right;
             pendingNodes.push(right);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>*root)
{
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << " : ";
        if(front -> left != NULL)
        {
            cout <<"Left Child : " <<  front->left->data << " ";
            pendingNodes.push(front -> left);
        }
        if(front -> right != NULL)
        {
            cout << "Right Child : " << front->right->data << " ";
             pendingNodes.push(front -> right);
        }
        if(front -> left == NULL && front -> right == NULL)
        {
            cout << "Leaf Node";
        }
        cout << endl;
    }
}
void preOrderTraversal(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return;

    cout << root -> data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}
void inOrderTraversal(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return;
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}
void postOrderTraversal(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    return;
    postOrderTraversal(root ->left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";

}
int main()
{
    BinaryTreeNode<int>* root = takeInput();
    cout << "\nThe usual Tree : ";
    printTree(root);
    //printBinaryTree(root);
    cout << "\n\nPreOrder Traversal : ";
    preOrderTraversal(root);
    cout << "\n\nInOrder Traversal : ";
    inOrderTraversal(root);
    cout << "\n\nPostOrder Traversal : ";
    postOrderTraversal(root);
}
