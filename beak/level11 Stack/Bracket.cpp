/*
��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�.
�� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���.
�� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���.
���� x �� VPS ��� �̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�.
�׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�.
���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�.

�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�.
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