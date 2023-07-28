#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n,m,ans=0;

char board[602][602];
bool vis[602][602]={0,};

int main(void) {
    cin >> n >> m;
    queue<pair<int,int>> Q;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board[i][j];
            if(board[i][j]=='I') {
                vis[i][j]=1;
                Q.push({i,j});
            }
        }
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(board[nx][ny]=='X' || vis[nx][ny]) continue;
            if(board[nx][ny]=='P') ans++;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    //for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout << vis[i][j];}
    if(ans == 0) cout << "TT";
    else cout << ans;
}