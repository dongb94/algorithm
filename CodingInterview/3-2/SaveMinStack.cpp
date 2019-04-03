#include <iostream>
#include "Stack.h"

int main() {
	stack stack;

	stack.push(2);
	printf("%d\n", stack.Min());
	stack.push(4);
	printf("%d\n", stack.Min());
	stack.push(1);
	printf("%d\n", stack.Min());
	stack.push(3);
	printf("%d\n", stack.Min());
	stack.push(5);
	printf("%d\n", stack.Min());

	printf("%d\n", stack.pop());
	printf("%d\n", stack.Min());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.Min());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.Min());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.Min());
	printf("%d\n", stack.pop());
	printf("%d\n", stack.Min());
}