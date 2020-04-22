/*
	Vento, Jack

	April 22, 2020

	CS A200
	Lab 4: Binary Search Trees
*/

#include "BST.h"

using namespace std;

// Definition function insert (non-recursive) 
void BST::insert(int item)
{
	if (root == nullptr)
	{
		root = new Node();
		root->data = item;
	}
	else
	{
		Node* search = root;
		Node* parent = nullptr;
		
		bool duplicate = false;

		while (search != nullptr)
		{
			if (item == search->data)
			{
				duplicate = true;
				break;
			}
			
			parent = search;

			if (item < search->data)
				search = search->llink;
			else
				search = search->rlink;
		}
		
		if (duplicate)
			cerr << "The item (" + to_string(item) + 
			") to insert is already in the list - duplicates are not allowed." << endl;

		if (!duplicate && item < parent->data)
		{
			parent->llink = new Node();
			parent->llink->data = item;
		}
		else if (!duplicate)
		{
			parent->rlink = new Node();
			parent->rlink->data = item;
		}
	}
}

// Definition function totalNodes
int BST::totalNodes() const
{
	return totalNodes(root);
}

// Definition function totalNodes (recursive)
int BST::totalNodes(const Node* p) const
{
	if (p == nullptr)
		return 0;

	int count = 1;

	if (p->llink != nullptr)
		count += totalNodes(p->llink);

	if (p->rlink != nullptr)
		count += totalNodes(p->rlink);

	return count;
}

// Definition overloaded function preorderTraversal
void BST::preorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
		preorderTraversal(root);
}

// Definition overloaded function preorderTraversal (recursive)
void BST::preorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		cout << p->data << " ";
		preorderTraversal(p->llink);
		preorderTraversal(p->rlink);
	}
}


// Definition overloaded function postorderTraversal
void BST::postorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
		postorderTraversal(root);
}

// Definition overloaded function postorderTraversal (recursive)
void BST::postorderTraversal(const Node* p) const
{
	if (p != nullptr)
	{
		postorderTraversal(p->llink);
		postorderTraversal(p->rlink);
		cout << p->data << " ";
	}
}