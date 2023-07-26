/* 
[2023-07-26 5427 불]
dist 배열을 2개 생성하여 하나는 상근의 dist, 하나는 불의 dist 계산
최종위치의 dist 배열을 출력하면 누적 이동횟수가 저장되어 있음
테스트 케이스 시작시 행렬 크기만큼 dist 배열을 -1로 초기화
불에 대한 bfs, 상근에 대한 bfs 각각 생성
if(nx<0 || nx>=r || ny<0 || ny>=c) => 상근이 범위에서 벗어나 경우 탈출 성공이라는 의미!
if(Fire[nx][ny] !=-1 && Jh[cur.X][cur.Y] + 1 >= Fire[nx][ny]) 
=> 불이 도달하지 않은 위치의 경우 상근의 거리값이 항상 -1보다 크므로 불이 도달한 위치라는 조건을 꼭 넣어야 함
테스트 케이스를 계속 입력받아야하므로 탈출한 경우 즉시 종료가 아닌
escape 변수를 활용해 탈출한 경우 escape=1, 아닌 경우 escape=0으로 설정함
*/
#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

char board[1002][1002];
int sg[1002][1002];
int fire[1002][1002];

int n, escape; // 테스트 회수 변수
int w, h, sg1, sg2; // 열, 행, 상근 시작지점 변수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--) {
        cin >> w >> h;

        escape = 0;
        queue<pair<int,int>> Q;

        for(int i=0;i<h;i++) {
            fill_n(sg[i],w,-1); // 행렬 크기만큼 -1로 초기화
            fill_n(fire[i],w,-1);
        }

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> board[i][j];
                if(board[i][j] == '*') {
                    Q.push({i,j});
                    fire[i][j] = 0;
                }
                if(board[i][j] == '@') {
                    sg1 = i;
                    sg2 = j;
                }
            }
        }

        while(!Q.empty()) {
            pair<int,int> cur = Q.front();
            Q.pop();

            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if(board[nx][ny]=='#' || fire[nx][ny]>=0) continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }

        Q.push({sg1,sg2});
        sg[sg1][sg2] = 0;

        while(!Q.empty() && (!escape)) {
            pair<int,int> cur = Q.front();
            Q.pop();

            for(int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx<0 || nx>=h || ny<0 || ny>=w) {
                    cout << sg[cur.X][cur.Y] + 1 << '\n';
                    escape = 1;
                    break;
                }
                if(fire[nx][ny] !=-1 && sg[cur.X][cur.Y]+1 >= fire[nx][ny]) continue;
                if(board[nx][ny]=='#' || sg[nx][ny]>=0) continue;
                
                sg[nx][ny] = sg[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
        if(!escape) cout << "IMPOSSIBLE" << '\n'; 
    }
}