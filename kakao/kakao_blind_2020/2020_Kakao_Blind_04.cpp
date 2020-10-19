#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
	int num;
	int a = -1;
	int b = -1;
	int s = -1;
	vector<node*> conn;
};

struct nodePtr {
	node* node;
};

bool operator< (nodePtr a, nodePtr b) {
	
	if (a.node->b != -1)
		return a.node->b > b.node->b;
	else if (a.node->a != -1)
		return a.node->a > b.node->a;
	else
		return a.node->s > b.node->s;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = -1;

	a--;
	b--;
	s--;

	vector<node*> nodes(n);
	vector<vector<int>> rail(n,vector<int>(n));

	for (int i = 0; i < nodes.size(); i++) {
		nodes[i] = new node();
		nodes[i]->num = i;
	}

	for (int i = 0; i < fares.size(); i++) {
		rail[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2];
		rail[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2];
		nodes[fares[i][0] - 1]->conn.push_back(nodes[fares[i][1] - 1]);
		nodes[fares[i][1] - 1]->conn.push_back(nodes[fares[i][0] - 1]);
	}

	priority_queue<nodePtr> searchQ;
	vector<int> searchComNode(n);
	nodes[s]->s = 0;
	searchComNode[s] = 1;
	nodePtr start;
	start.node = nodes[s];
	searchQ.push(start);
	while (!searchQ.empty()) {
		node* curNode = searchQ.top().node;
		searchQ.pop();

		for (int i = 0; i < curNode->conn.size(); i++) {
			if (curNode->conn[i]->s == -1 || curNode->conn[i]->s > curNode->s + rail[curNode->num][curNode->conn[i]->num]) {
				curNode->conn[i]->s = curNode->s + rail[curNode->num][curNode->conn[i]->num];
			}

			if (searchComNode[curNode->conn[i]->num] == 0) {

				nodePtr next;
				next.node = curNode->conn[i];

				searchQ.push(next);
				searchComNode[curNode->conn[i]->num] = 1;
			}
		}
	}

	searchComNode.assign(n, 0);
	nodes[a]->a = 0;
	searchComNode[a] = 1;
	start.node = nodes[a];
	searchQ.push(start);
	while (!searchQ.empty()) {
		node* curNode = searchQ.top().node;
		searchQ.pop();

		for (int i = 0; i < curNode->conn.size(); i++) {
			if (curNode->conn[i]->a == -1 || curNode->conn[i]->a > curNode->a + rail[curNode->num][curNode->conn[i]->num]) {
				curNode->conn[i]->a = curNode->a + rail[curNode->num][curNode->conn[i]->num];
			}

			if (searchComNode[curNode->conn[i]->num] == 0) {

				nodePtr next;
				next.node = curNode->conn[i];

				searchQ.push(next);
				searchComNode[curNode->conn[i]->num] = 1;
			}
		}
	}

	searchComNode.assign(n, 0);
	nodes[b]->b = 0;
	searchComNode[b] = 1;
	start.node = nodes[b];
	searchQ.push(start);
	while (!searchQ.empty()) {
		node* curNode = searchQ.top().node;
		searchQ.pop();

		for (int i = 0; i < curNode->conn.size(); i++) {
			if (curNode->conn[i]->b == -1 || curNode->conn[i]->b > curNode->b + rail[curNode->num][curNode->conn[i]->num]) {
				curNode->conn[i]->b = curNode->b + rail[curNode->num][curNode->conn[i]->num];
			}

			if (searchComNode[curNode->conn[i]->num] == 0) {

				nodePtr next;
				next.node = curNode->conn[i];

				searchQ.push(next);
				searchComNode[curNode->conn[i]->num] = 1;
			}
		}
	}

	for (int i = 0; i < nodes.size(); i++) {

		cout << "node" << i << " " << nodes[i]->s << " " << nodes[i]->a << " " << nodes[i]->b << endl;

		if (nodes[i]->a == -1) continue;
		if(answer == -1 || answer > nodes[i]->a + nodes[i]->b + nodes[i]->s)
			answer = nodes[i]->a + nodes[i]->b + nodes[i]->s;
	}

	return answer; 
}