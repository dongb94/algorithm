#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int a;
	int b;
	scanf("%d %d", &a, &b);

	queue<int> timeList;
	vector<int> csm;
	
	for (int i = 0; i < a; i++) {
		int temp;
		scanf("%d", &temp);
		timeList.push(temp);
	}

	for (int i = 0; i < b; i++) {
		if (timeList.empty())break;
		csm.push_back(timeList.front());
		timeList.pop();
	}

	int time = 0;
	while (!timeList.empty()) {
		int low = 128;
		for (int i = 0; i < b; i++) {
			if (csm[i] < low) {
				low = csm[i];
			}
		}
		time += low;
		for (int i = 0; i < b; i++) {
			csm[i] -= low;
			if (csm[i] == 0) {
				csm[i] = timeList.front();
				timeList.pop();
			}
			if (timeList.empty) break;
		}
	}

	int high=0;
	for (int i = 0; i < b; i++) {
		if (csm[i] > high)
			high = csm[i];
	}
	time += high;

	printf("%d", time);

	return 0;
}