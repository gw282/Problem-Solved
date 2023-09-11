    /*
    [2023-09-11 1240 노드 사이의 거리]
    노드 간의 거리 값을 추가적으로 저장
    pair 사용법
    1)
    pair<int, int> front = q.front();
    int cur = front.first;
    int dist = front.second;
    2)
    for(auto nxt_pair : arr[cur]) {
        int nxt = nxt_pair.first;
        int nxtdist = nxt_pair.second;
    }
    */
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <algorithm>

    using namespace std;

    int n,m,num1,num2;
    bool vis[1002];
    vector <pair<int, int>> arr[1002];

    void bfs(int i, int dis) { 
        queue <pair<int, int>> q;
        q.push({i, dis});
        vis[i] = true;

        while(!q.empty()) {
            pair<int, int> front = q.front();
            int cur = front.first;
            int dist = front.second;
            q.pop();   

            if(cur == num2) { // 현재 노드가 도착 노드와 같은 경우
                cout << dist << '\n';
                return;
            } 

            for(auto nxt_pair : arr[cur]) {
                int nxt = nxt_pair.first;
                int nxtdist = nxt_pair.second;

                if(vis[nxt]) continue;
                vis[nxt] = true;
                q.push({nxt, dist+nxtdist}); // 거리를 누적한 뒤 다시 push
            }
        }
    }

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int u,v,dist;

        cin >> n >> m;

        for(int i=1;i<n;i++) {
            cin >> u >> v >> dist;
            arr[u].push_back({v,dist});
            arr[v].push_back({u,dist});
        }

        while(m--) {
            fill_n(vis,n+1,false); // 방문 배열 초기화

            cin >> num1 >> num2; 
            
            bfs(num1, 0); // 시작 노드, 거리 반환
        }
    }