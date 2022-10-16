// https://www.acmicpc.net/problem/10818
// 최소, 최대

#include <iostream>
#include <set>

int main(void)
{
	int N;
	scanf("%d", &N);

	int input;
	int min=1000000, max=-1000000;
	for(int i=0; i<N; i++)
	{
		scanf("%d", &input);
		if(input < min) min = input;
		if(input > max) max = input;
	}

	printf("%d %d", min, max);

	return 0;
}