#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    int dx[4] = {1, 0, -1, 0}; // x 방향 이동
    int dy[4] = {0, 1, 0, -1}; // y 방향 이동

    queue<pair<int, int>> Q;
    vis[0][0] = true; // 시작 지점 방문 처리
    Q.push({0, 0});
    int answer = 1;
 
    while (!Q.empty()) {
        int size = Q.size(); // 현재 레벨의 크기
        
        for (int i = 0; i < size; i++) {
            pair<int, int> cur = Q.front(); Q.pop();
            
            // 목표 지점에 도달했는지 확인
            if (cur.first == n - 1 && cur.second == m - 1) {
                return answer; // 도달 시 이동 단계 반환
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                // 범위 검사 및 방문 여부, 유효한 셀인지 확인
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (vis[nx][ny] || maps[nx][ny] == 0) continue; // 0은 장애물

                vis[nx][ny] = true; // 셀 방문 처리
                Q.push({nx, ny}); // 큐에 새 위치 추가
            }
        }
        
        answer++; // 한 단계 이동
    }

    return -1; // 목표 지점에 도달할 수 없는 경우 -1 반환
}
