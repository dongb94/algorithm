// https://www.acmicpc.net/problem/10816
// 숫자 카드 2

#include <iostream>
#include <map>

int main(void)
{
	int N, M;
	std::map<int, int> cardMap;

	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		int num;
		scanf("%d", &num);

		if(cardMap.find(num) == cardMap.end())
		{
			cardMap[num] = 1;
		}
		else
		{
			cardMap[num]++;
		}
	}
	
	scanf("%d", &M);
	for(int i=0; i<M; i++)
	{
		int num;
		scanf("%d", &num);

		printf("%d ", cardMap[num]);
	}

	return 0;
}