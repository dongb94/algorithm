// 문제 번호 : 5622
// https://www.acmicpc.net/problem/5622
#include <iostream>

int main() {
	char input[30];
	scanf("%s", input);
	char *nextChar = input;
	int sum = 0;
	while (*nextChar != '\0') {
		sum += 2;
		switch (*nextChar) {
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			sum += 1;
		case 'T':
		case 'U':
		case 'V':
			sum += 1;
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
			sum += 1;
		case 'M':
		case 'N':
		case 'O':
			sum += 1;
		case 'J':
		case 'K':
		case 'L':
			sum += 1;
		case 'G':
		case 'H':
		case 'I':
			sum += 1;
		case 'D':
		case 'E':
		case 'F':
			sum += 1;
		case 'A':
		case 'B':
		case 'C':
			sum += 1;
			break;
		}
		nextChar++;
	}
	printf("%d", sum);
}