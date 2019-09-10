// https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    if(n==0) return answer;
    int rest = n%3;
    answer = solution((n-1)/3) + "412"[rest];
    return answer;
}