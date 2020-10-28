// C++14 program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Stores the ct of
// nodes which are maximum
// in the path from root
// to the current node
int ct = 0;

// Binary Tree Node
struct Node 
{
	int val;
	Node *left, *right;
	
	Node(int x)
	{
		val = x;
		left = right = NULL;
	}
};

// Function that performs Inorder
// Traversal on the Binary Tree
void find(Node *root, int mx)
{
	
	// If root does not exist
	if (root == NULL)
	return;
	
	// Check if the node
	// satisfies the condition
	if (root->val >= mx)
		ct++;
	
	// Update the maximum value
	// and recursively traverse
	// left and right subtree
	find(root->left, max(mx, root->val));
	
	find(root->right, max(mx, root->val));
}

// Function that counts the good
// nodes in the given Binary Tree
int NodesMaxInPath(Node* root)
{
	
	// Perform inorder Traversal
	find(root, INT_MIN);
	
	// Return the final count
	return ct;
}

// Driver code
int main()
{
	
	/* A Binary Tree 
			3 
			/ \ 
			2 5 
		/	 \ 
		4	 6 
		*/
	Node* root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(4);
	root->right->right = new Node(7);
	
	// Function call
	int answer = NodesMaxInPath(root);
	
	// Print the count of good nodes
	cout << (answer);
	return 0;
}

// This code is contributed by mohit kumar 29
