#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class TreeNode{

    public:
    T data;
    vector<TreeNode *> children;
    TreeNode (T data)
    {
        this->data = data;
    }
    //For De Allocating the Tree
     ~TreeNode()
     {
         for(int i = 0 ; i < children.size(); i++)
         {
             delete(children[i]);
         }
     }

};

TreeNode<int>* takeInput()
{
    int rootData;
    cout << "\nRoot Data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int> (rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "\n No. of children of " << front->data << " : ";
        cin>> numChild;
        for(int i =0 ; i < numChild; i++)
        {
            int ChildData;
            cout << "\n" << i <<"th child of " << front->data << " : ";
            cin >> ChildData;
            TreeNode<int>* child = new TreeNode<int> (ChildData);
            front->children.push_back(child);
            pendingNodes.push(child); 
        } 
    }
    return root;
}

void PreOrder(TreeNode<int>* root)
{
    cout << root->data << " ";
    for(int i = 0; i < root->children.size(); i++)
    {
        PreOrder(root->children[i]);
    }
}
void PostOrder(TreeNode<int>* root)
{
    for(int i = 0; i < root->children.size(); i++)
    {
        PostOrder(root->children[i]);
        
    }
    cout << root -> data << " "; 
}
int main()
{
    TreeNode<int> * root = takeInput();
    cout << "\nPreOrder : ";
    PreOrder(root);
    cout << "\nPostOrder : ";
    PostOrder(root);
    delete root;
}