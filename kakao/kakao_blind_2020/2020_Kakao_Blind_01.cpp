#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.length(); i++) {
		new_id[i] = tolower(new_id[i]);
	}

	for (int i = 0; i < new_id.length(); i++) {
		if (new_id[i] >= 'a' && new_id[i] <= 'z') {
			answer += new_id[i];
		}
		if (new_id[i] >= '0' && new_id[i] <= '9') {
			answer += new_id[i];
		}
		if (new_id[i] == '-') {
			answer += new_id[i];
		}
		if (new_id[i] == '_') {
			answer += new_id[i];
		}
		if (new_id[i] == '.') {
			answer += new_id[i];
		}
	}
	new_id = answer;

	while(true){
		int pt = new_id.find("..");
		if (pt == -1) {
			break;
		}
		new_id.replace(pt, 2, ".");
	}

	if (new_id[0] == '.') {
		new_id = new_id.substr(1);
	}
	if (new_id[new_id.length() - 1] == '.') {
		new_id = new_id.substr(0, new_id.length() - 1);
	}

	if (new_id.empty()) {
		new_id = "a";
	}

	if (new_id.length() > 15) {

		if(new_id[14] == '.')
			new_id = new_id.substr(0, 14);
		else
			new_id = new_id.substr(0, 15);
	}

	while (new_id.length() < 3) {
		new_id += new_id[new_id.length() - 1];
	}

	answer = new_id;

	return answer;
}