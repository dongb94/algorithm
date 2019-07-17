/* Include 
BinaryTree		      : 2019.7.16
BinarySearchTree      : 2019.5.17
*/ 

#include <iostream>
#include <queue>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Node.h"

template<class T>
class BinaryTree {
private:
	int count;
	TreeNode<T>* TopNode;
	std::deque<TreeNode<T>*> LeafNodeQueue;

public :
	BinaryTree(){
		count = 0;
		LeafNodeQueue = new std::deque<TreeNode<T>*>();
	}

	BinaryTree(T data) {
		BinaryTree();
		insert(data);
	}

	void insert(T data) {
		if (count == 0) {
			TopNode = new TreeNode<T>(data);
			LeafNodeQueue.push_back(TopNode);
		}
		else {
			TreeNode<T>* parent = LeafNodeQueue.front();
			TreeNode<T>* newNode = new TreeNode<T>(data);
			if (parent->left == NULL) {
				parent->addLeft(newNode);
				LeafNodeQueue.push_back(newNode);
			}
			else if(parent->right == NULL) {
				parent->addRight(newNode);
				LeafNodeQueue.push_back(newNode);
				LeafNodeQueue.pop_front();
			}
			else {
				LeafNodeQueue.pop_front();
				insert(data);
				return;
			}
		}
		count++;
	}

	TreeNode<T>* search(T data) {
		if (count == 0) return NULL;
		if (TopNode->data == data) return TopNode;
		std::queue<TreeNode<T>*> searchNodeQueue = new std::queue<TreeNode<T>*>();
		searchNodeQueue.push(TopNode);
		while (searchNodeQueue.size != 0) {
			TreeNode<T>* searchNode = searchNodeQueue.front();
			if (searchNode->data == data) return searchNode;
			if (searchNode->left != NULL) searchNodeQueue.push(searchNode->left);
			if (searchNode->right != NULL) searchNodeQueue.push(searchNode->right);
			searchNodeQueue.pop();
		}
		return NULL;
	}

	void remove(T data) {
		if (count == 0) return;
		std::queue<TreeNode<T>*> searchNodeQueue = new std::queue<TreeNode<T>*>();
		TreeNode<T>* replaceNode = LeafNodeQueue.back();
		
		if (replaceNode->data == data) {
			count--;
			if (replaceNode == TopNode) {
				TopNode = NULL;
				return;
			}
			if (replaceNode->parent->right == replaceNode)
				LeafNodeQueue.push_front(replaceNode->parent);
			LeafNodeQueue.pop_back();
			replaceNode->remove();
			return;
		}

		searchNodeQueue.push(TopNode);
		while (searchNodeQueue.size != 0) {
			TreeNode<T>* searchNode = searchNodeQueue.front();
			if (searchNode->data == data) {

				searchNode->data = replaceNode->data;

				if (replaceNode->parent->right == replaceNode)
					LeafNodeQueue.push_front(replaceNode->parent);
				LeafNodeQueue.pop_back();
				replaceNode->remove();
				count--;
				return;
			}
			if (searchNode->left != NULL) searchNodeQueue.push(searchNode->left);
			if (searchNode->right != NULL) searchNodeQueue.push(searchNode->right);
			searchNodeQueue.pop();
		}
	}

	TreeNode<T>* getRandomNode() {
		if (count == 0) return NULL;
		int ran = srand((unsigned int)time(NULL)) % count;

		std::queue<TreeNode<T>*> searchNodeQueue = new std::queue<TreeNode<T>*>();
		TreeNode<T>* searchNode;
		searchNodeQueue.push(TopNode);
		while (ran != -1) {
			searchNode = searchNodeQueue.front();
			if (searchNode->left != NULL) searchNodeQueue.push(searchNode->left);
			if (searchNode->right != NULL) searchNodeQueue.push(searchNode->right);
			searchNodeQueue.pop();
			ran--;
		}

		return searchNode;
	}
};

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
