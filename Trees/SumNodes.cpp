#include<iostream>
#include<vector>
#include<queue>
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
int sumTree(TreeNode<int>* root)
{
    int ans = root->data;
    for(int i = 0; i < root->children.size(); i++)
    {
        ans = ans + sumTree(root->children[i]);
    }
    return ans;
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
    int ans = sumTree(root);
    cout << "\nThe Sum : " << ans;
    // printTree(root);
}