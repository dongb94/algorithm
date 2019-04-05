#include <iostream>
#include "Stack.h"

class MyQueue {
private:
	Stack<int> in;
	Stack<int> out;
	bool inputFlag;
public:
	MyQueue() {
		inputFlag = true;
	}

	void push(int n) {
		if (!inputFlag) {
			while (out.Size > 0) {
				in.push(out.pop);
			}
		}
		inputFlag = true;
		in.push(n);
	}

	int pop() {
		if (inputFlag) {
			while (in.Size > 0) {
				out.push(in.pop);
			}
		}
		inputFlag = false;
		return out.pop();
	}
};
