// https://www.acmicpc.net/problem/1330
#include <iostream>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	if (a > b) printf(">");
	else if (a < b)printf("<");
	else printf("==");
}