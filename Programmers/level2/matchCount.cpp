//
// Created by Donggeon Byeon on 2024-09-26.
//https://programmers.co.kr/skill_checks/572684

#include <iostream>

using namespace std;


bool checkSameGroup(int& n, int& a, int& b)
{
	int half = n >> 1;
	if(half < a && half < b)
	{
		a-=half;
		b-=half;
		return true;
	}
	else if(half >= a && half >= b)
	{
		return true;
	}
	else
		return false;
}


int solution(int n, int a, int b)
{
	int answer = 0;

	while(checkSameGroup(n, a, b))
	{
		n = n>>1;
	}
	while(n > 1)
	{
		n = n>>1;
		answer++;
	}

	return answer;
}
