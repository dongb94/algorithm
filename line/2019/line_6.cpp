#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printNumber(char num, int len, int low) {
	int h = len * 2 - 1;
	switch (num) {
	case '0' :
		if (low == 0 || low == h - 1) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			for (int i = 0; i < len; i++) {
				if (i == 0 || i == len - 1)
					printf("#");
				else
					printf(".");
			}
		}
		break;
	case '1':
		for (int i = 0; i < len; i++) {
			if (i == len - 1)
				printf("#");
			else
				printf(".");
		}
		break;
	case '2':
		if (low == 0 || low == h - 1 || low == h/2) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			if(low < h/2)
				for (int i = 0; i < len; i++) {
					if (i == len - 1)
						printf("#");
					else
						printf(".");
				}
			else
				for (int i = 0; i < len; i++) {
					if (i == 0)
						printf("#");
					else
						printf(".");
				}
		}
		break;
	case '3':
		if (low == 0 || low == h - 1 || low == h / 2) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			for (int i = 0; i < len; i++) {
				if (i == len - 1)
					printf("#");
				else
					printf(".");
			}
		}
		break;
	case '4':
		if (low == h / 2) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			if (low < h / 2)
				for (int i = 0; i < len; i++) {
					if (i == 0 || i == len - 1)
						printf("#");
					else
						printf(".");
				}
			else
				for (int i = 0; i < len; i++) {
					if (i == len -1)
						printf("#");
					else
						printf(".");
				}
		}
		break;
	case '5':
		if (low == 0 || low == h - 1 || low == h / 2) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			if (low > h / 2)
				for (int i = 0; i < len; i++) {
					if (i == len - 1)
						printf("#");
					else
						printf(".");
				}
			else
				for (int i = 0; i < len; i++) {
					if (i == 0)
						printf("#");
					else
						printf(".");
				}
		}
		break;
	case '6':
		if (low == h - 1 || low == h / 2) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			if (low < h / 2)
				for (int i = 0; i < len; i++) {
					if (i == 0)
						printf("#");
					else
						printf(".");
				}
			else
				for (int i = 0; i < len; i++) {
					if (i == 0 || i == len -1)
						printf("#");
					else
						printf(".");
				}
		}
		break;
	case '7':
		if (low == 0) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			for (int i = 0; i < len; i++) {
				if (i == len - 1)
					printf("#");
				else
					printf(".");
			}
		}
		break;
	case '8':
		if (low == 0 || low == h - 1 || low == h / 2) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			for (int i = 0; i < len; i++) {
				if (i == 0 || i == len - 1)
					printf("#");
				else
					printf(".");
			}
		}
		break;
	case '9':
		if (low == 0 || low == h - 1 || low == h / 2) {
			for (int i = 0; i < len; i++) {
				printf("#");
			}
		}
		else {
			if (low < h / 2)
				for (int i = 0; i < len; i++) {
					if (i == 0 || i == len - 1)
						printf("#");
					else
						printf(".");
				}
			else
				for (int i = 0; i < len; i++) {
					if (i == len - 1)
						printf("#");
					else
						printf(".");
				}
		}
		break;
	}
}

int main(void) {
	int num;
	char *s;
	scanf("%d", &num);
	scanf("%s", s);

	int maxLen=0;
	vector<pair<int, string>> stringQ;

	for (int i = 0; i < num; i++) {
		int len;
		char *n;
		scanf("%d", &len);
		scanf("%s", s);

		if (len > maxLen) maxLen = len;
		pair<int, string> temp;
		
		temp.first = len;
		temp.second = string(n);

		stringQ.push_back(temp);
	}

	int h =  maxLen * 2 - 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < stringQ.size(); j++) {
			pair<int, string> p = stringQ[j];
			for (int k = 0; k < p.second.length; k++) {
				char number = p.second[k];
				switch (s[0])
				{
				case 'T' :
					if (i < p.first * 2 - 1) printNumber(number, p.first, i);
					else
						for (int i = 0; i < p.first; i++) {
							printf(".");
						}
					break;
				case 'B':
					if (h - i - 1 < p.first * 2 - 1) printNumber(number, p.first, i - (h - p.first * 2 + 1));
					else
						for (int i = 0; i < p.first; i++) {
							printf(".");
						}
					break;
				case 'M':
					int d = h - p.first * 2 + 1;
					if (i < d/2 || maxLen - i - 1 < d/2) 
						for (int i = 0; i < p.first; i++) {
							printf(".");
						}
					else
						printNumber(number, p.first, i - d/2);
					break;
				default:
					break;
				}

				printf(" ");
			}
		}
		printf("\n");
	}
}