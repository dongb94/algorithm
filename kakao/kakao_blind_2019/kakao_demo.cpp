#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>> v) {
	vector<int> ans;

	int x[2];
	int y[2];
	int cnt[2];

	for (int i = 0; i < 2; i++) {
		cnt[i] = 0; 
	}
	for (int i = 0; i < v.size(); i++) {
		vector<int> p = v[i];
		if (i == 0) {
			x[0] = p[0];
			y[0] = p[1];
		}
		if (x[0] == p[0]) cnt[0]++;
		else {
			x[1] = p[0];
		}
		if (y[0] == p[1]) cnt[1]++;
		else {
			y[1] = p[1];
		}
	}

	if (cnt[0] == 1) ans.push_back(x[0]);
	else ans.push_back(x[1]);
	if (cnt[1] == 1) ans.push_back(y[0]);
	else ans.push_back(y[1]);

	return ans;
}

int main() {
	vector<int> v1 = { 1,4 };
	vector<int> v2 = { 3,4 };
	vector<int> v3 = { 3,5 };

	vector<vector<int>> pointv;
	pointv.push_back(v1);
	pointv.push_back(v2);
	pointv.push_back(v3);

	vector<int> v4 = solution(pointv);

	cout << v4[0] << v4[1];
}

