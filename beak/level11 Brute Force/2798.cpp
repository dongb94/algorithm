// https://www.acmicpc.net/problem/2798
// 블랙잭

#include <iostream>

int main(void)
{
	int N,M; // 3 <= N <= 100, 10 <= M <= 300,000
	scanf("%d %d", &N, &M);

	int *cardset = new int[N];
	for(int i=0; i<N; i++)
	{
		scanf("%d", &(cardset[i]));
	}

	int a,b,c;
	int max=0;
	for(int i=0; i<N-2; i++)
	{
		a=cardset[i];
		if(a > M) continue;
		for(int j=i+1; j<N-1; j++)
		{
			b=cardset[j];
			if(a+b > M) continue;

			for(int k=j+1; k<N; k++)
			{
				c=cardset[k];
				if(a+b+c > M) continue;

				if(a+b+c > max) max = a+b+c;
				if(max == M)
				{
					printf("%d", max);
					return 0;
				}
			}
		}
	}

	printf("%d", max);
    return 0;
}