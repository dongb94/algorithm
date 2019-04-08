#include <iostream>
#include "LinkedList.h"

bool IsPalindrome(linked_list<char> list) {
	int length = 0;
	char *buffer;
	node<char> *pt = list.first();

	while (pt != NULL) {
		length++;
		pt = pt->next;
	}

	buffer = new char[(length-1)/2];
	pt = list.first();

	for (int i = 0; i < (length - 1) / 2; i++) {
		buffer[i] = pt->data;
		pt = pt->next;
	}

	printf("%d\n", length);
	if (length % 2 == 1) pt = pt->next;

	for (int i = (length - 3) / 2; i >= 0; i--) {
		if (buffer[i] != pt->data) return false;
		pt = pt->next;
	}

	return true;
}

int main() {
	linked_list<char> list;
	list.add_node('a');
	list.add_node('b');
	list.add_node('c');
	list.add_node('e');
	list.add_node('c');
	list.add_node('b');
	list.add_node('a');

	printf("%d\n", IsPalindrome(list));
}