#include <iostream>
#include <stdio.h>

bool CheckIsPermutation(char* str1, char* str2);

int main() {
	
	std::ios_base::sync_with_stdio(false);

	char string1[100];
	char string2[100];

	std::cin.getline(string1, 99);
	std::cin.getline(string2, 99);
	
	printf("%d\n", CheckIsPermutation(string1, string2));
}

bool CheckIsPermutation(char str1[], char str2[]) {
	
	if (sizeof(*str1) != sizeof(*str2)) return false;
	
	int alphabet[26];

	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}

	for (int i = 0; i < sizeof(str1) / sizeof(char); i++) {

		if (str1[i] <= 'Z' && str1[i] >= 'A') {
			str1[i] -= 'Z' - 'z';
		}
		if (str2[i] <= 'Z' && str2[i] >= 'A') {
			str2[i] -= 'Z' - 'z';
		}

		alphabet[str1[i] - 'a']++;
		alphabet[str2[i] - 'a']--;
	}
	
	for (int i = 0; i < 26; i++) {
		printf("%d = %d\n", i, alphabet[i]);
		if (alphabet[i] != 0) {
			return false;
		}
	}

	return true;
}
