#include <string>
#include <vector>

using namespace std;

vector<vector<int>> m;

void dfs(int x, int y, int size, vector<int> &answer) {
    bool zero = true, one = true;
    
    for (int i=x; i<x+size;i++) {
        for (int j=y;j<y+size; j++) {
            if (m[i][j] == 0) one = false;
            if (m[i][j] == 1) zero = false;
        }
    }
    
    if (zero) {
        answer[0]++;
        return;
    }
    if (one) {
        answer[1]++;
        return;
    }
    
    int halfsize = size / 2;
    dfs(x, y, halfsize, answer);    
    dfs(x, y + halfsize, halfsize, answer);
    dfs(x + halfsize, y, halfsize, answer);
    dfs(x + halfsize, y + halfsize, halfsize, answer);
}


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    m = arr;
    dfs(0, 0, arr.size(), answer);
    return answer;
}