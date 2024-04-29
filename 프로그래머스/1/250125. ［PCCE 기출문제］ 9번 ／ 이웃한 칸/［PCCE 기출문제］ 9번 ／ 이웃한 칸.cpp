#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string color = board[h][w];

    if(h-1 >=0 && color == board[h-1][w] ) answer++;
    
    if(h+1 <board.size() && color == board[h+1][w]) answer++;
    
    if(w-1 >=0 && color == board[h][w-1]) answer++;
    
    if(w+1 <board.size() && color == board[h][w+1] ) answer++;

    return answer;
}