#include <iostream>
#include "LinkedList.h"

void DeleteInsideNode(node* node) {
	node->data = node->next->data;
	node->next = node->next->next;
}

int main() {
	linked_list list;
	list.add_node(1);
	list.add_node(2);
	list.add_node(1);
	node *deleteNode = list.add_node(5);
	list.add_node(4);
	list.add_node(4);
	list.add_node(1);
	list.add_node(5);

	list.printLinkedList();
	DeleteInsideNode(deleteNode);
	list.printLinkedList();
}