#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>

int main() {
	int T, N, P;
	int *skill = new int[10001];

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &P);
		int leastCoach = -1;
		std::deque<int> team;

		for (int j = 10000; j > 0; j--) skill[j] = 0;

		for (int j = 0; j < N; j++) {
			int sk;
			scanf("%d", &sk);
			skill[sk]++;
		}

		for (int j = 10000; j > 0; j--) {

			for (int k = 0; k < skill[j]; k++) {
				team.push_back(j);
			}

			if (team.size() < P) continue;

			while (team.size() >= P) {
				int large = team[0];
				int sum = 0;
				for (int k = 1; k < P; k++) {
					sum += large - team[k];
				}
				if (sum < leastCoach || leastCoach == -1) leastCoach = sum;
				
				while (team.size()!=0 && team.front() == large) {
					team.pop_front();
				}
			}
		}

		printf("Case #%d: %d\n", i + 1, leastCoach);

	}
}