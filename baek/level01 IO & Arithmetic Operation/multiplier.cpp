// https://www.acmicpc.net/problem/2588
#include <iostream>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	int c, d, e, f;
	f = a * b;
	c = a * (b % 10);
	b /= 10;
	d = a * (b % 10);
	b /= 10;
	e = a * b;

	printf("%d\n%d\n%d\n%d", c, d, e, f);
}