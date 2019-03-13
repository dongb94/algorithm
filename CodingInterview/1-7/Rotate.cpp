#include <iostream>

int** RotateMatrix(int* matrix[], int n) {
	int temp;
	for (int i = 0; i <= (n - 1) / 2; i++) {
		for (int j = 0; j <= (n - 1) / 2; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[n-1-j][i];
			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
			matrix[j][n-1-i] = temp;
		}
	}
	return matrix;
}

void printMatrix(int * matrix[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int* input[10];
	for (int i = 0; i < 10; i++) {
		input[i] = new int[10]{1,2,3,4,5,6,7,8,9,0};
	}

	printMatrix(input, 10);
	RotateMatrix(input, 10);
	printMatrix(input, 10);

}