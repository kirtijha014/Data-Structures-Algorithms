#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class TreeNode{
	public:
		T data;
		vector<TreeNode*>children;
		TreeNode(T data)
		{
			this->data = data;
		}
		~TreeNode()
		{
			for(int i = 0 ; i <children.size(); i++)
			{
				delete(children[i]);
			}
		}
};
TreeNode<int>* takeInput()
{
	int rootData;
	cout << "Enter root data : ";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*>pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!= 0)
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout << "\nEnter no. of children of " << front -> data << " : " ;
		cin >> numChild;
		for(int i = 0; i < numChild; i++)
		{
			cout << "\nEnter " << i <<"th child of " << front->data << " : ";
			int childData;
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
	{
		cout << "No root present.\n";
		return;
	}
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numChild = front->children.size();
		cout <<"\n" << front->data << " : ";
		for(int i = 0; i < numChild; i++)
		{
			cout << front->children[i]->data << " ";
			pendingNodes.push(front->children[i]);
		}
		cout << endl;
	}
}

int count(TreeNode<int>* root)
{
	 int ans = 1; //calculating root as 1 and use recursion to calculate other nodes.
	 for(int i = 0; i < root->children.size(); i++)
	 {
		 ans += count(root->children[i]);
	 }

	 return ans;
}

int main()
{
	TreeNode<int>* root = takeInput();
	int ans = count(root);
	cout << "\nNumber of Nodes : " << ans;
	// printTree(root);
	delete root;
}