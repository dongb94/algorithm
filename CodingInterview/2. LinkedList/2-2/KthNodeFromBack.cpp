#include "LinkedList.h"

int SearchKthNode(linked_list list, int k) {
	node *front, *end;
	front = end = list.first();

	for (int i = 0; i < k; i++) {
		end = end->next;
		if (end == NULL) return front->data;
	}

	while (end != NULL) {
		end = end->next;
		front = front->next;
	}

	return front->data;
}

int main() {
	linked_list list;
	list.add_node(1);
	list.add_node(2);
	list.add_node(1);
	list.add_node(5);
	list.add_node(4);
	list.add_node(4);
	list.add_node(1);
	list.add_node(5);

	int K;
	scanf_s("%d", &K);
	printf("%d\n", SearchKthNode(list , K));
}