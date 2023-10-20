#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include "dsexceptions.h"
#include <algorithm>
using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// void displayTree()     --> Print the tree structure
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template<typename Comparable>
class BinarySearchTree {
public:
	void displayLinks(ostream &out = cout) const {
		if (isEmpty())
			out << "Empty tree" << endl;
		else
			displayLinks(root, 0, out);
	}
	int height() {
		return height(root);
	}
//	int depth(const Comparable &x) {
//		return depth(x, root);
//	}

	int depth(Comparable &x) {
		return depth(x, root);
	}

	int contains_search_depth( const Comparable &x) {
		return contains_search_depth(x, root);

	}

	const int contains_search_depth( const Comparable &x) const{
		return contains_search_depth(x, root);

	}


//
//	const int contains_search_depth( Comparable &x) {
//		return contains_search_depth(x, root);
//
//	}
	void bushy(int start, int end, Comparable a[]) {
		//variable: start index, end index, array
		//T2 is inserted with median
		//then median of subtrees and so on
		//such that every sub root is the median of its descendant
		if (end - start == 1) {

			//cout<<a[start]<<endl;
			//cout<<a[end]<<endl;
			insert(a[start]);
			insert(a[end]);    		//stopping case 1
//    		cout<<"print: ";
//    		T.displayLinks();

		} else if (abs(end - start) == 0) {

			insert(a[start]);
//    		cout<<"print: ";
//    		T.displayLinks();
//    		cout<<a[start]<<endl;
			//stopping case 2
		} else {
			int m = (end - start) / 2;
			if (m != 0) {
				insert(a[start + m]);    		 //inserting the median
//			cout<<"print: ";
//			T.displayLinks();
//			cout<<a[start+m]<<endl;
				bushy(start, (m - 1) + start, a);
				bushy(start + m + 1, end, a);
			}
		}
	}

	void bushy(int start, int end, Comparable a[]) const {

		if (end - start == 1) {

			//cout<<a[start]<<endl;
			//cout<<a[end]<<endl;
			insert(a[start]);
			insert(a[end]);    		//stopping case 1
//    		cout<<"print: ";
//    		T.displayLinks();

		} else if (abs(end - start) == 0) {

			insert(a[start]);
//    		cout<<"print: ";
//    		T.displayLinks();
//    		cout<<a[start]<<endl;
			//stopping case 2
		} else {
			int m = (end - start) / 2;
			if (m != 0) {
				insert(a[start + m]);    		 //inserting the median
//			cout<<"print: ";
//			T.displayLinks();
//			cout<<a[start+m]<<endl;
				bushy(start, (m - 1) + start, a);
				bushy(start + m + 1, end, a);
			}
		}
	}

	BinarySearchTree() :
			root { nullptr } {
	}

	/**
	 * Copy constructor
	 */
	BinarySearchTree(const BinarySearchTree &rhs) :
			root { nullptr } {
		root = clone(rhs.root);
	}

	/**
	 * Move constructor
	 */
	BinarySearchTree(BinarySearchTree &&rhs) :
			root { rhs.root } {
		rhs.root = nullptr;
	}

	/**
	 * Destructor for the tree
	 */
	~BinarySearchTree() {
		makeEmpty();
	}

