//=====================================================================
//   6593번:    상범 빌딩                   
//   @date:   2024-12-13              
//   @link:   https://www.acmicpc.net/problem/6593  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define Z get<0>
#define Y get<1>
#define X get<2>
#define dist get<3>

int L,R,C;

int dx[6] = {1, -1, 0, 0, 0, 0};  // 동, 서, 남, 북, 상, 하
int dy[6] = {0, 0, 1, -1, 0, 0};  // 동, 서, 남, 북, 상, 하
int dz[6] = {0, 0, 0, 0, 1, -1};  // 동, 서, 남, 북, 상, 하

char board[32][32][32];
bool vis[32][32][32];

int bfs(tuple<int,int,int> S, tuple<int,int,int> E) {

  queue<tuple<int,int,int,int>> q;
  vis[Z(S)][Y(S)][X(S)] = true;
  q.push({Z(S),Y(S),X(S),0});

  while(!q.empty()) {

    tuple<int,int,int,int> cur = q.front();
    q.pop();

    if(Z(cur)==Z(E) && Y(cur)==Y(E) && X(cur)==X(E)) return dist(cur); // 탈출시 거리 반환

    for(int dir=0;dir<6;dir++) {
      int nz = Z(cur) + dz[dir];
      int ny = Y(cur) + dy[dir];
      int nx = X(cur)+ dx[dir];

      if(nx<0 || nx >=C || ny<0 || ny >= R || nz<0 || nz >= L) continue;
      if(board[nz][ny][nx] == '#' || vis[nz][ny][nx]) continue;

      vis[nz][ny][nx] = true;
      q.push({nz,ny,nx,get<3>(cur)+1});
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1) {
    cin >> L >> R >> C;
      
    if(L == 0 && R == 0 && C == 0) return 0;

    tuple<int,int,int> S;
    tuple<int,int,int> E;

    // board, vis 초기화
    for(int i=0;i<32;i++) {
      for(int j=0;j<32;j++) {
        for(int k=0;k<32;k++) {
                board[i][j][k] = 0;
                vis[i][j][k] = false;
            }
        }
    }

    for(int i=0;i<L;i++) {
      for(int j=0;j<R;j++) {
        for(int k=0;k<C;k++) {
          cin >> board[i][j][k];
          if(board[i][j][k] == 'S') {
            S = make_tuple(i, j, k);
          }
          if(board[i][j][k] == 'E') {
            E = make_tuple(i, j, k);
          }
        }
      }
    }
    
    int result = bfs(S,E);
    //거리 0이면 trapped, 아니면 dist 출력
    if(result) cout << "Escaped in " << result << " minute(s).\n";
    else cout << "Trapped!\n";
  }
  
  return 0;
}
