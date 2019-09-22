#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 9999;
	bool flag = false;
	for (int i = 1; i <= s.length()/2; i++) {
		flag = false;
		int tempLen = s.length();
		for (int j = 0; j < s.length() - i*2 + 1; j+=i) {
			for (int k = 0; k < i; k++) {
				if (s[j + k + i] == s[j + k]) {
					if (k == i - 1) {
						tempLen -= i;
						if (!flag) {
							tempLen++;
							flag = true;
						}
					}
					else 
						continue;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (tempLen < answer) answer = tempLen;
	}

	return answer;
}