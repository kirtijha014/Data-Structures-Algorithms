 #include<iostream>
#include <vector>
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

void printTree(TreeNode<int>* root)
{
	//edge case
	if(root == NULL)
	{
		return;
	}
	cout << root->data << " : ";
	for(int i = 0; i < root->children.size(); i++)
	{
		cout << root->children[i]->data<< ", ";
	}
	cout << endl;
	for(int i =0; i< root->children.size(); i++)
	{
		printTree(root->children[i]);
	}
}

int main()
{
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	TreeNode<int>* node3 = new TreeNode<int>(4);
	TreeNode<int>* node4 = new TreeNode<int>(5);
	TreeNode<int>* node5 = new TreeNode<int>(6);	
	TreeNode<int>* node6 = new TreeNode<int>(7);
	TreeNode<int>* node7 = new TreeNode<int>(8);
	TreeNode<int>* node8 = new TreeNode<int>(9);
	TreeNode<int>* node9 = new TreeNode<int>(10);	
	root->children.push_back(node1);
	root->children.push_back(node2);
	node1->children.push_back(node3);
	node1->children.push_back(node4);
	node1->children.push_back(node5);
	node2->children.push_back(node6);
	node6->children.push_back(node7);
	node6->children.push_back(node8);
	node6->children.push_back(node9);
	printTree(root);
	
	
	
}
