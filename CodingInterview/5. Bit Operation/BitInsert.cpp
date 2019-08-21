#include <iostream>

int main() {
	int N, M;
	int i, j;

	printf("input N : ");
	scanf_s("%d", &N);
	printf("input M : ");
	scanf_s("%d", &M);

	printf("input i : ");
	scanf_s("%d", &i);
	printf("input j : ");
	scanf_s("%d", &j);

	int mask = ~0;

	for (int k = i-1; k < j; k++) {
		mask ^= 1 << k;
	}

	N &= mask;

	N += M << (i-1);

	printf("%d\n", N);

}