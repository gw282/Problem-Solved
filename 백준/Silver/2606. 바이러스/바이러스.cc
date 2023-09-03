/*
[2023-09-03 2606 바이러스]
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,cnt;
vector <int> arr[102];
bool vis[102];

int bfs() {
    queue <int> q;

    cnt = 0;
    q.push(1);
    vis[1] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for(auto nxt : arr[cur]) {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    if(cnt == 0) return 0;
    return cnt-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;

    cin >> n >> m;

    while(m--) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    cout << bfs();
}