// C++ program for the above approach 

#include <iostream> 
#include <unordered_map> 
#include <vector> 
using namespace std; 

// Defining tree node 
struct node { 
	int value; 
	struct node *right, *left; 
}; 

// Utility function to create 
// a new node 
struct node* newnode(int key) 
{ 
	struct node* temp = new node; 
	temp->value = key; 
	temp->right = NULL; 
	temp->left = NULL; 

	return temp; 
} 

// Function to check binary 
// tree whether its every node 
// has value K or, it is 
// connected with node having 
// value K 
bool connectedK(node* root, 
				node* parent, 
				int K, 
				bool flag) 
{ 
	// checking node value 
	if (root->value != K) { 

		// checking the left 
		// child value 
		if (root->left == NULL 
			|| root->left->value != K) { 

			// checking the rigth 
			// child value 
			if (root->right == NULL 
				|| root->right->value != K) { 

				// checking the parent value 
				if (parent == NULL 
					|| parent->value != K) { 
					flag = false; 
					return flag; 
				} 
			} 
		} 
	} 

	// Traversing to the left subtree 
	if (root->left != NULL) { 
		if (flag == true) { 
			flag 
				= connectedK(root->left, 
							root, K, flag); 
		} 
	} 

	// Traversing to the right subtree 
	if (root->right != NULL) { 
		if (flag == true) { 
			flag 
				= connectedK(root->right, 
							root, K, flag); 
		} 
	} 
	return flag; 
} 

// Driver code 
int main() 
{ 

	// Input Binary tree 
	struct node* root = newnode(0); 
	root->right = newnode(1); 
	root->right->right = newnode(0); 
	root->left = newnode(0); 

	int K = 0; 

	// Function call to check 
	// binary tree 
	bool result 
		= connectedK(root, NULL, 
					K, true); 

	if (result == false) 
		cout << "False\n"; 
	else
		cout << "True\n"; 

	return 0; 
} 
