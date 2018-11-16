// 자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cout << N - i << '\n';
	}
}