// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Initialise to update the maximum
// AND value from all the path
int maxm = 0;

// Node structure
struct Node {
	int val;

	// Left & right child of the node
	Node *left, *right;

	// Intialize consutructor
	Node(int x)
	{
		val = x;
		left = NULL;
		right = NULL;
	}
};

// Function to find the maximum value
// of Bitwise AND from root to leaf
// in a Binary tree
void maxm_Anding(Node* root, int ans)
{
	// Check if root is not null
	if (!root)
		return;

	if (root->left == NULL
		and root->right == NULL) {
		ans &= root->val;

		// Find the maxmimum AND value and
		// store in global maxm varibale
		maxm = max(ans, maxm);

		return;
	}

	// Traverse left of binary tree
	maxm_Anding(root->left,
				ans & root->val);

	// Traverse right of the binary tree
	maxm_Anding(root->right,
				ans & root->val);
}

// Driver Code
int main()
{
	// Given Tree
	Node* root = new Node(15);
	root->left = new Node(3);
	root->right = new Node(7);
	root->left->left = new Node(5);
	root->left->right = new Node(1);
	root->right->left = new Node(31);
	root->right->right = new Node(9);

	// Function Call
	maxm_Anding(root, root->val);

	// Print the maximum AND value
	cout << maxm << endl;

	return 0;
}
