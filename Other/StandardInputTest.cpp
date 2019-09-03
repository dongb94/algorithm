#include <iostream>

#pragma region ����

void integer() {
	int a, b, c, d, e;

	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);

	printf("%d%d%d%d%d", a, b, c, d, e);
}

#pragma endregion


#pragma region ���ڿ�
/// ����
void manyChar() {
	char c1, c2, c3, c4, c5;

	scanf_s("%c", &c1);
	scanf_s("%c", &c2);
	scanf_s("%c", &c3);
	scanf_s("%c", &c4);
	scanf_s("%c", &c5);

	printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
	printf("%c %c %c %c %c\n", c1, c2, c3, c4, c5);
}

void manyChar2() {
	char c1, c2, c3, c4, c5;

	scanf_s("1%c", &c1);
	scanf_s("2%c", &c2);
	scanf_s("3%c", &c3);
	scanf_s("4%c", &c4);
	scanf_s("5%c", &c5);

	printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
	printf("%c %c %c %c %c\n", c1, c2, c3, c4, c5);
}

void manyChar3() {
	char c1, c2, c3, c4, c5;

	scanf_s("%c%c%c%c%c", &c1, &c2, &c3, &c4, &c5);

	printf("%c%c%c%c%c", c1, c2, c3, c4, c5);
}

void manyChar4() {
	char c1, c2, c3, c4, c5;

	scanf_s("%c %c %c %c %c", &c1, 1, &c2, 1, &c3, 1, &c4, 1, &c5, 1);

	printf("%c%c%c%c%c", c1, c2, c3, c4, c5);
}

/// ���ڿ�
void string() {	
	char *s1, *s2;

	s1 = new char[10]; // �ʱ�ȭ�� �ʿ��ϴ�
	scanf_s("%s", s1); // ���ڿ��� ��� �̹� �ּ� (char*)
	printf("%s\n", s1);

	s2 = new char[10];
	scanf_s("%s", s2);
	printf("%s\n", s2);

	printf("%s%s", s1, s2);
}

void string2() {
	char *s1;

	s1 = new char[20];
	scanf_s("%[^\n]", s1);

	printf("%s", s1);
}

#pragma endregion

int main() {
	char *s1, *s2, *s3, *s4, *s5;
	int i1, i2, i3, i4, i5;

	string2();
}

