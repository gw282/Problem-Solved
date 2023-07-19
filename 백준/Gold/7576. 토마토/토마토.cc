#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];

int n,m;
int day,st1,st2;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;

    queue<pair<int,int>> Q;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
            if(board[i][j]==1) {
                Q.push({i,j}); //스타트 지점 큐에 push
            }
            if(board[i][j]==0) {
                dist[i][j]=-1; //안익은 토마토 좌표에 대한 거리 -1로 설정
            } 
        }
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); 
        Q.pop();

        for(int dir = 0; dir < 4; dir++){ 
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue; // 범위 밖일 경우 넘어감
            if(dist[nx][ny]>=0) continue; // 토마토 좌표가 스타트 지점과 이어져 있지 않은 경우 넘어감 
            dist[nx][ny] = dist[cur.X][cur.Y]+1; // 스타트 지점에서 (nx, ny)까지의 거리 계산
            Q.push({nx,ny});
        }
    }
    day=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dist[i][j]==-1) {  //토마토가 모두 익지 않았을 경우
                cout << -1;
                return 0;
            }
            day = max(day, dist[i][j]); //익은 날짜의 최소값을 비교
        }
    }
    cout << day;
    return 0;
}