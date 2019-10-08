#include <iostream>

int main() {
	int year;
	scanf("%d", &year);
	printf(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)?"1":"0");
}