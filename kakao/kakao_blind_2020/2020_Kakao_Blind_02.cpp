#include <string>
#include <vector>
#include <hash_map>
#include <set>

using namespace std;

hash_map<int, hash_map<string, int>> orderMap;

struct order {
	string orderSet;
	int value;
};

void doCombination(vector<int> combArr, int n, int r, int index, int target, string arr) {
	if (r == 0) {
		string key = "";
		set<char> sett;
		for (int i = 0; i < index; i++) {
			sett.insert(arr[combArr[i]]);
		}
		
		set<char>::iterator iter = sett.begin();
		while (iter != sett.end()) {
			key.push_back(*iter);
		}

		hash_map<string, int>::iterator find = orderMap.at(index).find(key);
		if (find == orderMap.at(index).end()) {
			orderMap.at(index).insert(hash_map<string,int>::value_type(key, 1));
		}
		else {
			find->second += 1;
		}
	}
	else if (target == n) return;
	else {
		combArr[index] = target;
		doCombination(combArr, n, r - 1, index + 1, target + 1, arr);

		if(target <= n-r)
			doCombination(combArr, n, r, index, target + 1, arr);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (int i = 0; i < course.size(); i++) {
		hash_map<string, int> temp;
		orderMap.insert(hash_map<int, hash_map<string, int>>::value_type(course[i], temp));
	}

	for (int i = 0; i < orders.size(); i++) {
		string order = orders[i];

		for (int j = 0; j < course.size(); j++) {
			int r = course[j];

			if (r > order.length()) continue;
			
			vector<int> combArr(r);

			doCombination(combArr, order.length(), r, 0, 0, order);
		}
	}


	// hash_map 못쓰네?
	// 정렬
	// 추출
	// 정렬

	return answer;
}