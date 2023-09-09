/*
[2023-09-09 4803 트리]
dfs를 활용: 인자로 현재 노드와 부모 노드를 받음
1)인접 벡터 배열을 살펴보며 부모 노드면 skip 
2)이미 방문한 노드(vis배열을 통해)이면 사이클 발생 -> tree X임을 체크(flag 활용)하고 skip
3)cur이 nxt의 부모였던 것임

새로운 테스트 케이스가 주어지면
tree 개수, vis 방문배열, arr 인접 행렬 초기화
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, cnt, t;
vector <int> arr[502];
bool vis[502];
bool flag;

void dfs(int cur, int par) {
    for(auto nxt : arr[cur]) {
        if(nxt == par) continue; // 부모 노드이면 스킵
        if(vis[nxt]) { 
            // 이미 방문한 노드를 방문한다는 것은 사이클이 발생했음을 의미
            flag = false; // 트리X
            continue;
        }
        vis[nxt] = true;
        dfs(nxt, cur); // cur : nxt의 부모 노드
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cnt = 0;
    
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;

        cnt++; // case 값 증가
        t = 0; // t값 초기화
        fill_n(vis,n+1,false); // 방문 배열 초기화

        for(int i=0;i<=n;i++) { // 인접행렬 초기화
            while(!arr[i].empty()) {
                arr[i].pop_back();
            }
        }

        while(m--) {
            cin >> a >> b;
            
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for(int i=1;i<=n;i++) {
            if(vis[i]) continue; // 이미 트리 구성에 사용된 노드는 skip
            vis[i] = true;
            flag = true;

            dfs(i, -1);
            if(flag) t++; // 트리인 경우 t++
        }

        cout << "Case " << cnt << ": ";
        if(t > 1) cout << "A forest of " << t << " trees.";
        else if(t == 1) cout << "There is one tree.";
        else if(t == 0) cout << "No trees.";
        cout << '\n';
    }
}