#include <iostream>
#include "Node.h"

TreeNode<int>* findCommonAncester(TreeNode<int> *n1, TreeNode<int> *n2) {
	int n1_depth = 0, n2_depth = 0;
	TreeNode<int> *p, *q;
	p = n1;
	q = n2;

	while (p->parent != NULL) {
		n1_depth++;
		p = p->parent;
	}
	while (q->parent != NULL) {
		n2_depth++;
		q = q->parent;
	}

	p = n1;
	q = n2;

	if (n1_depth < n2_depth) {
		int temp = n1_depth;
		n1_depth = n2_depth;
		n2_depth = temp;

		p = n2;
		q = n1;
	}
	while (n1_depth != n2_depth) {
		n1_depth--;
		p = p->parent;
	}

	while (p != q) {
		if (p->parent == NULL) return NULL;
		p = p->parent;
		q = q->parent;
	}

	return p;
}

int main() {
	TreeNode<int> *a = new TreeNode<int>(1);
	a->addLeft(2);
	a->addRight(3);
	a->right->addLeft(4);
	a->right->addRight(5);
	a->right->right->addRight(8);
	TreeNode<int> *b = a->right->left;
	b->addLeft(6);
	b->addRight(7);
	b->left->addLeft(9);

	TreeNode<int> *p = b->left->left;
	TreeNode<int> *q = a->right->right->right;

	printf("%d\n", findCommonAncester(p, q)->data);
}