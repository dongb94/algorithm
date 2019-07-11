#include <iostream>
#include "Node.h"

bool checkIsSameTree(TreeNode<int>* t1, TreeNode<int>* t2) {
	if (t1->data != t2->data) return false;
	if (t1->left != NULL) {
		if (t2->left == NULL) return false;
		if(!checkIsSameTree(t1->left, t2->left))
			return false;
	}
	else if (t2->left != NULL) return false;
	if (t1->right != NULL) {
		if (t2->right == NULL) return false;
		if (!checkIsSameTree(t1->right, t2->right))
			return false;
	}
	else if (t2->right != NULL) return false;

	return true;
}

bool findSubtree(TreeNode<int>* t1, TreeNode<int>* t2) { // t1 > t2
	if (t1->data == t2->data) 
		if(checkIsSameTree(t1, t2)) return true;
	if (t1->left != NULL) {
		if (findSubtree(t1->left, t2))
			return true;
	}
	if (t1->right != NULL) {
		if (findSubtree(t1->right, t2))
			return true;
	}
	return false;
}

int main() {
	TreeNode<int>* T1 = new TreeNode<int>(1);
	TreeNode<int>* T2 = new TreeNode<int>(2);

	T1->addLeft(2);
	T1->addRight(3);
	T1->left->addLeft(4);
	T1->left->addRight(5);
	T1->right->addLeft(6);

	T2->addLeft(4);
	T2->addRight(5);

	printf("%d\n", findSubtree(T1, T2));
}