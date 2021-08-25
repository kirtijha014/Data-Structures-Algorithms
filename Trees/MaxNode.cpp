#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode*>children;
    TreeNode(T data)
    {
        this -> data = data;
    }
    ~TreeNode()
    {
        for( int i = 0; i < children.size() ; i++)
        {
            delete(children[i]);
        }
    }
};

TreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter Root : ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "\nEnter no. of children of "<< front->data <<" : ";
        cin >> numChild;
        for(int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "\nEnter " << i << "th child of " << front ->data << " : "; 
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int>* maximumNode(TreeNode<int>* root)
{
    if(root == NULL)
    return NULL;
    TreeNode<int>* maxNode = new TreeNode<int>(0);
    int max = 0;
    for(int i = 0; i < root->children.size();i++)
    {
        if(maximumNode(root->children[i])-> data > max)
        {
            max = root->children[i]->data;
            maxNode = root->children[i];
        }     
    }
    if(max < root-> data)
        {
            
            maxNode = root;
        }
        return maxNode;
}
void printTree(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        cout << front-> data << " : ";
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
    TreeNode<int>* root = takeInput();
    TreeNode<int>* max = maximumNode(root);
    cout << "\nMax Value : " << max -> data ;
    // printTree(root);
    delete root;
}