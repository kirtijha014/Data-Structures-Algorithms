#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
class BTNode{
    public:
    T data;
    BTNode* left;
    BTNode* right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};

BTNode<int>* takeInput()
{
    int rootData;
    cout << "Root Data : ";
    cin >> rootData;

    if(rootData == -1)
    {
        return NULL;
    }
    BTNode<int>* root = new BTNode<int>(rootData);
    queue<BTNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BTNode<int>* front =  pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cout << "\nLeft Child of " << front->data << " :";
        cin >> leftData;
        if(leftData != -1)
        {
            BTNode<int>* left = new BTNode<int>(leftData);
            front -> left = left;
            pendingNodes.push(left);
        }
        int rightData;
        cout << "\nRight Child of " << front->data << " :";
        cin >> rightData;
        if(rightData != -1)
        {
            BTNode<int>* right = new BTNode<int>(rightData);
            front-> right = right;
            pendingNodes.push(right);

        }
    }
    return root;
}
int solve(BTNode<int>* root, int &res)
{
    if(root == NULL)
    return 0;

    int lDia = solve(root->left,res);
    int rDia = solve(root->right,res);

    int temp = max(lDia,rDia) + 1;
    int ans = max(temp,1+lDia+rDia);
    res = max(res,ans);

    return temp;

}
int diameterBT(BTNode<int>*root)
{
    int result = INT_MIN;
    solve(root,result);
    return result;
}
int main()
{
    BTNode<int>* root = takeInput();
    int diameter = diameterBT(root);
    cout << "\nDiameter of Binary Tree : " << diameter << endl;
}
