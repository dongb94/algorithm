#include <string>
#include <vector>
#include <queue>

using namespace std;

class  Node{
public:
	bool wall;
	bool ver;
	int x, y;
	int to, from;

	bool operator<(Node right) {
		return (from + to) > (right.from + right.to);
	}
};

bool operator<(Node left, Node right) {
	return (left.from + left.to) > (right.from + right.to);
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	int n = board.size();
	Node **b = new Node*[n];
	for (int i = 0; i < n; i++) {
		b[i] = new Node[n];
		for (int j = 0; j < n; j++) {
			b[i][j].x = i;
			b[i][j].y = j;
			b[i][j].from = 99999;
			b[i][j].to = n*2 - j - i - 2;
			if (board[i][j] == 1)
				b[i][j].wall = true;
			else
				b[i][j].wall = false;
		}
	}

	b[0][1].from = 0;
	b[0][1].ver = true;

	// auto cmp = [](Node left, Node right) { return (left.from + left.to) < (right.from + right.to); };//

	priority_queue<Node, vector<Node>> pq;
	vector<Node> endNode;

	endNode.push_back(b[0][0]);
	endNode.push_back(b[0][1]);
	pq.push(b[0][1]);

	while (!pq.empty()) {
		Node cur = pq.top();
		endNode.push_back(cur);
		pq.pop();

		printf("xy : %d %d \n", cur.x, cur.y);
		printf("ft : %d %d \n", cur.from, cur.to);

		if (cur.x!=n-1 && !b[cur.x+1][cur.y].wall) {
			bool br;
			for (int i = 0; i < endNode.size(); i++) {
				if (endNode[i].x == b[cur.x + 1][cur.y].x
					&& endNode[i].y == b[cur.x + 1][cur.y].y)
					br = true;
				else br = false;
			}
			if (br) break;

			if (cur.ver || (cur.y != 0 && !b[cur.x + 1][cur.y-1].wall)) {
				if (cur.from + 1 <= b[cur.x + 1][cur.y].from) {
					b[cur.x + 1][cur.y].from = cur.from + 1;
					b[cur.x + 1][cur.y].ver = true;
					if (b[cur.x + 1][cur.y].x == n - 1
						&& b[cur.x + 1][cur.y].y == n - 1)
						return b[cur.x + 1][cur.y].from;
					pq.push(b[cur.x + 1][cur.y]);
				}
			}
		}

		if (cur.y != n - 1 && !b[cur.x][cur.y + 1].wall) {
			bool br;
			for (int i = 0; i < endNode.size(); i++) {
				if (endNode[i].x == b[cur.x][cur.y + 1].x
					&& endNode[i].y == b[cur.x][cur.y + 1].y)
					br = true;
				else br = false;
			}
			if (br) break;

			if (!cur.ver || (cur.x != 0 && !b[cur.x-1][cur.y + 1].wall)) {
				if (cur.from + 1 <= b[cur.x][cur.y + 1].from) {
					b[cur.x][cur.y + 1].from = cur.from + 1;
					b[cur.x][cur.y + 1].ver = false;
					if (b[cur.x][cur.y + 1].x == n - 1
						&& b[cur.x][cur.y + 1].y == n - 1)
						return b[cur.x][cur.y + 1].from;
					pq.push(b[cur.x][cur.y + 1]);
				}
			}
		}

		if (cur.x != 0 && !b[cur.x - 1][cur.y].wall) {
			Node next = b[cur.x - 1][cur.y];
			bool br;
			for (int i = 0; i < endNode.size(); i++) {
				if (endNode[i].x == next.x
					&& endNode[i].y == next.y)
					br = true;
				else br = false;
			}
			if (br) break;

			if (cur.ver && cur.x != 1 && !b[cur.x - 2][cur.y].wall) {
				if (cur.from + 1 <= next.from) {
					next.from = cur.from + 1;
					next.ver = true;
					pq.push(next);
				}
			}
			else if(!cur.ver && cur.y != 0 && !b[cur.x - 1][cur.y - 1].wall) {
				if (cur.from + 1 <= next.from) {
					next.from = cur.from + 1;
					next.ver = true;
					pq.push(next);
				}
			}
		}

		if (cur.y != 0 && !b[cur.x][cur.y - 1].wall) {
			Node next = b[cur.x][cur.y - 1];
			bool br;
			for (int i = 0; i < endNode.size(); i++) {
				if (endNode[i].x == next.x
					&& endNode[i].y == next.y)
					br = true;
				else br = false;
			}
			if (br) break;

			if ((cur.ver && cur.x!=0 && !b[cur.x -1][cur.y - 1].wall) || (!cur.ver && cur.y != 1 && !b[cur.x][cur.y - 2].wall)) {
				if (cur.from + 1 <= next.from) {
					next.from = cur.from + 1;
					next.ver = false;
					pq.push(next);
				}
			}
		}

		if (cur.x !=0 && cur.y != 0 && !b[cur.x - 1][cur.y - 1].wall) {
			Node next = b[cur.x - 1][cur.y - 1];
			bool br;
			for (int i = 0; i < endNode.size(); i++) {
				if (endNode[i].x == next.x
					&& endNode[i].y == next.y)
					br = true;
				else br = false;
			}
			if (br) break;

			if (cur.ver && !b[cur.x][cur.y - 1].wall) {
				if (cur.from + 1 <= next.from) {
					next.from = cur.from + 1;
						next.ver = false;
						pq.push(next);
				}
			}
			else if(!cur.ver && !b[cur.x - 1][cur.y].wall) {
				if (cur.from + 1 <= next.from) {
					next.from = cur.from + 1;
					next.ver = true;
					pq.push(next);
				}
			}
		}

		if (cur.x != 0 && cur.y != n-1 && !b[cur.x - 1][cur.y + 1].wall && cur.ver) {
			Node next = b[cur.x - 1][cur.y + 1];
			bool br;
			for (int i = 0; i < endNode.size(); i++) {
				if (endNode[i].x == next.x
					&& endNode[i].y == next.y)
					br = true;
				else br = false;
			}
			if (br) break;

			if (!b[cur.x][cur.y + 1].wall) {
				if (cur.from + 1 <= next.from) {
					next.from = cur.from + 1;
					next.ver = false;
					pq.push(next);
				}
			}
		}

		if (cur.x != n-1 && cur.y != 0 && !b[cur.x + 1][cur.y - 1].wall && !cur.ver) {
			Node next = b[cur.x + 1][cur.y - 1];
			bool br;
			for (int i = 0; i < endNode.size(); i++) {
				if (endNode[i].x == next.x
					&& endNode[i].y == next.y)
					br = true;
				else br = false;
			}
			if (br) break;

			if (!b[cur.x][cur.y + 1].wall) {
				if (cur.from + 1 <= next.from) {
					next.from = cur.from + 1;
					next.ver = true;
					pq.push(next);
				}
			}
		}
	}
}

int main() {

	vector<vector<int>> board = {
		{0,0,0,1,1},
		{0,0,0,1,0},
		{0,1,0,1,1},
		{1,1,0,0,1},
		{0,0,0,0,0}
	};
	int r = solution(board);
	printf("%d", r);
	system("pause");
}