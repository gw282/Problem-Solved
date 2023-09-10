/*
[2023-09-10 15681 트리와 쿼리]
dfs를 통해 부분트리를 순회하고(재귀)
dp를 통해 정점마다 서브트리에 속한 정점의 수를 누적해 저장함
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r, q;

bool vis[100002];
int dp[100002];
vector <int> arr[100002];

int dfs(int cur) {
    if(vis[cur]) return dp[cur]; // 방문한 값이면 skip
    vis[cur] = true;

    for(auto nxt : arr[cur]) {
        if(vis[nxt]) continue; // 방문한 값이면 skip
        dp[cur] = dfs(nxt) + dp[cur]; // 방문하지 않았다면 정점 아래의 정점 개수를 더해줌
    } 
    return dp[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int u, v, ver;

    cin >> n >> r >> q;

    for(int i=1;i<n;i++) {
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        dp[i] = 1; // 배열 1로 초기화
    }

    dfs(r);

    while(q--) {
        cin >> ver;
        cout << dp[ver] << '\n';
    }
}
