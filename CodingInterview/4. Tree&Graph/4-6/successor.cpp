#include <iostream>
#include "Node.h"

TreeNode<int>* findNextode(TreeNode<int>* pre) {
	
	if (pre->left != NULL) return pre->left;
	if (pre->right != NULL) return pre->right;

	while (pre->parent != NULL && pre == pre->parent->right) pre = pre->parent;
	if (pre->parent == NULL) return NULL;
	pre = pre->parent;
	while (pre->parent != NULL && pre->right == NULL) pre = pre->parent;
	if (pre->right == NULL) return NULL;
	else return pre->right;
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

	a.addLeft(&b);
	a.addRight(&c);
	b.addLeft(&d);
	b.addRight(&e);
	c.addLeft(&f);
	c.addRight(&g);
	d.addLeft(&h);
	d.addRight(&i);
	e.addLeft(&j);
	e.addRight(&k);
	f.addLeft(&l);
	l.addRight(&n);

	TreeNode<int>* start = &a;
	while (start != NULL) {
		printf("%d - ", start->data);
		start = findNextode(start);
	}
}