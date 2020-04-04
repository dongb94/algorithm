#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	string input;
	getline(cin, input);

	for (int i = 0; i < T; i++) {
		int depth = 0;
		string output = "";
		getline(cin, input);

		for (int j = 0; j < input.size(); j++) {
			int num = input[j] - '0';
			while (num != depth) {
				if (num > depth) {
					output += '(';
					depth++;
				}
				else if (num < depth) {
					output += ')';
					depth--;
				}
			}
			output += input[j];
		}
		while (depth > 0) {
			output += ')';
			depth--;
		}

		cout << "Case #" << i + 1 << ": " << output << endl;

	}
}