// https://www.acmicpc.net/problem/1764
// 듣보잡

#include <iostream>
#include <set>
#include <string>

int main(void)
{
	int N, M;
	scanf("%d %d",&N, &M);

	std::set<std::string> notLook;
	std::set<std::string> notLookNotSee;

	char name[20];
	for(int i=0; i<N; i++)
	{
		scanf("%s", name);
		notLook.insert(name);
	}

	for(int i=0; i<M; i++)
	{
		scanf("%s", name);
		if(notLook.find(name) != notLook.end())
		{
			notLookNotSee.insert(name);
		}
	}

	printf("%d\n", notLookNotSee.size());
	for(auto i=notLookNotSee.begin(); i!=notLookNotSee.end(); i++)
	{
		printf("%s\n", (*i).c_str());
	}

	return 0;
}