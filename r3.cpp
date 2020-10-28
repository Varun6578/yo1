// Java program for the above approch
import java.util.*;

class GFG{
	
// Node structure
static class node
{
	int data;
	node left = null;
	node right = null;
}

// Creates and initilize a new node
static node newNode(int ch)
{
	
	// Allocating memory to a new node
	node n = new node();
	n.data = ch;
	n.left = null;
	n.right = null;
	return n;
}

// Function to find the height of tree 
static int Height(node root)
{
	if (root == null)
		return 0;
		
	return 1 + Math.max(Height(root.left), 
						Height(root.right));
}

// Given a perfect binary tree 
// print its node in Specific order
static void printSpecificLevelOrder(Queue<node> A,
									Queue<node> B,
									int height)
{
	while (height != 0)
	{
		
		// Get each one front 
		// element of both queue
		node X = A.poll();
		node Y = B.poll();
		
		// Check if X exist or not 
		if (X == null)
		{ 
			
			// Assume is has and put
			// their both child as none
			A.add(null);
			A.add(null);
		}
		else
		{ 
			
			// print the data and store 
			// their child first left 
			// then right
			System.out.print(X.data + " ");
			A.add(X.left);
			A.add(X.right);
		}
		
		// Check Y exist or not 
		if (Y == null)
		{ 
			
			// Assume is has and put
			// their both child as none
			B.add(null);
			B.add(null); 
		}
		else
		{
			
			// Print the data and store their
			// child first left then right
			System.out.print(Y.data + " ");
			B.add(Y.right);
			B.add(Y.left);
		}
		
		// Decrease by 1 unit 
		height -= 1;	 
	}
}

// Driver Code	 
public static void main (String[] args)
{
	
	// Given tree
	node root = newNode(1);
	root.left = newNode(2);
	root.right = newNode(3);
	
	root.left.left = newNode(4);
	root.left.right = newNode(5);
	root.right.right = newNode(7);
	
	root.left.left.left = newNode(8);
	root.left.left.right = newNode(9);
	root.left.right.left = newNode(10);
	root.left.right.right = newNode(11);
	root.right.right.left = newNode(14);
	root.right.right.right = newNode(15);
	
	root.left.left.left.left = newNode(16);
	root.left.left.left.right = newNode(17);
	root.left.left.right.left = newNode(18);
	root.left.left.right.right = newNode(19);
	root.left.right.left.left = newNode(20);
	root.left.right.left.right = newNode(21);
	root.left.right.right.left = newNode(22);
	root.left.right.right.right = newNode(23);
	root.right.right.left.left = newNode(28);
	root.right.right.left.right = newNode(29);
	root.right.right.right.left = newNode(30);
	root.right.right.right.right = newNode(31);
	
	// Initialise Queue
	Queue<node> A = new LinkedList<>();
	Queue<node> B = new LinkedList<>(); 
	
	int height = 0;
	
	// Check top root manually
	if (root != null)
	{ 
		System.out.print(root.data + " ");
		
		A.add(root.left);
		B.add(root.right);
		
		height = Height(root);
		height = (int)Math.pow(2, (height - 1)) - 1;
	}
	
	// Function Call
	printSpecificLevelOrder(A, B, height);
}
}

// This code is contributed by offbeat