	/**
	 * Copy assignment
	 */
	BinarySearchTree& operator=(const BinarySearchTree &rhs) {
		BinarySearchTree copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	/**
	 * Move assignment
	 */
	BinarySearchTree& operator=(BinarySearchTree &&rhs) {
		std::swap(root, rhs.root);
		return *this;
	}

	/**
	 * Find the smallest item in the tree.
	 * Throw UnderflowException if empty.
	 */
	const Comparable& findMin() const {
		if (isEmpty())
			throw UnderflowException { };
		return findMin(root)->element;
	}

	/**
	 * Find the largest item in the tree.
	 * Throw UnderflowException if empty.
	 */
	const Comparable& findMax() const {
		if (isEmpty())
			throw UnderflowException { };
		return findMax(root)->element;
	}

	/**
	 * Returns true if x is found in the tree.
	 */
	bool contains(const Comparable &x) const {
		return contains(x, root);
	}

	/**
	 * Test if the tree is logically empty.
	 * Return true if empty, false otherwise.
	 */
	bool isEmpty() const {
		return root == nullptr;
	}

	/**
	 * Print the tree contents in sorted order.
	 */
	void printTree(ostream &out = cout) const {
		if (isEmpty())
			out << "Empty tree" << endl;
		else
			printTree(root, out);
	}

	void printTree(ostream &out = cout) {
		if (isEmpty())
			out << "Empty tree" << endl;
		else
			printTree(root, out);
	}
	/**
	 * Print the tree structure in sorted order.
	 */
	void displayTree(ostream &out = cout) const {
		if (isEmpty())
			out << "Empty tree" << endl;
		else
			displayTree(root, 0, out);
	}

	void displayTree(ostream &out = cout) {
		if (isEmpty())
			out << "Empty tree" << endl;
		else
			displayTree(root, 0, out);
	}

	/**
	 * Make the tree logically empty.
	 */
	void makeEmpty() {
		makeEmpty(root);
	}

	/**
	 * Insert x into the tree; duplicates are ignored.
	 */
	void insert(const Comparable &x) {
		insert(x, root);
	}

	void insert(Comparable &x) {
		insert(x, root);
	}

	/**
	 * Insert x into the tree; duplicates are ignored.
	 */
	void insert(Comparable &&x) {
		insert(std::move(x), root);
	}

	/**
	 * Remove x from the tree. Nothing is done if x is not found.
	 */
	void remove(const Comparable &x) {
		remove(x, root);
	}

private:
	struct BinaryNode {
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt) :
				element { theElement }, left { lt }, right { rt } {
		}

		BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt) :
				element { std::move(theElement) }, left { lt }, right { rt } {
		}
	};

	BinaryNode *root;

	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert(const Comparable &x, BinaryNode *&t) {
		if (t == nullptr)
			t = new BinaryNode { x, nullptr, nullptr };
		else if (x < t->element)
			insert(x, t->left);
		else if (t->element < x)
			insert(x, t->right);
		else
			;  // Duplicate; do nothing
	}

	void insert(Comparable &x, BinaryNode *&t) {
		if (t == nullptr)
			t = new BinaryNode { x, nullptr, nullptr };
		else if (x < t->element)
			insert(x, t->left);
		else if (t->element < x)
			insert(x, t->right);
		else
			;  // Duplicate; do nothing
	}

	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void insert(Comparable &&x, BinaryNode *&t) {
		if (t == nullptr)
			t = new BinaryNode { std::move(x), nullptr, nullptr };
		else if (x < t->element)
			insert(std::move(x), t->left);
		else if (t->element < x)
			insert(std::move(x), t->right);
		else
			;  // Duplicate; do nothing
	}

	/**
	 * Internal method to remove from a subtree.
	 * x is the item to remove.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void remove(const Comparable &x, BinaryNode *&t) {
		if (t == nullptr)
			return;   // Item not found; do nothing
		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else if (t->left != nullptr && t->right != nullptr) // Two children
				{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		} else {
			BinaryNode *oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete oldNode;
		}
	}

	/**
	 * Internal method to find the smallest item in a subtree t.
	 * Return node containing the smallest item.
	 */
	BinaryNode* findMin(BinaryNode *t) const {
		if (t == nullptr)
			return nullptr;
		if (t->left == nullptr)
			return t;
		return findMin(t->left);
	}

	/**
	 * Internal method to find the largest item in a subtree t.
	 * Return node containing the largest item.
	 */
	BinaryNode* findMax(BinaryNode *t) const {
		if (t != nullptr)
			while (t->right != nullptr)
				t = t->right;
		return t;
	}

	/**
	 * Internal method to test if an item is in a subtree.
	 * x is item to search for.
	 * t is the node that roots the subtree.
	 */
	bool contains(const Comparable &x, BinaryNode *t) const {
		if (t == nullptr)
			return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return true;    // Match
	}
	/****** NONRECURSIVE VERSION*************************
	 int contains_search_depth( const Comparable & x, BinaryNode *t ) const
	 {
	 while( t != nullptr )
	 if( x < t->element )
	 t = t->left;
	 else if( t->element < x )
	 t = t->right;
	 else
	 return depth(t->element,root);    // Match

	 return depth(t->element,root);   // No match
	 }
	 *****************************************************/

	int contains_search_depth( const Comparable &x, BinaryNode *t) {
		if (contains(x)){
			return depth(x,t);
		}
		BinaryNode* temp;
		while (t != nullptr) {
			if (x < t->element)
			{	temp = t;
				t = t->left;
			}else if (t->element < x){
				temp = t;
				t = t->right;
			}
		}

		return depth(temp->element);



	}

	const int contains_search_depth(const Comparable &x, BinaryNode *t) const {
		if (contains(x)){
				return depth(x,root);
			}
			BinaryNode* temp;
			while (t != nullptr) {
				if (x < t->element)
				{	temp = t;
					t = t->left;
				}else if (t->element < x){
					temp = t;
					t = t->right;
				}
			}

			return depth(temp->element);


	}

	/**
	 * Internal method to make subtree empty.
	 */
	void makeEmpty(BinaryNode *&t) {
		if (t != nullptr) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	/**
	 * Internal method to print a subtree rooted at t in sorted order.
	 */
	void printTree(BinaryNode *t, ostream &out) const {
		if (t != nullptr) {
			printTree(t->left, out);
			out << t->element << endl;
			printTree(t->right, out);
		}
	}

	/**
	 * Internal method to print a subtree rooted at t in sorted order.
	 */
	void displayTree(BinaryNode *t, int depth, ostream &out) {
		const int SHIFT = 4;
		if (t != nullptr) {
			for (int i = 0; i < SHIFT * depth; i++) {
				out << " ";
			}
			out << t->element << endl;
			displayTree(t->left, depth + 1, out);
			displayTree(t->right, depth + 1, out);
		}
	}

	void displayLinks(BinaryNode *t, int depth, ostream &out) const {
		const int SHIFT = 4;
		if (t != nullptr) {
			for (int i = 0; i < SHIFT * depth; i++) {
				out << " ";
			}
			//out << t->element << endl;
			out << t->element << ") @:" << t << "  L:" << t->left << " R:"
					<< t->right << endl;
			;
			displayLinks(t->left, depth + 1, out);
			displayLinks(t->right, depth + 1, out);
		}
	}

	int height(BinaryNode *nodeA) {
		if (isLeaf(nodeA)) {
			//return 1;
			return 0;
		} else if (hasOneLeftChild(nodeA)) {

			return 1 + height(nodeA->left);
		} else if (hasOneRightChild(nodeA)) {

			return 1 + height(nodeA->right);
		} else {

			return 1 + max(height(nodeA->left), height(nodeA->right));

		}
	}
	bool hasTwoChild(BinaryNode *node1) {
		return (node1->left != nullptr && node1->right != nullptr);
	}

	bool isLeaf(BinaryNode *node1) {
		return (node1->left == nullptr && node1->right == nullptr);
	}

	bool hasOneLeftChild(BinaryNode *node1) {
		return (node1->left != nullptr && node1->right == nullptr);
	}

	bool hasOneRightChild(BinaryNode *node1) {
		return (node1->left == nullptr && node1->right != nullptr);
	}
//    int depth(const Comparable & x) const{
//    	return depth(x,root);
//    }
	int depth( const Comparable &x, BinaryNode *t) { //assume x is in the tree
		while (t->element != x) {
			if (x > t->element) {
				return 1 + depth(x, t->right);
			}
			if (x < t->element) {
				return 1 + depth(x, t->left);
			}
		}
		return 0;
	}

	/**
	 * Internal method to clone subtree.
	 */
	BinaryNode* clone(BinaryNode *t) const {
		if (t == nullptr)
			return nullptr;
		else
			return new BinaryNode { t->element, clone(t->left), clone(t->right) };
	}
};

#endif
