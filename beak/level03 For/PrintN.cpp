//자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cout << i + 1 << endl;
	}
}