#include <iostream>
#include <list>
#include <queue>
#include "Node.h"

using namespace std;

list<TreeNode<int>*> makeList(queue<TreeNode<int>*>& searchQueue);

list<list<TreeNode<int>*>> DepthList(TreeNode<int>* tree) {
	list<list<TreeNode<int>*>> depthList;
	queue<TreeNode<int>*> searchQueue;

	list<TreeNode<int>*> topList;
	topList.push_back(tree);
	depthList.push_back(topList);
	searchQueue.push(tree);

	while (searchQueue.size()!=0) {
		depthList.push_back(makeList(searchQueue));
	}

	return depthList;
}

list<TreeNode<int>*> makeList(queue<TreeNode<int>*>& searchQueue) {
	queue<TreeNode<int>*> tempQueue;
	list<TreeNode<int>*> levelList;
	while (searchQueue.size() != 0) {
		TreeNode<int>* front = searchQueue.front();
		if (front->left != NULL) {
			levelList.push_back(front->left);
			tempQueue.push(front->left);
		}
		if (front->right != NULL) {
			levelList.push_back(front->right);
			tempQueue.push(front->right);
		}
		searchQueue.pop();
	}
	searchQueue = tempQueue;
	return levelList;
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
	node_6.left = &node_10;
	node_10.right = &node_11;

	list<list<TreeNode<int>*>> result = DepthList(&node_1);
	for (list<TreeNode<int>*> itr : result) {
		for (TreeNode<int>* itr2 : itr) {
			printf("%d", itr2->data);
		}
		printf("\n");
	}
}