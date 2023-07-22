#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

char board[1002][1002];
int Jh[1002][1002];
int Fire[1002][1002];

int r,c;
int j1,j2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    queue<pair<int,int>> Q;

    for(int i=0;i<r+2;i++) {
        fill_n(Jh[i],c,-1);
        fill_n(Fire[i],c,-1);
    }

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> board[i][j];
            if(board[i][j] == 'J') {
                Jh[i][j] = 0;
                j1 = i; j2 = j;
            }
            else if(board[i][j] == 'F') {
                Fire[i][j] = 0;
                Q.push({i,j});
            }
        }
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir=0;dir<sizeof(dx)/4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(board[nx][ny] == '#' || Fire[nx][ny] >= 0) continue;
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            Fire[nx][ny] = Fire[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }

    Q.push({j1,j2});
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
    
        for(int dir=0;dir<sizeof(dx)/4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=r || ny<0 || ny>=c) {
                cout << Jh[cur.X][cur.Y] + 1; return 0;
            }
            if(board[nx][ny] == '#' || Jh[nx][ny] >= 0) continue;
            if(Fire[nx][ny] !=-1 && Jh[cur.X][cur.Y] + 1 >= Fire[nx][ny]) continue;
            Jh[nx][ny] = Jh[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
}