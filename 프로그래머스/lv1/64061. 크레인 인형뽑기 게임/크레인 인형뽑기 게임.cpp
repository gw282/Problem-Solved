#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int b[30][30];
    
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            b[i][j]=board[i][j];
        }
    }
    stack<int> s;
    for(int i=0;i<moves.size();i++) {
        int col = 0;
        while(!b[col][moves[i]-1]) {
            col++;
        }
        int pick = b[col][moves[i]-1];
        b[col][moves[i]-1] = 0;
        
        if(!s.empty() && s.top() == pick) {
            s.pop();
            answer += 2;
        }
        else s.push(pick);
    }
    return answer;
}