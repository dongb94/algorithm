#include <iostream>
#include "Node.h"

TreeNode<int>* MinimumTree(int* sortedArray, int start, int end) {

	if (start > end) return NULL;

	int center = (start + end + 1) / 2;

	printf("%d Start : %d, End : %d\n", sortedArray[center], start, end);
	TreeNode<int>* node = new TreeNode<int>(sortedArray[center]);
	node->left = MinimumTree(sortedArray, start, center - 1);
	node->right = MinimumTree(sortedArray, center + 1, end);

	return node;
}

TreeNode<int>* MinimumTree(int* sortedArray, int length) {
	
	return MinimumTree(sortedArray, 0, length - 1);
}

void printTree(TreeNode<int>* tree) {
	printf("%d : ", tree->data);
	if(tree->left!=NULL)
		printf("L %d ", tree->left->data);
	if (tree->right != NULL)
		printf("R %d", tree->right->data);
	printf("\n");
	if (tree->left != NULL)
		printTree(tree->left);
	if (tree->right != NULL)
		printTree(tree->right);
}

int main() {

	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	printTree(MinimumTree(array, 10));
	printf("\n");
}