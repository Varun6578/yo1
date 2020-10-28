// C++ program to implement 
// the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Structure of the binary tree 
struct Node { 
	// Stores data 
	int data; 

	// Stores left child 
	Node* left; 

	// Stores right child 
	Node* right; 

	// Initialize a node 
	// of binary tree 
	Node(int val) 
	{ 

		// Update data; 
		data = val; 
		left = right = NULL; 
	} 
}; 

// Function to find maximum count 
// of even nodes in a path 
int cntMaxEvenNodes(Node* root) 
{ 

	// If the tree is an 
	// empty binary tree. 
	if (root == NULL) { 
		return 0; 
	} 

	// Stores count of even nodes 
	// in current subtree 
	int cntEven = 0; 

	// If root node is 
	// an even node 
	if (root->data % 2 
		== 0) { 

		// Update cntEven 
		cntEven += 1; 
	} 

	// Stores count of even nodes 
	// in left subtree. 
	int X = cntMaxEvenNodes( 
		root->left); 

	// Stores count of even nodes 
	// in right subtree. 
	int Y = cntMaxEvenNodes( 
		root->right); 

	// cntEven 
	cntEven += max(X, Y); 

	return cntEven; 
} 

// Function to print paths having 
// count of even nodes equal 
// to maximum count of even nodes 
void printPath(Node* root, int cntEven, 
			int cntMaxEven, 
			vector<int>& path) 
{ 
	// If the tree is an 
	// empty Binary Tree 
	if (root == NULL) { 
		return; 
	} 

	// If current node value is even 
	if (root->data % 2 == 0) { 
		path.push_back( 
			root->data); 
		cntEven += 1; 
	} 

	// If current node is 
	// a leaf node 
	if (root->left == NULL 
		&& root->right == NULL) { 

		// If count of even nodes in 
		// path is equal to cntMaxEven 
		if (cntEven == cntMaxEven) { 

			// Stores length of path 
			int N = path.size(); 

			// Print path 
			for (int i = 0; i < N - 1; 
				i++) { 
				cout << path[i] << " -> "; 
			} 
			cout << path[N - 1] << endl; 
		} 
	} 

	// Left subtree 
	printPath(root->left, cntEven, 
			cntMaxEven, path); 

	// Right subtree 
	printPath(root->right, cntEven, 
			cntMaxEven, path); 

	// If current node is even 
	if (root->data % 2 == 0) { 
		path.pop_back(); 

		// Update cntEven 
		cntEven--; 
	} 
} 

// Utility Function to print path 
// from root to leaf node having 
// maximum count of even nodes 
void printMaxPath(Node* root) 
{ 
	// Stores maximum count of even 
	// nodes of a path in the tree 
	int cntMaxEven; 

	cntMaxEven 
		= cntMaxEvenNodes(root); 

	// Stores path of tree having 
	// even nodes 
	vector<int> path; 

	printPath(root, 0, cntMaxEven, 
			path); 
} 

// Driver code 
int main() 
{ 
	// Create tree. 
	Node* root = NULL; 
	root = new Node(2); 
	root->left = new Node(6); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(7); 
	root->right->right = new Node(11); 
	root->left->left->left = new Node(10); 
	root->left->left->right = new Node(12); 
	root->left->right->right = new Node(1); 

	printMaxPath(root); 
} 
