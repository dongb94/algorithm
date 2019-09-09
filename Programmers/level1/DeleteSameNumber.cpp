#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int temp = -1;
    vector<int> answer;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] == temp) continue;
        temp = arr[i];
        answer.push_back(arr[i]);
    }

    return answer;
}