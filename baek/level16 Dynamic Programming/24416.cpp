// https://www.acmicpc.net/problem/24416
//알고리즘 수업 - 피보나치 수 1

#include <iostream>

int fib(int n, int* c) {
	
	if(n==1||n==2)
	{
		(*c)++;
		return 1;
	}
	else
		return fib(n-1, c) + fib(n-2, c);
}

int main(void)
{
	int N;
	scanf("%d", &N);

	int rfc = 0, dpc = 0;
	// recursion function
	fib(N, &rfc);

	// dynamic programming
	int f[41];
	f[1]=1;
	f[2]=1;
	for(int i=3; i<=N; i++)
	{
		dpc++;
		f[i]=f[i-1]+f[i-2];
	}

	printf("%d %d", rfc, dpc);

	return 0;
}