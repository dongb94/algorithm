#include <iostream>

int main() {
	int T;
	scanf("%d",&T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);

		int** M = new int*[N];
		int sum = 0;
		int r = 0;
		int c = 0;

		for (int j = 0; j < N; j++) {
			M[j] = new int[N];
			int* row = new int[N+1];
			bool rowF = false;
			for (int k = 0; k < N; k++) {
				scanf("%d", &M[j][k]);
				
				if (rowF) continue;

				if (row[M[j][k]] == 1) {
					rowF = true;
					r++;
					continue;
				}

				row[M[j][k]] = 1;
			}
			sum += M[j][j];
		}

		for (int j = 0; j < N; j++) {
			int* col = new int[N+1];
			for (int k = 0; k < N; k++) {
				if (col[M[k][j]] == 1) {
					c++;
					break;
				}
				col[M[k][j]] = 1;
			}
		}

		printf("Case #%d: %d %d %d\n", i+1, sum, r, c);
	}
}