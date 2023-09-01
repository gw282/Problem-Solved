/*
[2023-09-01 11724 연결 요소의 개수]
연결 요소: 그래프의 개수
bfs 방식으로 해결: 정점 1부터 n까지 그래프가 몇 개 만들어지는지 확인
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, cnt = 0; // n: 정점의 개수, m: 간선의 개수
vector <int> arr[1002];
bool vis[1002];

void bfs() {
    queue <int> q;

    for(int i=1;i<=n;i++) { // 정점 1~n까지
        if(vis[i]) continue;
        q.push(i);
        vis[i] = true;
        cnt++; // 하나의 이어진 그래프 발견
        
        while(!q.empty()){ // 이어진 정점을 모두 true 전환
            int cur = q.front();
            q.pop();

            for(int i : arr[cur]) { // arr[cur] 배열의 각 값을 순서대로 순회
                if(vis[i]) continue;
                q.push(i);
                vis[i] = true;
            }
        }  
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int u, v;

    cin >> n >> m;

    while(m--) {
        cin >> u >> v;
        
        arr[u].push_back(v); // 방향 없는 그래프
        arr[v].push_back(u);
    }
    bfs();
    cout << cnt;
}