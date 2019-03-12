#include <iostream>

bool CheckChange(char str1[], char str2[], int len1, int len2) {
	if (len1 - len2 > 1 || len2 - len1 > 1) return false;

	int maxLength = len1 > len2 ? len1 : len2;
	int change = 0;
	int insert = 0;
	int remove = 0;

	if (len1 == len2) {
		for (int i = 0; i < maxLength; i++) {
			if (str1[i] == str2[i]) continue;
			else if (change > 0) return false;
			else change++;
		}
	}
	else {
		for (int i = 0; i < maxLength; i++) {
			if (str1[i] == str2[i + insert - remove]) continue;
			else if (insert + remove > 0) return false;
			else if (str1[i] == str2[i + 1]) insert++;
			else if (str1[i + 1] == str2[i]) remove++;
			else return false;
		}
	}

	return true;
}

int main() {
	char input1[5] = { 'a','b','c','d','\0' };
	char input2[5] = { 'a','b','e','d','\0' };
	char input3[6] = { 'a','b','c','d','e','\0' };
	char input4[4] = { 'a','c','d','\0' };

	printf("%d\n", CheckChange(input1, input2, 5, 5 ));
	printf("%d\n", CheckChange(input1, input3, 5, 6));
	printf("%d\n", CheckChange(input1, input4, 5, 4));
	printf("%d\n", CheckChange(input2, input3, 5, 6));
}