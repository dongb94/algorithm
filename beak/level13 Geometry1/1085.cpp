// https://www.acmicpc.net/problem/1085
// 직사각형에서 탈출

#define MIN(x,y) x>y?y:x
#include <iostream>

int main(void)
{
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	int minDir = MIN(x,y);
	minDir = MIN(w-x, minDir);
	minDir = MIN(h-y, minDir);

	printf("%d", minDir);

	return 0;
}