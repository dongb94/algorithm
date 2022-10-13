//https://www.acmicpc.net/problem/11047
//동전0

// 동전의 단위가 특수해서 그리디 알고리즘이 성립하는 문제. 만약 높은 동전의 가치가 낮은 동전으로 나누었을때 나누어 떨어지지 않으면 다른 방법을 사용해야 한다.

#include <iostream>

int main(void)
{
	int N,K;

	scanf("%d %d", &N, &K);

	int *coin = new int[N];
	for(int i=0; i<N; i++)
	{
		scanf("%d", &(coin[i]));
	}

	int coinNum = 0;
	while(K!=0)
	{
		for(int i=N-1; i>=0; i--)
		{
			if(coin[i] <= K)
			{
				coinNum++;
				K-=coin[i];
				break;
			}

			if(i==0) // 불가능
			{
				printf("-1");
				return -1;
			}
		}
	}

	printf("%d", coinNum);

	return 0;
}