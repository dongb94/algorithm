#include <iostream>
#include <vector>
#include <algorithm>

struct timeSet
{
	int index;
	int S;
	int E;
	timeSet(int i, int S, int E) :index(i) ,S(S), E(E) {}
};

bool compare(timeSet a, timeSet b) {
	if (a.S == b.S) a.E < b.E;
	return a.S < b.S;
}

int main() {

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		int C = 0,J = 0;
		bool brk = false;
		
		scanf("%d", &N);
		std::vector<timeSet> set;
		char* result = new char[N+1];

		for (int j = 0; j < N; j++) {
			int S, E;
			scanf("%d %d", &S, &E);
			timeSet time(j,S,E);
			set.push_back(time);
		}

		std::sort(set.begin(), set.end(), compare);

		for (int j = 0; j < set.size(); j++) {
			timeSet task = set[j];
			if (C <= task.S) {
				result[task.index] = 'C';
				C = task.E;
			}
			else if (J <= task.S) {
				result[task.index] = 'J';
				J = task.E;
			}
			else {
				brk = true;
				break;
			}
		}
		result[N] = '\0';

		printf("Case #%d: ", i+1);
		if (brk)
			printf("IMPOSSIBLE\n");
		else
			printf("%s\n", result);
	}
}