#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* takeInput()
{
	int rootData;
	cout << "\nEnter Root Data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "\nEnter no. of children of " << front -> data << " : ";
		int numChild;
		cin >> numChild;
		for(int i = 0; i < numChild ; i++)
		{
			int childData;
			cout << "Enter : " << i << "th child of " << front -> data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
void printTree(TreeNode<int>* root)
{
	if(root == NULL)
	return;
	
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!= 0)
	{
	
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numChild = front -> children.size();
		cout << front -> data << " : ";	
		for(int i =0 ; i < numChild; i++)
		{
			cout << front ->children[i]-> data << " ";
			pendingNodes.push(front -> children[i]);
		}
		cout << endl;
	}
}
int main()
{
	TreeNode<int>* root = takeInput();
	printTree(root);
}
