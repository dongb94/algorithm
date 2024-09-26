//
// Created by Donggeon Byeon on 2024-09-26.
// https://programmers.co.kr/skill_checks/572684?challenge_id=15193

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cards) {

	int l = 0;
	int l2 = 0;
	for(int i=0;i<cards.size();i++)
	{
		auto next = i;
		int count = 0;
		while(cards[next] != 0)
		{
			auto temp = next;
			next = cards[next] - 1;
			cards[temp] = 0;
			count++;
		}
		if(l < count)
		{
			if(l > l2) l2 = count;
			else l = count;
		}
		else if(l2 < count)
		{
			l2 = count;
		}
	}

	return l*l2;
}