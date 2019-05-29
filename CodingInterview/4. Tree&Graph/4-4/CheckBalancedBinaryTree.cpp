#include <iostream>
#include "Node.h"

int checkBalanced(TreeNode<int>* top) {
	int left = top->left == NULL ? 0 : checkBalanced(top->left) + 1;
	int right = top->right == NULL ? 0 : checkBalanced(top->right) + 1;

	if (abs(left - right) > 1) return -1;
	else return left < right ? right : left;
}

int main() {
	TreeNode<int> node_1(1);
	TreeNode<int> node_2(2);
	TreeNode<int> node_3(2);
	TreeNode<int> node_4(3);
	TreeNode<int> node_5(3);
	TreeNode<int> node_6(3);
	TreeNode<int> node_7(4);
	TreeNode<int> node_8(4);
	TreeNode<int> node_9(4);
	TreeNode<int> node_10(4);
	TreeNode<int> node_11(5);

	node_1.left = &node_2;
	node_1.right = &node_3;
	node_2.left = &node_4;
	node_2.right = &node_5;
	node_3.right = &node_6;
	node_4.left = &node_7;
	node_4.right = &node_8;
	node_5.left = &node_9;
	node_3.left = &node_10;
	node_10.right = &node_11;

	if(checkBalanced(&node_1)==-1)
		printf("Is not balenced");
	else
		printf("Is balenced");

}