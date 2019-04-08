#include <iostream>
#include "Stack.h"

template <typename T>
class SetOfStack {
private :
	Stack<Stack<T>*> stackStack;
	int index;
	int stackSize;
public :
	SetOfStack() {
		stackSize = 8;
		index = stackSize;
	}

	SetOfStack(int size) {
		stackSize = size;
		index = stackSize;
	}

	void push(T n) {
		if (stackSize <= index) {
			stackStack.push(new Stack<T>(stackSize));
			index = 1;
		}
		else {
			index++;
		}
		(*stackStack.top()).push(n);
	}

	T pop() {
		if (stackStack.Size() == 0) return NULL;
		T value = (*stackStack.top()).pop();
		if (index <= 1) {
			stackStack.pop();
			index = stackSize;
		}
		else {
			index--;
		}
		return value;
	}
};