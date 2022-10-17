// https://www.acmicpc.net/problem/10815
// 숫자 카드

#include <iostream>
#include <set>

int main(void)
{
	int N, M;
	int num;

	scanf("%d", &N);
	std::set<int> card;

	for(int i=0; i<N; i++)
	{
		scanf("%d", &num);
		card.insert(num);
	}

	int flag;
	scanf("%d", &M);
	for(int i=0; i<M; i++)
	{
		flag = 0;
		scanf("%d", &num);
		if(card.find(num)!=card.end())
		{
			flag=1;
		}

		if(flag) printf("1 ");
		else printf("0 ");
	}

	return 0;
}