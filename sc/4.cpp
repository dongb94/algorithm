//
// Created by Donggeon Byeon on 2024-10-15.
//

#include <string>
#include <vector>
#include <queue>
using namespace std;

// head => node1
class weightTree
{
public:
	weightTree(vector<int> truck) {
		truckNum = truck.size();

		int treeSize = 1;
		while (treeSize < truckNum) treeSize *= 2;
		treeSize = 2 * treeSize - 1;

		tree.resize(treeSize);
		initailize(truck, 1, 0, truckNum-1);
	}

	void initailize(vector<int>& truck, int node, int start, int end){
		if(start == end)
		{
			tree[node] = truck[start];
			return;
		}
		int mid = (start + end) /2;
		initailize(truck, node*2, start, mid);
		initailize(truck, node*2 +1, mid+1, end);
		tree[node] = max(tree[node*2], tree[node*2 +1]);
	}

	int findIndex(int node, int start, int end, int weight)
	{
		if(tree[node] < weight) return -1;
		if(start == end) {
			tree[node] -= weight;
			update(node/2);
			return start+1;
		}
		int mid = (start + end) /2;
		int res = findIndex(node * 2, start, mid, weight);
		if(res != -1) return res;
		return findIndex(node *2 +1, mid+1, end, weight);
	}

	void update(int node)
	{
		if(node == 0) return;
		int preValue = tree[node];
		tree[node] = max(tree[node*2], tree[node*2 +1]);
		if(tree[node] == preValue) return;
		else update(node/2);
	}

public :
	int truckNum = 0;
	vector<int> tree;
};

vector<int> solution(vector<int> truck, vector<int> w) {
	vector<int> answer;

	weightTree wt{truck};
	for(int weight : w){
		answer.push_back(wt.findIndex(1, 0, wt.truckNum-1, weight));
	}

	return answer;
}