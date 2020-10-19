#include <hash_map>
#include <string>
#include <vector>

using namespace std;
using namespace stdext;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    hash_map<string,int> map;
    for(string s : participant){
        if(map.find(s)==null) 
            map.insert(pair(s,1));
        else
            (*map.find(s)).second++;
    }

    return answer;
}