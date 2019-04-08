#include <iostream>
#include "SetOfStack.h"

int main() {
	SetOfStack<int> stack(2);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.pop());
}