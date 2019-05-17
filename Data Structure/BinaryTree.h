#include <iostream>
#include "Node.h"

template <class T>
class BinarySearchTree {
private:
	TreeNode<T>* Top;
public:

	TreeNode<T>* TopNode() {
		return Top;
	}

	void AddNode(T data) {
		if (Top == NULL) {
			Top = new TreeNode(data);
		}
		else AddNode(Top, data);
	}

	void AddNode(TreeNode* node, T data){
		if (node->data > data)
			if (node->left == NULL)
				node->left = new TreeNode(data);
			else
				AddNode(node->left, data);
		else if(node->data < data)
			if (node->right == NULL)
				node->right = new TreeNode(data);
			else
				AddNode(node->right, data);
	}

	TreeNode<T>* FindNode(T data) {
		if (top == NULL) return NULL;
		else return FindNode(top, data);
	}

	TreeNode<T>* FindNode(TreeNode* node, T data) {
		if (node->data == data) return node;
		else if (node->data > data) {
			if (node->left == NULL) return NULL;
			return FindNode(node->left, data);
		}
		else if (node->data < data) {
			if (node->right == NULL) return NULL;
			return FindNode(node->right, data);
		}
	}
};
