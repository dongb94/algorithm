// https://www.acmicpc.net/problem/2751
// 수 정렬하기 2

#include <iostream>
// #include <algorithm>
#include <set>

int main(void)
{
	int N;
	std::set<int> sortSet;

	scanf("%d", &N);

	for(int i=0; i<N; i++)
	{
		int input;
		scanf("%d", &input);
		sortSet.insert(input);
	}

	for(auto i=sortSet.begin(); i!=sortSet.end(); i++)
	{
		printf("%d\n", *i);
	}
}