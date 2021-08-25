#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for(int i = 0; i <children.size(); i++)
        {
            delete (children[i]);
        }
    }
    
};
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "\nEnter root: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "\nEnter no. of children of " << front->data << " : ";
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "\nEnter " << i << "th child of " << front->data << " : ";
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


int heightNode(TreeNode<int>* root)
{
    int height = 0;
    if(root == NULL)
    {
        return height;
    }

    for(int i = 0 ; i < root->children.size();i++)
    {
        int temp = heightNode(root->children[i]);
      
        if(temp > height)
        {
            height = temp;
        }
    }
    return height+1;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        cout << front->data << " : ";
        pendingNodes.pop();
        for (int i = 0; i < front->children.size(); i++)
        {

            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}
int main()
{
    TreeNode<int> *root = takeInput();
    //printTree(root);
   int height = heightNode(root);
   cout << "\nHeight : " << height;
  //cout << root->children.size() << endl;
}