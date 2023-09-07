/*
[2023-09-07 11725 트리의 부모 찾기]
p 배열을 통해 해당 노드의 부모 노드 값을 저장해 둠
cur의 부모 노드가 이미 있다면 skip
cur의 부모 노드가 없다면 큐에서 꺼낸 cur이 해당 노드의 부모
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int p[100002]; // 부모 노드를 저장
vector <int> arr[100002];

void bfs(int i) {
    queue <int> q;

    q.push(i);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto nxt : arr[cur]) {
            // nxt 노드는 자식일수도, 부모일수도 있음
            // if문이 성립하면 nxt는 cur의 부모 노드
            if(p[cur] == nxt) continue;
            // 부모의 노드를 못찾은 경우
            q.push(nxt);
            p[nxt] = cur; // cur 값이 nxt 노드의 부모가 됨 
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++) {
        int a, b;

        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    bfs(1);

    for(int i=2;i<=n;i++) { // 2번 노드부터 n번 노드까지 출력
        cout << p[i] << '\n';
    }
}