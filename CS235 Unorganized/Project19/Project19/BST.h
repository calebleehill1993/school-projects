#ifndef BST_H
#define BST_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/** A binary tree node with data, left and right child pointers */
template<class T>
class BST
{
public:

	template<typename U>
	struct Node
	{
		U value;
		Node* leftChild;
		Node* rightChild;

		Node(const U& data) : value(data) {
			this->leftChild = NULL;
			this->rightChild = NULL;
		}

		Node(const U& data, Node<U> left, Node<U> right) {
			this->value = data;
			this->leftChild = left;
			this->rightChild = right;
		}

		~Node() {}
	};

	Node<T>* root;

	/**Creates a Binary Search Tree*/
	BST(void) {
		root = NULL;
	};

	virtual ~BST(void) {
		delete root;
	}

	/** Return true if node added to BST, else false */
	virtual bool addNode(const T& data) {
		if (this->root == NULL) {
			root = new Node<T>(data);
			return true;
		}
		else if (data < root->value) {
			return insert(this->root, data);
		}
		else if (data > root->value) {
			return insert(this->root, data);
		}
		else {
			return false;
		}
	}

	/** Return true if node removed from BST, else false */
	virtual bool removeNode(const T& data) {
		return erase(this->root, data);
	}

	/** Return true if BST cleared of all nodes, else false */
	virtual bool clearTree() {
		while (root != NULL) {
			removeNode(root->value);
		}
		return true;
	}

	/**Helps the addNode function to add a node to the Binary Search Tree*/
	bool insert(Node<T>* localRoot, const T& data) {
		if (localRoot->value > data) {
			if (localRoot->leftChild == NULL) {
				localRoot->leftChild = new Node<T>(data);
				return true;
			}
			else {
				return insert(localRoot->leftChild, data);
			}
		}
		else if (localRoot->value < data) {
			if (localRoot->rightChild == NULL) {
				localRoot->rightChild = new Node<T>(data);
				return true;
			}
			else {
				return insert(localRoot->rightChild, data);
			}
		}
		else {
			return false;
		}
	}

	/**Helps the removeNode and erase functions to move the nodes around to delete them*/
	void replaceParent(Node<T>*& oldRoot, Node<T>*& localRoot) {
		if (localRoot->rightChild != NULL) {
			replaceParent(oldRoot, localRoot->rightChild);
		}
		else {
			oldRoot->value = localRoot->value;
			oldRoot = localRoot;
			localRoot = localRoot->leftChild;
		}
	}

	/**Helps the removeNode function to delete the Node*/
	bool erase(Node<T>*& localRoot, const T& data) {
		if (localRoot == NULL) {
			return false;
		}
		else {
			if (data < localRoot->value) {
				return erase(localRoot->leftChild, data);
			}
			else if (localRoot->value < data) {
				return erase(localRoot->rightChild, data);
			}
			else {
				Node<T>* oldRoot = localRoot;
				if (localRoot->leftChild == NULL) {
					localRoot = localRoot->rightChild;
				}
				else if (localRoot->rightChild == NULL) {
					localRoot = localRoot->leftChild;
				}
				else {
					replaceParent(oldRoot, oldRoot->leftChild);
				}
				delete oldRoot;
				return true;
			}
		}
	}

	/** Output nodes at a given level */
	bool outLevel(Node<T>* root, int level, stringstream& out) const
	{
		if (root == NULL) return false;
		if (level == 0) {
			out << " " << root->value;
			if ((root->leftChild != NULL) || (root->rightChild != NULL)) return true;
			return false;
		}
		if ((level == 1) && !root->leftChild && root->rightChild) out << " _";
		bool left = outLevel(root->leftChild, level - 1, out);
		bool right = outLevel(root->rightChild, level - 1, out);
		if ((level == 1) && root->leftChild && !root->rightChild) out << " _";
		return left || right;
	} // end outLevel()

	  /** Return a level order traversal of a BST as a string */
	virtual string toString() const
	{
		stringstream out;
		if (root == NULL) {
			out << " Empty";
		}
		else
		{
			int level = -1;
			do
			{
				out << endl << "  ";
				level++;
			} while (outLevel(root, level, out));
		}
		return out.str();
	} // end toString()

};

#endif 
