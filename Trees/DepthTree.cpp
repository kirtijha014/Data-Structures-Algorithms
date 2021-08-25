#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode{

    public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data)
    {
        this -> data = data;
    }
    ~TreeNode()
    {
        for(int i = 0; i < children.size(); i++)
        {
            delete(children[i]);
        }
    }
};

TreeNode<int>* takeInput()
{
    int rootData;
    cout << "\nRoot data : ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "\nEnter no. of children of " <<front->data <<" : ";
        cin >> numChild;
        for(int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i <<"th child of " << front->data << " : ";
            cin>> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printAtLevelK(TreeNode<int>* root, int k)
{
    if(root == NULL)
    return;
    if(k == 0)
    {
        cout << "Node at : "<< k << " : " << root->data << endl;
    }
    for(int i = 0; i < root->children.size();i++)
    {
        printAtLevelK(root->children[i], k-1);
    }
   
}
void print(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        cout << front->data << " : ";
        pendingNodes.pop();
        for(int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
    
}
int main()
{
    TreeNode<int>* root  =takeInput();
    print(root);
 printAtLevelK(root,2);
 delete root;
}