#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land) {
    int answer = 0;
    
    int rows = land.size();
    int cols = land[0].size();
    
    vector<vector<int>> mx(rows, vector<int>(cols, 0));
    
    // 첫 번째 행 초기화
    mx[0] = land[0];

    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int max_value = 0;
            for(int k = 0; k < cols; k++) {
                if(j != k) max_value = max(max_value, mx[i-1][k]);
            }
            mx[i][j] = max_value + land[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        answer = max(answer, mx[rows - 1][i]);
    }

    return answer;
}