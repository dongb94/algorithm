#include <iostream>

int main() {
	int T;
	scanf_s("%d", &T); ///

	for (int i = 0; i < T; i++) {
		int N, r, c, Rr, Rc;
		scanf_s("%d %d %d %d %d\n", &N, &r, &c, &Rr, &Rc); ///

		int** board = new int*[r];
		for (int j = 0; j < r; j++) {
			board[j] = new int[c];
		}
		Rr--;
		Rc--;
		board[Rr][Rc] = 1;

		for (int j = 0; j < N; j++) {
			char I;
			scanf_s("%c", &I); ///
			switch (I) {
			case 'S' :
				while (board[Rr][Rc] == 1) {
					Rr++;
				}
				board[Rr][Rc] = 1;
				break;
			case 'W' :
				while (board[Rr][Rc] == 1) {
					Rc--;
				}
				board[Rr][Rc] = 1;
				break;
			case 'E' :
				while (board[Rr][Rc] == 1) {
					Rc++;
				}
				board[Rr][Rc] = 1;
				break;
			case 'N' :
				while (board[Rr][Rc] == 1) {
					Rr--;
				}
				board[Rr][Rc] = 1;
				break;
			}
		}

		printf("Case #%d: %d %d\n", T + 1, Rr+1, Rc+1);
	}
}