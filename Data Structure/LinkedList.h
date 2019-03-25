// LinkedList.h
#include <iostream>

template <class T>
struct node {
	T data;
	node *next;
};

template <class T>
class linked_list{
private:
	node<T> *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}

	node<T>* add_node(T n) {
		node<T> *temp = new node<T>;
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

	void addFirst(T x) {
		node<T> *temp = new node<T>;
		temp->data = x;
		temp->next = head;
		head = temp;
		if (tail == NULL) tail = temp;

	}

	void addFirst(node<T> *node) {
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

	node<T>* first() {
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

