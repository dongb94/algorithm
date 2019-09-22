#include <iostream>

using namespace std;

int main(void) {
	int num;
	int numOfZero=0;
	int max=0;
	bool isLeaf = true;
	scanf("%d", &num);

	int s;
	for (int i = 0; i < num; i++) {
		scanf("%d", &s);
		if (s == 0) {
			numOfZero++;
			if (i == num - 1) {
				if (numOfZero > max) max = numOfZero;
			}
		}
		else {
			int temp;
			if (isLeaf) {
				temp = numOfZero;
				isLeaf = false;
			}
			else temp = (numOfZero + 1) / 2;
			numOfZero = 0;
			if (temp > max) max = temp;
		}
	}

	printf("%d", max);

	return 0;
}