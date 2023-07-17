#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second //pair에서 first, second를 줄여서 사용
int board[502][502] = {0,}; //1이 파란 칸, 0이 빨간 칸
bool vis[502][502]; //해당 칸 방문여부 저장
int n,m; //n=행의 수, m=열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> n >> m;
	for(int i=0;i<n;i++) {
		for(int j=0; j<m;j++) {
			cin >> board[i][j];
		}
	}
	int mx=0; //그림의 최댓값
	int num=0; //그림의 수

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(board[i][j]==0 || vis[i][j]) continue;
			num++;

			queue<pair<int,int>> Q;
			vis[i][j] = 1; //(i,j)을 방문했다고 명시
			Q.push({i,j}); //큐에 (i,j) 삽입
			int area=0;
			while(!Q.empty()) {
				area++;
				pair<int,int> cur = Q.front();
				Q.pop();
				for(int dir=0; dir<4; dir++) { //상하좌우 칸 탐색
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir]; //nx,ny에 dir에서 정한 방향의 인접한 칸의 좌표 삽입
					if( nx<0 || nx>=n || ny<0 || ny>=m) continue; //범위 밖일 경우 패스
					if(vis[nx][ny] || board[nx][ny]!=1) continue; //방문한 칸이거나 파란칸이 아닌 경우 패스
					vis[nx][ny]=1; //(nx,ny)를 방문했다고 명시
					Q.push({nx,ny});
				}
			}
			mx =max(mx, area);
		}
	}
	cout << num << '\n' << mx;
	return 0;
}