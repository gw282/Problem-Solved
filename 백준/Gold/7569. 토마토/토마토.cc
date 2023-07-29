#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int board[102][102][102];
int dist[102][102][102];

int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int m,n,h; // x,y,z
int day; // 토마토 익는데 걸리는 날

int main(void) {
    ios::sync_with_stdio(0);    
    cin.tie(0);

    cin >> m >> n >> h;
    queue<tuple<int,int,int>> Q;

    for(int i=0;i<h;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                cin >> board[i][j][k];
                dist[i][j][k] = -1;
                if(board[i][j][k]==1) {
                    dist[i][j][k] = 0;
                    Q.push({i,j,k});
                }
            }
        }
    }
    
    while(!Q.empty()) {
        tuple<int,int,int> cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curZ, curY, curX) = cur;

        for(int dir=0;dir<6;dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];

            if(nx<0 || nx>=m || ny<0 || ny>=n || nz<0 || nz>=h) continue;
            if(board[nz][ny][nx]!=0 || dist[nz][ny][nx]!=-1) continue;
            dist[nz][ny][nx] = dist[curZ][curY][curX]+1;
            Q.push({nz,ny,nx});
        }
    }
    day = 0;
    for(int i=0;i<h;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<m;k++) {
                if(dist[i][j][k]==-1 && board[i][j][k]!=-1)  {
                cout << -1;
                return 0;
                }
                day = max(day, dist[i][j][k]);
            }
        }
    }
    cout << day;
}