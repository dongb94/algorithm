// https://www.acmicpc.net/problem/3003
// 킹, 퀸, 룩, 비숍, 나이트, 폰
#include <iostream>

int main(void)
{
	int number[6];
	int need[] = {1,1,2,2,2,8};

	for(int i=0; i<6; i++)
	{
		scanf("%d", &number[i]);
	}
	
	for(int i=0; i<6; i++)
	{
		printf("%d ", need[i]-number[i]);
	}

	return 0;
}