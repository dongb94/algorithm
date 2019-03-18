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