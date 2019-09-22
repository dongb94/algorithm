#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> num;
	vector<int> ans;
	int b;

	while (scanf("%d", &b) != EOF) {
		num.push_back(b);
	}

	b = num[num.size() - 1];
	num.pop_back();

	int sort[10] = { 0 };

	for (int i = 0; i < num.size(); i++) {
		sort[num[i]] = 1;
	}
	num.clear();

	for (int i = 0; i < 10; i++) {
		if (sort[i] == 1) num.push_back(i);
	}

	int size = num.size();
	int a = 1;
	for (int i = size; i > 1; i--) {
		a *= i;
	}
	
	while (size != 0) {
		a /= size;
		size--;

		int c = (b-1) / a;
		b = b % a;
		for (int i = 0; i < 10; i++) {
			if (num[i] != -1) {
				if (c <= 0) {
					ans.push_back(num[i]);
					num[i] = -1;
					break;
				}
				c--;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
	}

	return 0;
}