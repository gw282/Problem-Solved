/*
[2023-07-23 10026 적록색약]
bfs를 두 번 사용해야 하는 문제이므로, bfs 함수를 따로 만드는 것이 좋음(그렇지 않으면 코드 반복이 발생함)
색깔 개수를 세는 코드도 중복되서 사용하므로, 카운팅 함수를 만드는 것이 좋음(카운팅 함수 안에 bfs 함수 포함시키면 됨)
적록색약X일 때 한 번, G=>R로 바꾸고 방문 배열 초기화 한뒤 적록색약O일 때 한 번 수행하면 됨
vis[i][j]==0이라는 뜻은 새로운 색이라는 뜻 == cnt(카운트 값)를 1 증가시켜줌
*/
#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

char board[102][102]; //1차: 적록색약이 아닐때, 2차: 적록색약일 때
bool vis[102][102] = {0,}; // 방문 배열 0으로 초기화
int n;
int cnt1; //적록색약X
int cnt2; //적록색약O


void bfs(int i, int j) {
    queue<pair<int,int>> Q;
    vis[i][j] = 1;
    Q.push({i,j});

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int dir=0;dir<sizeof(dx)/4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(board[nx][ny]!=board[cur.X][cur.Y] || vis[nx][ny]==1) continue;
            vis[nx][ny]=1;
            Q.push({nx,ny});
        }
    }
}

int num() {
    int cnt = 0;
    for(int i=0;i<n;i++) { 
        for(int j=0;j<n;j++) {
            if(vis[i][j] == 1) continue;
            cnt++;
            bfs(i,j);
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) { //적록색약이 아닌 경우
        for(int j=0;j<n;j++) {
            cin >> board[i][j];
        }
    }
    cnt1 = num();

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) { // 적록색약인 경우
            if(board[i][j]=='G') board[i][j] = 'R'; // G=>R로 변경 
            vis[i][j] = 0; // 방문 배열 초기화
        }
    }
    cnt2 = num();

    cout << cnt1 << ' ' << cnt2;
}