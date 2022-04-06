#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};
Node* takeInput()
{
    int rootData;
    cout << "Root data : " ;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    Node* root = new Node(rootData);
    queue<Node*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        Node* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "Left Child " << front -> data << " : ";
        cin >> leftChild;
        if(leftChild!= -1)
        {
            Node* left = new Node(leftChild);
            front -> left = left;
            pendingNodes.push(left);
        }
        int rightChild;
        cout << "Right Child " << front -> data << " : ";
         cin >> rightChild;
        if(rightChild!= -1)
        {
            Node* right = new Node(rightChild);
            front -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}
void leftTraversal(Node* root, vector<int>&ans)
{
    if(root == NULL)
    return;
    if(root->left  == NULL && root->right == NULL)
    return;

    ans.push_back(root->data);

    if(root->left)
    {
        leftTraversal(root->left,ans);
    }
    else
    leftTraversal(root->right,ans);
}

void leafTraversal(Node* root, vector<int>&ans)
{
    if(root == NULL)
    return;
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);
}

void rightTraversal(Node* root, vector<int>&ans)
{
    if(root == NULL)
    return;
    if(root->left == NULL && root->right == NULL)
    return;
    if(root->right)
    rightTraversal(root->right,ans);
    else
    rightTraversal(root->left,ans);
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root)
{
    vector<int>ans;
    if(root == NULL)
    return ans;
    ans.push_back(root->data);
    // left Traversal
    leftTraversal(root->left,ans);

    //leaf Traversal
    //left subtree
    leafTraversal(root->left,ans);
    //right subtree
    leafTraversal(root->right,ans);

    // right Traversal
    rightTraversal(root -> right,ans);

    return ans;

}
int main()
{
    Node* root = takeInput();
    vector<int>ans = boundaryTraversal(root);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " "; 
    }
    cout << endl;
    delete root;
    return 0;
}