/*
[2023-09-05 11403 경로 찾기]
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int arr[102][102]; 
bool vis[102]; // 

vector <int> v[102];

void dfs(int i) { // dfs
    stack <int> s;

    s.push(i);

    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        for(auto nxt : v[cur]) {
            if(vis[nxt]) continue;
            s.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;

    cin >> n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> num;
            if(num == 1) {
                v[i].push_back(j);
            }
        }
    }

    for(int i=0;i<n;i++) {
        fill_n(vis,n,false); // 방문 배열 false로 초기화
        dfs(i);
        for(int j=0;j<n;j++) {
            if(vis[j]) { // 방문 배열이 true인 경우
                arr[i][j] = 1; // arr 배열을 1로 바꿈
            }
        }
    }

    for(int i=0;i<n;i++) { // 배열 출력
        for(int j=0;j<n;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}