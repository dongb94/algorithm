#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	for (int i = 0; i < queries.size(); i++) {
		vector<int> nonWild;
		for (int k = 0; k < queries[i].length(); k++) {
			if (queries[i][k] != '?') {
				nonWild.push_back(k);
			}
		}

		int pass = 0;
		for (int j = 0; j < words.size(); j++) {
			if (queries[i].length() != words[j].length()) continue;
			for (int k = 0; k < nonWild.size(); k++) {
				if (queries[i][nonWild[k]] != words[j][nonWild[k]]) break;
				if (k == nonWild.size() - 1) pass++;
			}
		}
		answer.push_back(pass);
	}

	return answer;
}