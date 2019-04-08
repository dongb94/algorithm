#include <iostream>
#include "LinkedList.h"

linked_list SumTwoList(linked_list list1, linked_list list2) {
	node *num1, *num2;
	num1 = list1.first();
	num2 = list2.first();

	linked_list sumList;
	int sum;
	int carry = 0;

	while(num1 != NULL && num2 != NULL) {
		sum = num1->data + num2->data + carry;

		carry = 0;
		if (sum >= 10) {
			sum -= 10;
			carry++;
		}

		sumList.add_node(sum);

		num1 = num1->next;
		num2 = num2->next;
	}

	while (num1 != NULL) {
		sum = num1->data + carry;

		carry = 0;

		if (sum >= 10) {
			sum -= 10;
			carry++;
		}

		sumList.add_node(sum);

		num1 = num1->next;
	}

	while (num2 != NULL) {
		sum = num2->data + carry;

		carry = 0;

		if (sum >= 10) {
			sum -= 10;
			carry++;
		}

		sumList.add_node(sum);

		num2 = num2->next;
	}

	if (carry != 0) sumList.add_node(carry);

	return sumList;
}

int main() {
	linked_list list1;
	list1.add_node(3);
	list1.add_node(2);
	list1.add_node(1);
	list1.add_node(5);
	list1.add_node(4);
	list1.add_node(4);
	list1.add_node(1);
	list1.add_node(5);
	list1.add_node(6);
	list1.add_node(8);
	list1.add_node(1);
	list1.add_node(2);
	list1.add_node(9);

	list1.printLinkedList();

	linked_list list2;
	list2.add_node(3);
	list2.add_node(2);
	list2.add_node(1);
	list2.add_node(5);
	list2.add_node(4);
	list2.add_node(4);
	list2.add_node(1);
	list2.add_node(5);
	list2.add_node(6);
	list2.add_node(8);
	list2.add_node(1);
	list2.add_node(9);

	list2.printLinkedList();

	SumTwoList(list1, list2).printLinkedList();
}