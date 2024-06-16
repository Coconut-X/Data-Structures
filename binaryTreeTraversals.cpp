#include<iostream>
#include<queue>
using namespace std;

struct node {
	int data;
	node* right;
	node* left;
	node(){}
	node(int data): data(data), right(nullptr),left(nullptr){}
};

/// current-left-right
void preOrder(node* root)
{
	if (root == nullptr) return;
	cout << root->data << "  ";
	preOrder(root->left);
	preOrder(root->right);							///=================================///
}													///	 jahan pr "current"				///
													///	 aye ga wahan data				///
/// left-current-right								///	 print krna ha, these 3 are DFS ///
void inOrder(node* root)							///=================================///
{													
	if (root == nullptr) return;
	inOrder(root->left);
	cout << root->data << "  ";
	inOrder(root->right);
}

///left-right-current
void postOrder(node* root)
{
	if (root == nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << "  ";
}

///BFS (breadth first search)
void levelOrder(node* root)
{
	if (root == nullptr) return;
	
	queue<node*> Q;
	Q.push(root);

	while (!Q.empty())
	{
		node* current = Q.front();
		cout << current->data << "  ";
		Q.pop();
		if (current->left != nullptr) Q.push(current->left);
		if (current->right != nullptr) Q.push(current->right);
	}
}

void leaves(node* root)
{
	if (root == nullptr) return;
	if (root->right == nullptr && root->left == nullptr)
		cout << root->data << "  ";
	leaves(root->left);
	leaves(root->right);
}

void deAllocate(node*& root)
{
	///deletion by inorder
	if (root == nullptr) return;
	node* temp = root;
	deAllocate(temp->left);
	deAllocate(temp->right);
	delete root;
	root = nullptr;
	//cout << "root deleted\n";
}

int main()
{
	node* root = new node(10);
	root->left = new node(7);
	root->left->right = new node(3);
	root->left->left = new node(2);
	root->left->left->left = new node(0);
	root->left->left->left->left = new node(6);
	root->right = new node(8);
	root->right->right = new node(5);
	root->right->left = new node(4);
	root->right->left->right = new node(9);
	root->right->left->right->right = new node(11);

	cout << "Pre Order :" << endl;
	preOrder(root);
	cout << endl << endl << endl;

	cout << "In Order :" << endl;
	inOrder(root);
	cout << endl << endl << endl;

	cout << "Post Order :" << endl;
	postOrder(root);
	cout << endl << endl << endl;
	
	cout << "Leaves: " << endl;
	leaves(root);
	cout << endl << endl << endl;

	cout << "Level Order" << endl;
	levelOrder(root);
	cout << endl << endl << endl;

	deAllocate(root);

	return 0;
}
