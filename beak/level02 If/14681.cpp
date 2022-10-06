// https://www.acmicpc.net/problem/14681
// 사분면 고르기

#include <iostream>

int main(void)
{
	int x,y; // (−1000 ≤ x ≤ 1000; y ≠ 0) (−1000 ≤ y ≤ 1000; y ≠ 0)
	scanf("%d %d", &x, &y);

	if(y < 0){
		if(x < 0){
			printf("3");
		}
		else{
			printf("4");
		}
	}
	else{
		if(x < 0){
			printf("2");
		}
		else{
			printf("1");
		}
	}

	return 0;
}