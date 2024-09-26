/// 2023.04.30 넥슨 코딩 테스트
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void N1()
{
	int N;
	scanf("%d", &N);

	char M[N+1];
	int Q;
	scanf("%s", M);
	scanf("%d", &Q);

	vector<int> sVector(N);
	vector<int> eVector;
	map<int, int> valueMap;
	{
		int value = 0;
		int i=0;
		int lastStarValue = 0;
		for(auto c : M)
		{
			if(c == '*') {
				valueMap.emplace(i, value);
				lastStarValue = value;
			}
			else {
				value += (c-'0');
			}
			i++;
			eVector.push_back(lastStarValue);
		}
	}
	{
		int i=0;
		int lastValue = 0;
		for(auto map : valueMap)
		{
			while(i <= map.first)
			{
				sVector[i] = (map.second);
				i++;
			}	
		}
		if(i!=0)
		{
			lastValue = sVector[i-1];
			for(;i<N; i++)
			{
				sVector[i] = lastValue;
			}
		}
	}

	// printf("sV count : %d\n", sVector.size());
	// for(auto var : sVector)
	// {
	// 	printf("%3d", var);
	// }
	// printf("\neV count : %d\n", eVector.size());
	// for(auto var : eVector)
	// {
	// 	printf("%3d", var);
	// }
	// printf("\n");

	for(int i=0; i<Q; i++)
	{
		int s,e;
		scanf("%d %d", &s, &e);

		int min, max;

		min = sVector[s];
		max = eVector[e];


		int result = max - min;
		if(result < 0) result = 0;
		printf("%d\n", result);
	}
}

void N2()
{
	int M, N;
	scanf("%d %d", &M, &N);
	vector<int> board(N+1);
	vector<int> dice;

	for(int i; i<M; i++)
	{
		int v;
		scanf("%d", &v);
		
		if(v > N) continue;

		dice.push_back(v);
		board[v] = 1;
	}

	for(int i=1; i<N; i++)
	{
		if(board[i]!=0)
		{
			for(auto v:dice)
			{
				if(i+v > N) continue;

				board[i+v] += board[i];
			}
		}
	}

	printf("%d", board[N]);
}

void updateSet(set<string>& inputSet, vector<char> charGroup)
{
	set<string> rSet;
	for(string base:inputSet)
	{
		for(char c:charGroup)
		{
			if(base.find(c)!=string::npos) continue;

			rSet.insert(base+c);
		}
	}
	inputSet = rSet;
}

void N3()
{
	vector<char> g1 = {'b','d','g','n','p','r','s','t'};
	vector<char> g2 = {'a','e','i','o','u'};

	set<string> nameSet;
	for(int i=0; i<g1.size(); i++)
	{
		nameSet.insert(string(1, g1[i]));
	}
	updateSet(nameSet, g2);
	updateSet(nameSet, g1);
	updateSet(nameSet, g2);


	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		char name[5];
		int a,b;
		scanf("%s %d %d", name, &a, &b);

		auto itr = nameSet.begin();
		while(itr != nameSet.end())
		{
			string str = *itr;

			int cor=0, sim=0;
			for(int j=0; j<4; j++)
			{
				if(str[j]==name[j])
				{ 
					cor++;
					continue;
				}

				if(str.find(name[j])!=string::npos)
				{
					sim++;
				}
			}

			if(a!=cor || b!= sim)
			{
				nameSet.erase(itr++);
			}
			else
			{
				itr++;
			}
		}
	}

	// printf("%d\n", nameSet.size());
	// for(auto s:nameSet)
	// {
	// 	printf("%s\n", s.data());
	// }

	if(nameSet.size()!=1) printf("x");
	else printf("%s", (*(nameSet.begin())).data());

}

void N4()
{
	unordered_map<int, int> starSet;
	map<int, set<int>> groupSet;

	int M, N;
	scanf("%d %d", &M, &N);

	int groupId = 1;
	for(int i=0; i<M; i++){
		int n1, n2;
		scanf("%d %d", &n1, &n2);

		if(starSet.find(n1)!=starSet.end())
		{
			// 그룹 병합
			if(starSet.find(n2)!=starSet.end())
			{
				groupSet[starSet[n1]].insert(groupSet[starSet[n2]].begin(), groupSet[starSet[n2]].end());
				int eraseGroup = starSet[n2];
				for(int st:groupSet[eraseGroup])
				{
					starSet[st] = starSet[n1];
				}
				groupSet.erase(eraseGroup);
			}
			else
			{
				starSet.emplace(n2, starSet[n1]);
				groupSet[starSet[n1]].insert(n2);
			}
		}
		else if(starSet.find(n2)!=starSet.end())
		{
			starSet.emplace(n1, starSet[n2]);
			groupSet[starSet[n2]].insert(n1);
		}
		else
		{
			starSet.emplace(n1, groupId);
			starSet.emplace(n2, groupId);
			set<int> newGroup = {n1, n2};
			groupSet.emplace(groupId, newGroup);
			groupId++;
		}
	}

	int count=0;
	for(auto group : groupSet)
	{
		// printf("Group : %d\n\t{", group.first);
		// for(auto star: group.second)
		// {
		// 	printf("%d, ",star);
		// }
		// printf("}\n");

		if(group.second.size() <= N)
		{
			count += group.second.size();
		}
	}
	printf("%d", count);
}

// 라빈카프
bool RK(string searchStr, char *buff)
{
	int len = strlen(buff);
	int searchLen = searchStr.size();
	if(searchLen > len) return false;

	long long thash = 0;
	long long shash = 0;
	long long pow = 1;
	int i=0;
	for(i=0; i<searchLen; i++)
	{
		thash += buff[searchLen-i-1] * pow;
		shash += searchStr[searchLen-i-1] * pow;
		pow *= 3;
	}
	pow/=3;

	for(; i<len; i++)
	{
		if(thash == shash)
		{
			// 검증
			bool isSame = strncmp(searchStr.data(), buff + (i-searchLen), searchLen);
			if(!isSame) return true;
		}
		thash = 3*(thash - buff[i - searchLen] * pow) + buff[i];
	}

	if(thash == shash)
	{
		// 검증
		bool isSame = strncmp(searchStr.data(), buff + (len-searchLen), searchLen);
		if(!isSame) return true;
	}

	return false;
}

// 욕설 필터링.
void N5()
{
	int N;
	char buff[101];

	vector<string> abuseList;

	scanf("%d", &N);

	for(int i=0; i<N; i++)
	{
		scanf("%s", buff);
		bool isDuplicate = false;
		for(auto str : abuseList)
		{
			if(RK(str, buff))
			{
				isDuplicate = true;
				printf("%s\n", buff);
				break;
			}
		}

		if(isDuplicate) continue;
		string newAbuse = buff;
		abuseList.push_back(newAbuse);
	}
}

int main(void)
{
	N5();

	return 0;
}