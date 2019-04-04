#include <iostream>

template<typename T>
class Stack {
private:
	T *start;
	int nOfE;
	int size;
public:

	Stack() {
		start = new T[10];
		nOfE = 0;
		size = 10;
	}

	Stack(int N) {
		start = new T[N];
		nOfE = 0;
		size = N;
	}

	void push(T n) {
		if (nOfE == size) {
			T *sizeIncreaseStack = new T[size * 2];
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

	T pop() {
		if (nOfE == 0) return NULL;
		nOfE--;

		return start[nOfE];
	}

	T top() {
		if (nOfE == 0) return NULL;
		return start[nOfE - 1];
	}

	int Size() {
		return nOfE;
	}
};