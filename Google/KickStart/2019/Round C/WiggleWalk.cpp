#include <iostream>

int main() {
	int T;
	scanf("%d", &T);
	int N, r, c, Rr, Rc;
	int i,j,k;
	char I;
	bool* board[30000];
	for (j = 0; j < 30000; j++) {
		board[j] = new bool[30000];
	}
	for (i = 0; i < T; i++) {
		scanf("%d %d %d %d %d\n", &N, &r, &c, &Rr, &Rc);
		for (j = 0; j < r; j++) {
			for (k = 0; k < c; k++) {
				board[j][k] = false;
			}
		}
		Rr--;
		Rc--;
		board[Rr][Rc] = true;

		for (j = 0; j < N; j++) {
			scanf("%c", &I);
			switch (I) {
			case 'S':
				while (board[Rr][Rc]) {
					Rr++;
				}
				board[Rr][Rc] = true;
				break;
			case 'W':
				while (board[Rr][Rc]) {
					Rc--;
				}
				board[Rr][Rc] = true;
				break;
			case 'E':
				while (board[Rr][Rc]) {
					Rc++;
				}
				board[Rr][Rc] = true;
				break;
			case 'N':
				while (board[Rr][Rc]) {
					Rr--;
				}
				board[Rr][Rc] = true;
				break;
			}
		}

		printf("Case #%d: %d %d\n", i + 1, Rr + 1, Rc + 1);
	}
}