#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> basket;
    
    for(int i=0; i<moves.size(); i++){
        int line = moves[i]-1;
        int next = 0;
        for(int j=0; j<board.size(); j++){
            if(board[j][line]!=0){
                next = board[j][line];
                board[j][line] = 0;
                break;
            }
        }
        cout << next <<endl;
        if(next == 0) continue;
        
        if(basket.empty())
            basket.push(next);
        else{
            int pro = basket.top();
            if(pro == next) {
                basket.pop();
                answer+=2;
            }
            else{
                basket.push(next);
            }
        }
    }
    cout << "basket size : " <<basket.size();
    
    for(int i=basket.size();i>0;i--){
        int org = basket.top();
        basket.pop();
        cout << org;
    }
    
    return answer;
}
