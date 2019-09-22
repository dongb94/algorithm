#include <string>
#include <vector>

using namespace std;

bool check(string s) {
	int stack = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') stack++;
		else stack--;

		if (stack < 0) return false;
	}
	return true;
}

bool checkBlance(string s) {
	int stack = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') stack++;
		else stack--;
	}
	if (stack == 0) return true;
	return false;
}

string changeV(string v) {
	string answer = "";
	if (v.length() == 0) return answer;
	if (check(v)) return v;

	string u, v2;
	for (int i = 0; i < v.length(); i += 2) {
		u.push_back(v[i]);
		u.push_back(v[i + 1]);

		if (checkBlance(u)) {
			for (int j = i + 2; j < v.length(); j++)
				v2.push_back(v[j]);
			break;
		}
	}

	if (check(u)) {
		u += changeV(v2);
		return u;
	}

	answer += '(';
	answer += changeV(v2);
	answer += ')';

	for (int i = 1; i < u.length() - 1; i++) {
		if (u[i] == ')') answer += '(';
		else answer += ')';
	}

	return answer;
}

string solution(string p) {

	return changeV(p);
}
