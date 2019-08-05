#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int p_num = 0;
	int y_num = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'p' || s[i] == 'P') p_num++;
		if (s[i] == 'y' || s[i] == 'Y') y_num++;
	}

	return p_num == y_num;
}

//////////////////////////////////////////////////////

#include <string>

using namespace std;

string solution(int num) {
	
	if (num % 2 == 0) return "Even";

	return "Odd";
}