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
	int T, N, P;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &P);
		int leastCoach = 9999999;
		int *coach = new int[N];
		int *skill = new int[N];
		for (int j = 0; j < N; j++) {
			scanf("%d", &skill[j]);
		}

		arraySort(skill, 0, N - 1);

		for (int j = 1; j < N; j++) {
			coach[j] = skill[j] - skill[j - 1];
			if (j < P - 1) continue;
			int sum = 0;
			for (int k = 0; k < P - 1; k++) {
				sum += coach[j - k] * (P - k - 1);
			}
			if (sum < leastCoach) leastCoach = sum;
		}

		printf("%d\n", leastCoach);
	}
}