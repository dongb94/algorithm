#include <iostream>
#include <unordered_set>
#include "LinkedList.h"

template <class T>
node<T>* FindLoop(linked_list<T> list) {

	node<T> *itr = list.first();

	std::unordered_set<node<T>*> set;
	while (1) {
		if (set.find(itr) != set.end()) return itr;

		set.insert(itr);
		itr = itr->next;

		if (itr == NULL) return NULL;
	}
}

int main() {
	linked_list<int> list;
	list.add_node(1);
	node<int> *looped = list.add_node(2);
	list.add_node(3);
	list.add_node(4);
	list.add_node(1);
	list.add_node(2);
	node<int> *looping = list.add_node(3);
	looping->next = looped;

	node<int> *loopNode =  FindLoop(list);
	if (loopNode == NULL) printf("No Loop\n");
	else printf("%d\n", loopNode->data);
}