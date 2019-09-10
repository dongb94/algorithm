#include <string>
#include <vector>

using namespace std;

string to124(int n){
    string answer = "";
    if(n<=0) return answer;
    switch(n%3){
        case 0 :
            answer = to124(n/3 - 1) + "4";
            break;
        case 1:
            answer = to124(n/3) + "1";
            break;
        case 2:
            answer = to124(n/3) + "2";
            break;
    }
    return answer;
}

string solution(int n) {
    return to124(n);
}