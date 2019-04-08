#include <iostream>
//#include <hash_set>

struct node {
	int data;
	node *next;
};

class linked_list {
private:
	node *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}

	void add_node(int n) {
		node *temp = new node;
		temp->data = n;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}

	node* first() {
		return head;
	}
};

void printLinkedList(linked_list list) {
	if (list.first() == NULL) return;

	node* currentNode = list.first();
	while (currentNode->next != NULL) {
		printf("%d - ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("%d", currentNode->data);

	printf("\n");
}

//void RemoveDuplicate(linked_list list) {
//	if (list.first() == NULL) return;
//
//	std::hash_set<int> set;
//	node* currentNode = list.first();
//	node* previous;
//	while (true) {
//		if (*set.find(currentNode->data) == NULL) {
//			set.insert(currentNode->data);
//			previous = currentNode;
//		}
//		else {
//			previous->next = currentNode->next;
//		}
//		if (currentNode->next == NULL) break;
//		currentNode = currentNode->next;
//	}
//}

void RemoveDuplicate(linked_list list) {
	if (list.first() == NULL) return;

	node *currentNode = list.first();
	node *serchNode, *previousNode;

	while (true) {
		serchNode = currentNode->next;
		previousNode = currentNode;

		while (true) {
			if (serchNode->data == currentNode->data) {
				previousNode->next = serchNode->next;
			}
			else {
				previousNode = serchNode;
			}
			if (serchNode->next == NULL) break;
			serchNode = serchNode->next;
		}
		if (currentNode->next == NULL) break;
		currentNode = currentNode->next;
	}
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

	printLinkedList(list);
	RemoveDuplicate(list);
	printLinkedList(list);
}