/*
[2023-09-06 2660 회장뽑기]

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, score, candidate;
vector <int> arr[52];
vector <int> v;
vector <int> res;
int dist[52];

int bfs(int i) {
    queue <int> q;

    q.push(i);
    dist[i] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto nxt : arr[cur]) {
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    return *max_element(dist+1,dist+n+1); // 거리 배열 중 가장 큰 값 return
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a=0, b=0;

    cin >> n;

    while(a!=-1 && b!=-1) {
        cin >> a >> b;
        
        arr[a].push_back(b);
        arr[b].push_back(a);
    }       

    for(int i=1;i<=n;i++) {
        fill_n(dist,n+1,-1); // 거리 배열 -1로 초기화
        v.push_back(bfs(i));
    }

    score = *min_element(v.begin(),v.end()); // 저장한 값 중 가장 작은 값
    candidate = 0;

    for(int i=0;i<v.size();i++) {
        if(v[i] == score) {
            candidate++; // 가장 작은 값인 경우 후보수 ++
            res.push_back(i); // 후보자 번호 출력을 위해 vector에 push
        }
    }

    cout << score << ' ' << candidate << '\n';
    for(int i=0;i<res.size();i++) { // vector 배열 전부 출력(오름차순으로 정렬이 되어있음)
        cout << res[i]+1 << ' ';
    }
}