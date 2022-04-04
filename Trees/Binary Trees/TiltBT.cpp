#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;

class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right =NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode* takeInput()
{
    int rootData;
    cout << "Root data : ";
    cin >> rootData;
    cout << endl;
    if(rootData == -1)
    return NULL;

    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*>pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        BinaryTreeNode* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout <<"Left Child of " << front ->data << " : ";
        cin >> leftChild;
        cout << endl;
        if(leftChild!=-1)
        {
            BinaryTreeNode* left = new BinaryTreeNode(leftChild);
            front -> left = left;
            pendingNodes.push(left);
        }
        int rightChild;
        cout <<"Right Child of " << front ->data << " : ";
        cin >> rightChild;
        cout << endl;
        if(rightChild!=-1)
        {
            BinaryTreeNode* right = new BinaryTreeNode(rightChild);
            front -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;
}
int solve(BinaryTreeNode* root, int &tilt)
{
     if(root == NULL)
    {
        return 0;
    }
    int leftTiltSum = solve(root->left,tilt);
    int rightTiltSum = solve(root->right,tilt);
     tilt += abs(leftTiltSum - rightTiltSum);
     //cout << "\nTilt  : " << root -> data << " : " << tilt << endl;
    // this will provide the sum of the tilts
    int totalSum = leftTiltSum + rightTiltSum + root -> data;
    //cout << "\nTotal Sum  : " << root -> data <<  " : " << totalSum;
    return totalSum;


}
int tiltBT(BinaryTreeNode* root)
{ 
   int tilt = 0;
   solve(root,tilt);
   return tilt;
  
}

int main()
{
    BinaryTreeNode* root = takeInput();
    cout << "\nTilt of the Binary Tree : " << tiltBT(root);
}
// 10 20 30 40 50 100 60 70 80 -1 90 -1  -1 -1 -1 -1 -1 -1 -1  -1 -1 