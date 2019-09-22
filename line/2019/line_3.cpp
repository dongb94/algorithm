#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int num;
	scanf("%d", &num);

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < num; i++) {
		pair<int, int> temp;
		scanf("%d %d", &temp.first, &temp.second);
		pq.push(temp);
	}

	int highSize = 0;
	priority_queue<int, vector<int>, greater<int>> pq2;
	while (!pq.empty()) {
		pair<int, int> temp = pq.top();
		pq.pop();
		if (pq2.empty());
		else {
			
			while (pq2.top() <= temp.first) {
				pq2.pop();
				if (pq2.empty()) break;
			}
		}
		pq2.push(temp.second);

		if (highSize < pq2.size()) highSize = pq2.size();
	}

	printf("%d", highSize);

	return 0;
}