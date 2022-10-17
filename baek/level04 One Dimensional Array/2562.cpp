// https://www.acmicpc.net/problem/2562
// 최댓값

#include <iostream>

int main(void)
{

	int max = 0;
	int count;

	int input;
	for(int i = 0; i<9; i++){
		scanf("%d",&input);
		if(input > max) {
			max = input;
			count = i+1;
		}
	}

	printf("%d\n%d", max, count);

	return 0;
}