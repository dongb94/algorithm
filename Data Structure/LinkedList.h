// LinkedList.h
#include <iostream>

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

	node* add_node(int n) {
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

		return temp;
	}

	void addFirst(int x) {
		node *temp = new node();
		temp->data = x;
		temp->next = head;
		head = temp;
		if (tail == NULL) tail = temp;

	}

	void addFirst(node *node) {
		node->next = head;
		head = node;
		if (tail == NULL) tail = node;

	}

	int removeFirst() {
		if(head == NULL) return NULL;

		int data = head->data;
		head = head->next;

		return data;
	}

	node* first() {
		return head;
	}

	void printLinkedList() {
		if (head == NULL) return;

		node* currentNode = head;
		while (currentNode->next != NULL) {
			printf("%d - ", currentNode->data);
			currentNode = currentNode->next;
		}
		printf("%d", currentNode->data);

		printf("\n");
	}
};

