#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[51][51]={0,}; //1: 배추O, 0: 배추X
bool vis[51][51]; //해당 칸 방문 여부 저장

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int t,m,n,k; //t: 테스트 케이스 수, m:열의 수, n:행의 수, k:위치 개수
int worm;

queue<pair<int,int>> Q;

void bfs(int x, int y) {
        vis[x][y] = 1;
        Q.push({x,y});
        while(!Q.empty()) {
            pair<int,int> cur = Q.front();
            Q.pop();

            for(int dir=0;dir<4;dir++) { //상하좌우 칸 탐색(하부터)
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(vis[nx][ny] || board[nx][ny]!=1) continue;
                vis[nx][ny]=1; //(nx,ny) 방문
                Q.push({nx,ny});
            }
        }    
    }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while(t--) {

        cin >> m >> n >> k;
        int x, y; //x: 열 위치, y: 행 위치
        for(int i=0;i<k;i++) {
            cin >> x >> y;
            board[y][x] = 1; //배추O인 위치 1로 변경
        }
        worm = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==1 && !vis[i][j]) {
                    bfs(i,j);
                    worm++;
                }
            }
        }
        cout << worm << '\n';
        for(int i = 0; i < n; i++){ //초기화
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m, 0);
    }
    }
    return 0;
}