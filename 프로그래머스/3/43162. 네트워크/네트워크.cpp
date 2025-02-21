#include <string>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& computers, vector<bool>& vis, int n) {
    vis[node] = true;
    for(int i=0;i<n;i++) {
        if(computers[node][i] && !vis[i]) {
            dfs(i, computers, vis, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> vis(n, false);

    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i, computers, vis, n);
            answer++;
        }
    }

    return answer;
}
