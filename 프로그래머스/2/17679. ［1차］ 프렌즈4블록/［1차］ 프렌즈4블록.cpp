#include <string>
#include <vector>

using namespace std;

int N, M;
int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};

bool Check(int x, int y, const vector<string>& board) {
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= N || ny >= M || board[x][y] != board[nx][ny]) 
            return false;
    }
    return true;
}

int DeleteBlocks(vector<pair<int, int>>& blocks, vector<string>& board) {
    int count = 0;
    for (const auto& [x, y] : blocks) {
        if (board[x][y] != '.') {
            board[x][y] = '.';
            count++;
        }
        for (int i = 0; i < 3; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (board[nx][ny] != '.') {
                board[nx][ny] = '.';
                count++;
            }
        }
    }
    return count;
}

void ArrangeBoard(vector<string>& board) {
    for (int j = 0; j < M; j++) {
        int emptyRow = N - 1;
        for (int i = N - 1; i >= 0; i--) {
            if (board[i][j] != '.') {
                if (i != emptyRow) {
                    board[emptyRow][j] = board[i][j];
                    board[i][j] = '.';
                }
                emptyRow--;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    N = m, M = n;
    int answer = 0;
    
    while (true) {
        vector<pair<int, int>> blocks;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                if (board[i][j] != '.' && Check(i, j, board)) {
                    blocks.emplace_back(i, j);
                }
            }
        }
        
        if (blocks.empty()) break;
        
        answer += DeleteBlocks(blocks, board);
        ArrangeBoard(board);
    }
    
    return answer;
}