#include <iostream>
void arraySort(int *arr, int start, int end) {
	if (end - start < 1) return;
	if (end - start == 1) {
		if (arr[start] <= arr[end]) return;
		else {
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			return;
		}
	}

	int pivot = arr[start];
	int *sp = &arr[start];
	int *ep = &arr[end];
	int pp = start;

	while (start < end) {
		while (*sp < pivot) {
			sp++;
			pp++;
		}
		while (*ep >= pivot) ep--;

		if (sp >= ep) break;

		int temp = *sp;
		*sp = *ep;
		*ep = temp;
	}

	for (int i = 0; i < 21; i++) {
		if (i == pp) printf("*");
		printf("%d-", arr[i]);
	}
	printf("\n");

	if(pp==start) arraySort(arr, pp + 1, end);
	else {
		arraySort(arr, start, pp - 1);
		arraySort(arr, pp, end);
	}
}

int main() {
	int asdf[21] = {3,2,5,3,6,7,1,2,3,4,5,244,61,22,71128,4,2,2,32,1,6};

	for (int i = 0; i < 21; i++) {
		printf("%d-", asdf[i]);
	}
	printf("\n");

	arraySort(asdf,0,20);

	for (int i = 0; i < 21; i++) {
		printf("%d-", asdf[i]);
	}
	printf("\n");
}