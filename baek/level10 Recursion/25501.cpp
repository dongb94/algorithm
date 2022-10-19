// https://www.acmicpc.net/problem/25501
// 재귀의 귀재

#include <iostream>
#include <string.h>

int recursion(const char *s, int l, int r, int *c){
	(*c)++;
	if(l >= r) return 1;
	else if(s[l] != s[r]) return 0;
	else return recursion(s, l+1, r-1, c);
}

int isPalindrome(const char *s, int *c){
	return recursion(s, 0, strlen(s)-1, c);
}

int main(){
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
	{
		char input[1000];
		scanf("%s", input);

		int c=0;
		int r = isPalindrome(input, &c);
		printf("%d %d\n", r, c);
		
	}
}