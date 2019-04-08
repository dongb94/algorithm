#include <iostream>

int** OMatrix(int** input, int m, int n) {
	bool* horizen0;
	bool* vertical0;

	horizen0 = new bool[m];
	vertical0 = new bool[n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (input[i][j] == 0) {
				horizen0[i] = 1;
				vertical0[j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		if (horizen0[i] == 1) {
			for (int j = 0; j < n; j++) {
				input[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (vertical0[i] == 1) {
			for (int j = 0; j < m; j++) {
				input[j][i] = 0;
			}
		}
	}

	return input;
}

int main() {
	int* input[4];
	input[0] = new int[5] {1, 2, 3, 4, 5};
	input[1] = new int[5] {1, 0, 3, 0, 5};
	input[2] = new int[5] {1, 2, 3, 4, 5};
	input[3] = new int[5] {1, 0, 3, 4, 5};

	OMatrix(input, 4, 5);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d", input[i][j]);
		}
		printf("\n");
	}
}