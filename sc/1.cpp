//
// Created by Donggeon Byeon on 2024-10-15.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Node
{
public:
	Node() = default;
	void AddFriend(Node* frd) {friends.emplace_back(frd);}
	size_t GetFriendsCount()
	{
		set<Node*> totalFriends;
		for(auto frd : friends)
		{
			totalFriends.emplace(frd);
			for(auto frdSfrd : frd->friends)
			{
				totalFriends.emplace(frdSfrd);
			}
		}

		return totalFriends.empty()?0:totalFriends.size()-1;
	}
public :
	vector<Node*> friends;
};

vector<int> solution(int N, vector<vector<int> > relation)
{
	vector<int> answer;

    vector<Node> friends(N);

	for(auto frd :relation)
	{
		int f1 = frd[0]-1;
		int f2 = frd[1]-1;
		friends[f1].AddFriend(&friends[f2]);
		friends[f2].AddFriend(&friends[f1]);
	}

	for(auto frd : friends){
		answer.emplace_back(frd.GetFriendsCount());
	}

	return answer;
}