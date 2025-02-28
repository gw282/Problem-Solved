#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int arr[n][m];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            arr[i][j] = 0;
        }
    }
    
    for(auto p : puddles) {
        arr[p[1]-1][p[0]-1] = -1;
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (arr[i][j] == -1) arr[i][j] = 0;
            else if(i == 0 && j == 0) arr[i][j] = 1;
            else if(i == 0) arr[i][j] = arr[i][j-1];
            else if(j == 0) arr[i][j] = arr[i-1][j];
            else arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 1000000007;
        }
    }

    answer = arr[n-1][m-1];
    return answer;
}