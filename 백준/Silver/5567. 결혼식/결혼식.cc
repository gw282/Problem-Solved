/*
[2023-09-04 5567 결혼식]
상근이와의 dist 배열의 값이 1 or 2인 값의 수를 출력함
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, cnt;
vector<int> arr[502];
int dist[502];

void bfs() {
    queue <int> q;

    q.push(1);
    dist[1] +=1; // 상근이의 거리값 = 0

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto nxt : arr[cur]) {
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1; // 해당 사람의 거리에서 +1
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--) {
        int a, b;

        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    fill_n(dist,502,-1);

    cnt = 0;
    bfs();

    for(int i=0;i<502;i++) {
        if(dist[i] == 1 || dist[i] == 2) { 
            // 상근의 친구거나, 친구의 친구인 경우
            cnt++;
        }
    }
    cout << cnt;
}