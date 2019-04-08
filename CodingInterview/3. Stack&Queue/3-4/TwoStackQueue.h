#include <iostream>
#include "Stack.h"

class MyQueue {
private:
	Stack<int> in;
	Stack<int> out;
public:
	MyQueue() {
	}

	void push(int n) {
		in.push(n);
	}

	int pop() {
		if (out.Size() == 0) {
			while (in.Size() > 0) {
				out.push(in.pop());
			}
		}
		if (out.Size() == 0) return NULL;
		return out.pop();
	}
};
