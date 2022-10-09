// https://www.acmicpc.net/problem/2884
// 알람 시계

#include <iostream>

int main(void)
{
    int hour, minute;
    scanf("%d %d", &hour, &minute);

    if(minute < 45)
    {
        minute = minute + 15;
        if(hour == 0)
        {
            hour = 23;
        }
        else{
            hour--;
        }

        printf("%d %d", hour, minute);
    }
    else
    {
        printf("%d %d", hour, minute - 45);
    }

    return 0;
}
