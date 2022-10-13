// https://www.acmicpc.net/problem/1712
// 손익분기점

#include <iostream>

int main(void)
{
	int A, B, C;// A 고정비용, B 생산비용, C 가격
	scanf("%d %d %d", &A, &B, &C);

	if(C <= B) {
		printf("-1");
		return 0;
	}

	// a + bn < cn
	// a < (c-b)n
	// a/(c-b) < n

	int n = (A / (C-B)) + 1;

	printf("%d",n);

	return 0;
}