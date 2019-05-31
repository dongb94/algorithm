#include <iostream>
#include "Node.h"

bool isBST(TreeNode<int>* top, int low, int high) {
	if (top == NULL) return true;
	if (low != NULL && top->data <= low) return false;
	if (high != NULL && top->data >= high) return false;
	bool left = isBST(top->left, low, top->data);
	bool right = isBST(top->right, top->data, high);
	return left && right;
}

int main() {
	TreeNode<int> a(10);
	TreeNode<int> b(5);
	TreeNode<int> c(15);
	TreeNode<int> d(3);
	TreeNode<int> e(7);
	TreeNode<int> f(13);
	TreeNode<int> g(17);
	TreeNode<int> h(1);
	TreeNode<int> i(4);
	TreeNode<int> j(6);
	TreeNode<int> k(8);
	TreeNode<int> l(11);
	TreeNode<int> n(12);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;
	d.left = &h;
	d.right = &i;
	e.left = &j;
	e.right = &k;
	f.left = &l;
	l.right = &n;

	printf("%d\n", isBST(&a, NULL, NULL));

}