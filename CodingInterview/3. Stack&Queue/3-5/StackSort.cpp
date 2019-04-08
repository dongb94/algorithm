#include "Stack.h"

void StackSort(Stack<int> stack) {
	Stack<int> buffer;

	while (!stack.isEmpty()) {
		int temp = stack.pop();
		int count = 0;

		while (!buffer.isEmpty() && buffer.peak() > temp) {
			stack.push(buffer.pop());
			count++;
		}

		buffer.push(temp);

		for (int i = 0; i < count; i++) {
			buffer.push(stack.pop());
		}
	}

	while (!buffer.isEmpty()) {
		stack.push(buffer.pop());
	}
}

int main() {
	Stack<int> stack;
	stack.push(2);
	stack.push(1);
	stack.push(4);
	stack.push(6);
	stack.push(12);
	stack.push(2);
	stack.push(66);
	stack.push(7);
	stack.push(8);
	stack.push(10);
	stack.push(4);

	StackSort(stack);

	while(!stack.isEmpty()) {
		printf("%d\n", stack.pop());
	}
}