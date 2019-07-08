#include <iostream>
#include "Node.h"
#include <queue>

void AddDataInBST(TreeNode<int>* bst, int data, bool descending = false) {
	
	if (bst == NULL || bst->data == data) return;

	if (bst->data < data) {
		if (descending)
			if (bst->left == NULL)
				bst->addLeft(data);
			else
				AddDataInBST(bst->left, data, descending);
		else
			if (bst->right == NULL)
				bst->addRight(data);
			else
				AddDataInBST(bst->left, data, descending);
	}
	else {
		if (descending)
			if (bst->right == NULL)
				bst->addRight(data);
			else
				AddDataInBST(bst->left, data, descending);
		else
			if (bst->left == NULL)
				bst->addLeft(data);
			else
				AddDataInBST(bst->left, data, descending);
	}

}

void printTree(TreeNode<int>* root) {
	std::queue<TreeNode<int>*> bfsQueue;
	TreeNode<int>* searchNode;
	bfsQueue.push(root);

	while (bfsQueue.size > 0) {
		searchNode = bfsQueue.front();

		printf("%d", searchNode->data);

		if (searchNode->left != NULL) bfsQueue.push(searchNode->left);
		if (searchNode->right != NULL) bfsQueue.push(searchNode->right);

		bfsQueue.pop();
	}
}

void BSTSequence(TreeNode<int>* root, std::queue<int> posibleInput, std::queue<TreeNode<int>*> nextNode) {
	posibleInput.push(root->data);
	if(root->left !=NULL)
		nextNode.push(root->left);
	if (root->right != NULL)
		nextNode.push(root->right);

	if (nextNode.size() == 0) {
		printf("[");
		while (posibleInput.size() != 0) {
			printf("%d, ", posibleInput.front());
			posibleInput.pop();
		}
		printf("]\n");
		return;
	}

	while(nextNode.size() != 0)
	{
		BSTSequence(nextNode.front() , posibleInput, nextNode);
		nextNode.pop();
	}
}

int main() {

}
