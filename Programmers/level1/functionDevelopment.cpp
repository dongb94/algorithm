// https://programmers.co.kr/learn/courses/30/lessons/42586?language=cpp

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day =0;
    for(int i=0; i<progresses.size();){
        int count = 0;
        day = (100 - progresses[i])/speeds[i];
        if((100 - progresses[i])%speeds[i]!=0) day++;
        while(progresses[i]+speeds[i]*day >= 100){
            count++;
            i++;
            if(i==progresses.size())break;
        }
        answer.push_back(count);
    }
    return answer;
}