// C++ implementation of
// the above approach
#include <bits/stdc++.h>
using namespace std;

int oddsum = 0;
int evensum = 0;
int ans = 0;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Function calculate the sum of
// odd and even value node
void OddEvenDifference(struct node*
						root)
{
	// If root is NULL
	if (root == NULL) {
		return;
	}
	else {
		// Check if current root
		// is odd or even
		if (root->data % 2 == 0) {
			evensum += root->data;
		}
		else {
			oddsum += root->data;
		}
		// Call on the left subtree
		OddEvenDifference(root->left);

		// Call on the right subtree
		OddEvenDifference(root->right);
	}
}

// Driver Code
int main()
{
	node* root = newnode(5);
	root->left = newnode(2);
	root->right = newnode(6);
	root->left->left = newnode(1);
	root->left->right = newnode(4);
	root->left->right->left
		= newnode(3);
	root->right->right = newnode(8);
	root->right->right->right
		= newnode(9);
	root->right->right->left
		= newnode(7);

	OddEvenDifference(root);

	cout << abs(oddsum - evensum)
		<< endl;
}
