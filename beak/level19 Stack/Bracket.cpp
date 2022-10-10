/*
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다.
만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다.
그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다.
예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다.

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>

int main() {

	std::ios_base::sync_with_stdio(false);

	int N;

	std::cin >> N;
	char next[51];
	std::cin.getline(next, 51);
	for (; N > 0; N--) {
		std::stack<int> bracketStack;
		std::cin.getline(next, 51);
		for (int i = 0;; i++) {
			if (next[i] == '(') bracketStack.push(1);

			else if (next[i] == ')')
				if (bracketStack.empty()) {
					std::cout << "NO\n";
					break;
				}
				else bracketStack.pop();

				if (next[i] == '\0') {

					if (bracketStack.empty()) std::cout << "YES\n";
					else std::cout << "NO\n";

					break;
				}
		}
	}

	system("pause");
}