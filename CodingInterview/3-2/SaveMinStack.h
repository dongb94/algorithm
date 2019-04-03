#include <iostream>

//template<typename T>
class stack {
private:
	int *start;
	int nOfE;
	int size;

	int *minStack;
	int minNofE;
	int minStackSize;
public:

	stack() {
		start = new int[10];
		nOfE = 0;
		size = 10;

		minStack = new int[10];
		minNofE = 0;
		minStackSize = 10;
	}

	stack(int N) {
		start = new int[N];
		nOfE = 0;
		size = N;

		minStack = new int[N];
		minNofE = 0;
		minStackSize = N;
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

		if (minNofE == 0) {
			minStack[0] = n;
			minNofE++;
		}
		else if(minStack[minNofE-1] >= n){
			
			minStack[minNofE] = n;
			minNofE++;

		}

		nOfE++;
	}

	int pop() {
		if (nOfE == 0) return NULL;
		nOfE--;

		if (start[nOfE] == minStack[minNofE-1]) {
			minNofE--;
		}

		return start[nOfE];
	}

	int Size() {
		return nOfE;
	}

	int Min() {
		if (minNofE == 0) return NULL;
		return minStack[minNofE - 1];
	}
};