//=====================================================================
//   2468번:    안전 영역                   
//   @date:   2024-12-12              
//   @link:   https://www.acmicpc.net/problem/2468  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define X first
#define Y second

int t;
int dx[4] = {1, 0, -1, 0}; // 우, 하, 좌, 상
int dy[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상

int board[102][102] = {0,};
bool vis[102][102] = {false,};
vector<int> res;

int bfs(int x, int y, int count) {
  int area = 0;
  queue<pair<int, int>> q;
  vis[x][y] = true;
  q.push({x,y});

  while(!q.empty()) {
    area++;
    pair<int,int> cur = q.front();
    q.pop();

    for(int dir=0;dir<4;dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx<0 || nx>=t || ny<0 || ny>=t) continue;
      if(vis[nx][ny] || board[nx][ny] <= count) continue;

      vis[nx][ny] = true;
      q.push({nx,ny});
    }
  }
  return area;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int count = 0,max_areas = 0;
	cin >> t;

  for(int i=0;i<t;i++) {
    for(int j=0;j<t;j++) {
      cin >> board[i][j];
      count = max(count, board[i][j]);
    }
  }

  for(int k=0;k<=count;k++) {
    vector<int> v;
    memset(vis, false, sizeof(vis));
    int safe_areas = 0;
    for(int i=0;i<t;i++) {
      for(int j=0;j<t;j++) {
        if(board[i][j] <= k || vis[i][j]) continue;

        v.push_back(bfs(i,j,k));
        safe_areas++;
      }
    
    }
    max_areas = max(max_areas,safe_areas);
  }


  cout << max_areas;
  
  return 0;
}
