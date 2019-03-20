#include <iostream>
#include "LinkedList.h"

void divisionBasedOnX(linked_list& list, int x) {
	node *pre = list.first();
	node *crr = list.first()->next;

	while (crr != NULL) {
		if (crr->data < x) {
			pre->next = crr->next;
			list.addFirst(crr);
			crr = pre->next;
		}
		else {
			pre = crr;
			crr = crr->next;
		}
	}
}

int main() {
	linked_list list;
	list.add_node(3);
	list.add_node(2);
	list.add_node(1);
	list.add_node(5);
	list.add_node(4);
	list.add_node(4);
	list.add_node(1);
	list.add_node(5);
	list.add_node(6);
	list.add_node(8);
	list.add_node(1);
	list.add_node(2);
	list.add_node(7);

	list.printLinkedList();
	divisionBasedOnX(list, 5);
	list.printLinkedList();
}