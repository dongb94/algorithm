// �ڿ��� N�� �־����� ��, N���� 1���� �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

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