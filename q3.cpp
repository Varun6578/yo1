// C++ program of the
// above approach

#include <bits/stdc++.h>
using namespace std;

// Structure of
// binary tree node
struct Node {
	int data;
	Node *left, *right;
};

// Function to create new node
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Utility function which calculates
// smallest three nodes of all leaf nodes
void storeLeaf(Node* root, vector<int>& arr)
{
	if (!root)
		return;

	// Check if current root is a leaf node
	if (!root->left and !root->right) {
		arr.push_back(root->data);
		return;
	}

	// Traverse the left
	// and right subtree
	storeLeaf(root->left, arr);
	storeLeaf(root->right, arr);
}

// Function to find the K smallest
// nodes of the Binary Tree
void KSmallest(Node* root, int k)
{
	vector<int> arr;
	storeLeaf(root, arr);

	// Sorting the Leaf nodes array
	sort(arr.begin(), arr.end());

	// Loop to print the K smallest
	// Leaf nodes of the array
	for (int i = 0; i < k; i++) {
		if (i < arr.size()) {
			cout << arr[i] << " ";
		}
		else {
			break;
		}
	}
}

// Driver Code
int main()
{
	// Construct binary tree
	Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->left->left = newNode(21);
	root->left->right = newNode(5);
	root->left->right->right = newNode(8);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->right = newNode(19);

	// Function Call
	KSmallest(root, 3);
	return 0;
}
