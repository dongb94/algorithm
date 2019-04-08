#include <iostream>

char* TransString(char input[], int length);

int main() {
	char input[] = {'c','d',' ','a',' ','e','h','\0'};
	
	printf("%s\n", TransString(input, 8));
}

char* TransString(char input[], int length){
	
	int transLength = 0;

	for (int i = 0; i < length; i++) {
		if (input[i] == ' ') transLength += 3;
		else transLength += 1;
	}

	char* output = new char[transLength];
	char* iter = output;

	for (int i = 0; i < length; i++) {
		printf("%d\n", iter);
		if (input[i] != ' ') {
			*iter = input[i];
			iter += 1;
		}
		else {
			*iter = '%';
			iter += 1;
			*iter = '2';
			iter += 1;
			*iter = '0';
			iter += 1;
		}
	}
	
	printf("%c\n", output[transLength - 1]);

	return output;
}