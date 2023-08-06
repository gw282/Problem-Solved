/*
[2023-08-06 15683 감시]
1. 배열을 입력받는다 
- 1-1.cctv가 위치한 좌표를 모두 vector에 push_back함 / 1-2. 좌표값이 0인 좌표를 카운팅함
2. 모든 경우의 수 4^cctv개수만큼 탐색을 해야한다(한 개의 cctv 경우의 수가 가장 많은 경우가 4이므로) 
- 2-1. 변경되는 board2 값을 board1으로 재입력 / 2-2. 4로 나누면서 해당 cctv의 
*/
#include <iostream>
#include <vector>
#include <tuple> // tie
using namespace std;

#define X first
#define Y second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n,m;
int board1[10][10]; // 값을 입력받을 배열
int board2[10][10]; // 사각지대 개수 카운트를 위한 배열
vector<pair<int,int>> cctv; // cctv의 좌표를 저장

bool oob(int x, int y) { // 범위 벗어났는지 확인(벗어나면 true, 아니면 false 반환)
    return x<0 || x>=n || y<0 || y>=m;
}

//dir 방향으로 진행하며 지나는 좌표를 7로 변경
void func(int x, int y, int dir) { // 벽이나 범위를 벗어나기 전까지 해당 방향의 끝까지 진행
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(oob(x,y) || board2[x][y]==6) return; // 범위 벗어나거나 벽을 만나면 return
        if(board2[x][y]!=0) continue; // cctv가 있는 좌표인 경우 건너뛰기
        board2[x][y] = 7; // 값이 0인 좌표를 7로 변경
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int cnt = 0; // 사각지대 개수

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> board1[i][j];
            if(board1[i][j]!=0 && board1[i][j]!=6) { // cctv나 벽이 아닌 경우
                cctv.push_back({i,j}); // 벡터에 push
            }
            else cnt++; // 값이 0인 경우 모두 카운팅
        }
    }
    // '1<<(2*cctv.size())' == '4의 cctv.size()승'
    for(int tmp=0;tmp<(1<<(2*cctv.size()));tmp++) { // tmp를 4진법으로 두고 각 자리수를 cctv 방향으로 고려
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                board2[i][j]=board1[i][j]; // 계속 값이 변경되는 board2에 board1 값 넣기 
            }
        }
        // x,y: cctv의 좌표, dir: cctv가 나아가는 방향
        int brute = tmp; // tmp 값을 저장,변형하기 위한 변수(4진법)
        for(int i=0;i<cctv.size();i++) { // 4진법인 수를 해체
            int dir = brute % 4; // ex) tmp = 39 = 2*(4^2) + 1*(4^1) + 3*(4^0) 
                                 // => 2, 1, 3이 cctv의 방향이다(추후에 4로 나뉘어진 나머지를 사용)
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            //tie(x,y) = cctv[i]; // cctv 좌표를 x,y에 입력

            if(board1[x][y]==1) {
                func(x,y,dir);
            }
            else if(board1[x][y]==2) {
                func(x,y,dir);
                func(x,y,dir+2);
            }
            else if(board1[x][y]==3) {
                func(x,y,dir);
                func(x,y,dir+1);
            }
            else if(board1[x][y]==4) {
                func(x,y,dir);
                func(x,y,dir+1);
                func(x,y,dir+2);
            }
            else { // board1[x][y]==5
                func(x,y,dir);
                func(x,y,dir+1);
                func(x,y,dir+2);
                func(x,y,dir+3);
            }
        }
        int val = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                val += (board2[i][j]==0); // 사각지대 좌표 카운팅
            }
        }
        cnt = min(cnt, val); // 최솟값 산출
    }
    cout << cnt;
}