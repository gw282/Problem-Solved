//=====================================================================
//   2583번:    영역 구하기                   
//   @date:   2024-12-09              
//   @link:   https://www.acmicpc.net/problem/2583  
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

int n, m, t; // n, m, t: m은 세로 크기, n은 가로 크기, t는 색칠된 영역의 개수
int dx[4] = {1, 0, -1, 0}; // 우, 하, 좌, 상
int dy[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상

// BFS로 영역을 탐색하는 함수
int bfs(int startX, int startY, vector<vector<int>> &board, vector<vector<bool>> &vis) {
    int area = 0;
    queue<pair<int, int>> q;
    vis[startX][startY] = true;
    q.push({startX, startY});

    while (!q.empty()) {
        area++;
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir=0;dir<4;dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue; // 범위 밖으로 나가면 넘어감
            if (vis[nx][ny] || board[nx][ny] == 1) continue; // 이미 방문했거나 색칠된 부분이면 넘어감

            vis[nx][ny] = true; // 방문 처리
            q.push({nx, ny}); // 큐에 넣어 탐색
        }
    }
    return area;
}

// 직사각형 영역을 board에 입력하는 함수
void fillBoard(int x1, int y1, int x2, int y2, vector<vector<int>>& board) {
    for (int i=y1;i<y2;i++) { // 세로 범위
        for (int j=x1;j<x2;j++) { // 가로 범위
            board[i][j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> t;  // m: 세로 크기, n: 가로 크기, t: 색칠된 영역의 개수

    vector<vector<int>> board(m, vector<int>(n, 0)); // m x n 보드
    vector<vector<bool>> vis(m, vector<bool>(n, false)); // 방문 여부 확인

    // 색칠된 영역을 board에 입력
    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fillBoard(x1, y1, x2, y2, board);  // 직사각형 영역
    }

    vector<int> areas; // 각 영역의 넓이를 저장할 벡터

    // BFS로 영역을 탐색
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 || vis[i][j]) continue; // 색칠됐거나 방문한 부분은 건너뛰기

            // (i, j)가 시작점이 되는 새로운 영역
            areas.push_back(bfs(i, j, board, vis));  // BFS 실행하고 넓이 저장
        }
    }

    // 결과 출력
    cout << areas.size() << '\n';  // 영역의 수
    sort(areas.begin(), areas.end());  // 넓이를 오름차순으로 정렬
    for (int area : areas) {
        cout << area << ' ';
    }
}
