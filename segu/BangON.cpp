#include <iostream>
#include <map>

int main()
{
    int N;
    scanf("%d", &N);
    
    std::map<long long, long long> schedule;
    for(int i=0; i<N; i++)
    {
        long long start, end;
        scanf("%lld %lld", &start, &end);

        auto endTime = schedule.find(end);
        if(endTime == schedule.end())
        {
            schedule.emplace(end, start);
        }
        else
        {
            if(schedule[end] < start)
            {
                schedule[end] = start;
            }
        }
    }

    long long end=0;
    int count=0;
    for(auto t : schedule)
    {
        //printf(" -> %lld~%lld (%lld>=%lld?%d)\n", t.second, t.first, t.second, end, t.second>=end);
        if(t.second >= end)
        {
            //printf(" [%lld~%lld]\n", t.second, t.first);
            count++;
            end = t.first;
        }
    }
    
    printf("%d", count);

    return 0;
}