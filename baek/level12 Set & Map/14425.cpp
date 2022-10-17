// https://www.acmicpc.net/problem/14425
// 문자열 집합

#include <iostream>
#include <string>
#include <set>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	std::set<std::string> stringSet;

	for(int i=0; i<N; i++)
	{
		char input[500];
		scanf("%s", input);

		stringSet.insert(input);
	} 

	int includeCnt = 0;
	for(int i=0; i<M; i++)
	{
		char input[500];
		scanf("%s", input);

		if(stringSet.find(input)!=stringSet.end()) includeCnt++;
	}

	printf("%d", includeCnt);

	return 0;
}