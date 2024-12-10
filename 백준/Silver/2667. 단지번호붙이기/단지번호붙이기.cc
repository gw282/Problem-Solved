//=====================================================================
//   2667번:    단지번호붙이기                   
//   @date:   2024-12-10              
//   @link:   https://www.acmicpc.net/problem/2667  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0}; // 우, 하, 좌, 상
int dy[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int t;

int bfs(int startX, int startY,vector<vector<int>> &board, vector<vector<bool>> &vis) {
  int count = 0;
  queue<pair<int, int>> q;
  vis[startX][startY] = true;
  q.push({startX,startY});

  while(!q.empty()) {
    count++;
    pair<int, int> cur = q.front();
    q.pop();

    for(int dir=0;dir<4;dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || nx >= t || ny < 0 || ny >= t) continue;
      if(vis[nx][ny] || board[nx][ny] == 0) continue;

      vis[nx][ny] = true;
      q.push({nx,ny});
    } 
  }
  return count;
}

int main() {
	cin >> t;

  vector<vector<int>> board(t, vector<int>(t, 0));
  vector<vector<bool>> vis(t, vector<bool>(t, false));

  vector<int> house;
  for(int i=0;i<t;i++) {
    string s;
    cin >> s;
    for(int j=0;j<s.length();j++) {
      if(s[j] == '1') board[i][j] = 1;
    }
  }
  
  for(int i=0;i<t;i++) {
    for(int j=0;j<t;j++) {
      if(board[i][j] == 0 || vis[i][j]) continue;

      house.push_back(bfs(i,j,board,vis));
    }
  }
  
  cout << house.size() << '\n';
  sort(house.begin(),house.end());
  for(int i=0;i<house.size();i++) {
    cout <<house[i] << '\n';
  }
  return 0;
}
