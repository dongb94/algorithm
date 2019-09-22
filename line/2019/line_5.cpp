
#include <iostream>

using namespace std;

int combination(int n, int r) {
	if (n == r || r == 0)
		return 1;
	else 
		return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(void) {
	int x, y;
	int cx, cy;
	scanf("%d %d", &x, &y);
	scanf("%d %d", &cx, &cy);

	if (cx < 0 || cx > x
		|| cy < 0 || cy > y) {
		printf("fail");
		return 0;
	}

	printf("%d\n", cx + cy);
	printf("%d", combination(cx + cy, cx));

	return 0;
}


