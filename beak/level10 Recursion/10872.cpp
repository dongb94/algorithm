// https://www.acmicpc.net/problem/10872
// 팩토리얼

#include <iostream>

int Factorial(int N)
{
    if(N==0) return 1;

    return N*Factorial(N-1);
}

int main(void)
{
    int N;

    scanf("%d",&N);

    printf("%d", Factorial(N));

    return 0;
}