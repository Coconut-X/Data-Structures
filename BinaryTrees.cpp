#include<iostream>
#include<queue>
using namespace std;

struct node {
	int data;
	node* right;
	node* left;
	node() :right(nullptr), left(nullptr) {}
	node(int data) : data(data), right(nullptr), left(nullptr) {}
};
///=======================================================================

/// current-left-right
void preOrder(node* root)
{
	if (root == nullptr) return;
	cout << root->data << "  ";
	preOrder(root->left);
	preOrder(root->right);							///=================================///
}													///  jahan pr "current"				///
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
		//if(current!=nullptr)
			cout << current->data << "  ";
		Q.pop();
		if (current->left != nullptr) Q.push(current->left);
		if (current->right != nullptr) Q.push(current->right);
	}
	cout << endl;
}

void leaves(node* root)
{
	if (root == nullptr) return;
	if (root->right == nullptr && root->left == nullptr)
		cout << root->data << "  ";
	leaves(root->left);
	leaves(root->right);
}

void insertByLevel(node*& root, int data) ///balanced tree
{
	node* newNode = new node(data);
	if (root == nullptr)
	{
		root = newNode;
		return;
	}

	queue<node*> Q;
	Q.push(root);

	while (!Q.empty())
	{
		node* temp = Q.front();
		Q.pop();

		if (temp->left == nullptr)
		{
			temp->left = newNode;
			return;
		}
		else
		{
			Q.push(temp->left);
		}
		if (temp->right == nullptr)
		{
			temp->right = newNode;
			return;
		}
		else
		{
			Q.push(temp->right);
		}
	}
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

void Insertion_binary_Search_Tree(node*& root, int data)
{
	node* newNode = new node(data);
	if (root == nullptr)
	{
		root = newNode;
		return;
	}

	node* current = root;
	while (true)
	{
		if (data >= current->data)
		{
			if (current->right == nullptr)
			{
				current->right = newNode;
				return;
			}
			else
			{
				current = current->right;
			}
		}
		else
		{
			if (current->left == nullptr)
			{
				current->left = newNode;
				return;
			}
			else
			{
				current = current->left;
			}
		}
	}
}

void searchInBST(node* root, int key)
{
	node* current = root;
	string path = "root";

	if (root == nullptr)
	{
		cout << "Empty" << endl;
		return;
	}
	do
	{
		if (current->data == key)
		{
			cout << "Found" << endl;
			cout << "Path: " << path << endl;
			return;
		}

		if (key < current->data && current->left != nullptr)
		{
			current = current->left;
			path += "->left";
		}
		else if (current->right != nullptr)
		{
			current = current->right;
			path += "->right";
		}

	} while (current != nullptr);

	cout << "Not Found!" << endl;
}

bool searchUsingPreOrder_GeneralBinaryTree(node* root, int key,int data)
{
	if (root == nullptr) return false;
	if (root->data == key)
	{
		root->data = data;
		return true;
	}
	bool A = searchUsingPreOrder_GeneralBinaryTree(root->left, key, data);
	bool B = searchUsingPreOrder_GeneralBinaryTree(root->right, key, data);
	return A || B;
}

void deletion_in_binary_tree(node*& root, int key)
{
	///replace the node by bottom most && right most node
	///nodeToBeDeleted->data=bottom_most_right_most->data
	/// now delete bottom most right most
	/// the actual not to be deleted will not be deleted (only data replaced)
	node* bottom_right = root;
	node* parent_bottom_right = root;
	while (bottom_right->right != nullptr)
	{
		parent_bottom_right = bottom_right;
		bottom_right = bottom_right->right;
	}
	int data = bottom_right->data;
	///do not delete this node until the key is found
	///search node with given value using pre order
	if (searchUsingPreOrder_GeneralBinaryTree(root, key, data))
	{
		if (bottom_right->left != nullptr)
			parent_bottom_right->right = bottom_right->left;
		else parent_bottom_right->right = nullptr;
		delete bottom_right;
		bottom_right = nullptr;
		cout << "Deleted" << endl;
		return;
	}
	cout << "Not Found" << endl;
}

void deletion_In_Binary_SEARCH_Tree(node*& root, int key)
{
	if (root == nullptr) return;

	if (key < root->data)
		deletion_In_Binary_SEARCH_Tree(root->left, key);
	else if (key > root->data)
		deletion_In_Binary_SEARCH_Tree(root->right, key);
	else ///key == root->data, found the node to delete
	{
		///node to delete is a leaf node
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		///node to delete has only one child
		else if (root->left == nullptr)
		{
			node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr)
		{
			node* temp = root;
			root = root->left;
			delete temp;
		}
		/// node to delete has both left and right children
		else
		{
			///find the inorder successor (min value in right subtree)
			node* min = root->right;
			node* parentMin = root;

			while (min->left != nullptr)
			{
				parentMin = min;
				min = min->left;
			}
			root->data = min->data;

			/// delete the inorder successor node
			if (parentMin->left == min)
				parentMin->left = min->right;
			else
				parentMin->right = min->right;

			delete min;
			//we can also do this by recursively deleting inorder successor
			//deletion_In_Binary_SEARCH_Tree(root->right, min->data);
		}
	}
}


int height_of_binary_tree(node* root)
{
	int height = 0;
	if (root == nullptr) return -1;

	queue<node*>Q;
	Q.push(root);

	while (!Q.empty())
	{
		int size = Q.size();

		for (int i = 0; i < size; i++)
		{
			node* temp = Q.front();
			Q.pop();

			if (temp->left != nullptr)
			{
				Q.push(temp->left);
			}

			if (temp->right != nullptr)
			{
				Q.push(temp->right);
			}
		}
		height++;
	}
	return height;
}

///for general binary tree/ level order
int depth_of_node(node* root, int key)
{
	int height = 0;

	queue<node*>Q;
	Q.push(root);

	while (!Q.empty())
	{
		int size = Q.size();

		for (int i = 0; i < size; i++)
		{
			node* temp = Q.front();
			Q.pop();

			if (temp->left != nullptr) ///exception here
			{
				Q.push(temp->left);
			}

			if (temp->right != nullptr)
			{
				Q.push(temp->right);
			}
			if (key == temp->data)
			{
				return height;
			}
		}
		height++;
	}
	return -1;
}

int depth_of_node_in_bst(node* root, int key)
{
	int depth = 0;
	node* temp = root;
	while (true)
	{
		if (key == temp->data) return depth;
		if (key >= temp->data && temp->right != nullptr) temp = temp->right, depth++;
		else if (key < temp->data && temp->left != nullptr) temp = temp->left, depth++;
		else return -1;
	}
	return 0;
}

int main()
{
	cout << "General		Binary			 tree" << endl << endl << endl;
	node* root = new node(10);
	root->left = new node(7);
	root->left->right = new node(3);
	root->left->left = new node(2);
	root->left->left->left = new node(0);
	root->left->left->left->left = new node(6);
	root->right = new node(8);
	root->right->right = new node(5);
	root->right->right->left = new node(99);///
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
	///=====================

	cout << "Before Deletion" << endl;
	levelOrder(root);
	cout << "\nAfter Deletion" << endl;
	deletion_in_binary_tree(root, 3);
	levelOrder(root);

	///=====================

	deAllocate(root);

	//system("cls");
	cout << "\n====================================================================" << endl << endl;
	///==============================================================================

	cout << "LEVEL ORDER TREE" << endl << endl;

	node* root2 = new node();
	root2 = nullptr;
	insertByLevel(root2, 10);
	insertByLevel(root2, 7);
	insertByLevel(root2, 3);
	insertByLevel(root2, 2);
	insertByLevel(root2, 0);
	insertByLevel(root2, 6);
	insertByLevel(root2, 8);
	insertByLevel(root2, 5);
	insertByLevel(root2, 4);
	insertByLevel(root2, 9);
	insertByLevel(root2, 11);

	cout << "Level Order Insertion:" << endl;
	levelOrder(root2);

	cout << endl << endl << "Height of Binary Tree: " << height_of_binary_tree(root2) << endl;


	cout << "Depth of Node with value 9: " << depth_of_node(root2, 9);
	deAllocate(root2);

	cout << "\n====================================================================" << endl << endl;
	///===================================================================================


	cout << "	BINARY		SEARCH		TREE" << endl << endl << endl;

	node* bst = new node();
	bst = nullptr;
	Insertion_binary_Search_Tree(bst, 8);
	Insertion_binary_Search_Tree(bst, 3);
	Insertion_binary_Search_Tree(bst, 10);
	Insertion_binary_Search_Tree(bst, 1);
	Insertion_binary_Search_Tree(bst, 6);
	Insertion_binary_Search_Tree(bst, 14);
	Insertion_binary_Search_Tree(bst, 4);
	Insertion_binary_Search_Tree(bst, 7);
	Insertion_binary_Search_Tree(bst, 13);
	Insertion_binary_Search_Tree(bst, 18);
	Insertion_binary_Search_Tree(bst, 19);
	levelOrder(bst);
	cout << "\nDeleting 8:" << endl;
	deletion_In_Binary_SEARCH_Tree(bst, 8);

	levelOrder(bst);


	cout << "\nSearching 4: " << endl;
	searchInBST(bst, 4);


	cout << endl << endl << "Height of Binary Tree: " << height_of_binary_tree(bst);
	cout << endl << endl << "Depth of Node 6: " << depth_of_node_in_bst(bst, 6);

	deAllocate(bst);

	cout << "\n====================================================================" << endl << endl;
	///=============================================================================================

	return 0;
}
