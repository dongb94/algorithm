// https://www.acmicpc.net/problem/1620
// 나는야 포켓몬 마스터 이다솜

#include <memory.h>
#include <iostream>
#include <string>
#include <map>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	std::map<int,std::string> book1;
	std::map<std::string,int> book2;

	for(int i=0; i<N; i++)
	{
		char input[20];
		scanf("%s", input);

		book1.insert({i+1, input});
		book2.insert({input, i+1});
	}

	for(int i=0; i<M; i++)
	{
		char input[20];
		memset(input, 0, sizeof(input));
		scanf("%s", input);

		if(input[0] >= '0' && input[0] <= '9')
		{
			int num = std::stoi(input);
			printf("%s\n", (book1[num]).c_str());
		}
		else
		{
			printf("%d\n", book2[input]);
		}
	}

	return 0;
}