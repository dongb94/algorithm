#include <iostream>

//template<typename T>
class Stack {
private:
	int *start;
	int nOfE;
	int size;
public:

	Stack() {
		start = new int[10];
		nOfE = 0;
		size = 10;
	}

	Stack(int N) {
		start = new int[N];
		nOfE = 0;
		size = N;
	}

	void push(int n) {
		if (nOfE == size) {
			int *sizeIncreaseStack = new int[size * 2];
			sizeIncreaseStack = start;
			for (int i = 0; i < size; i++) {
				sizeIncreaseStack[i] = start[i];
			}
			start = sizeIncreaseStack;
			size *= 2;
		}
		start[nOfE] = n;

		nOfE++;
	}

	int pop() {
		if (nOfE == 0) return NULL;
		nOfE--;

		return start[nOfE];
	}

	int Size() {
		return nOfE;
	}
};