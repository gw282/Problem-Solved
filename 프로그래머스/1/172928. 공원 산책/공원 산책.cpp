#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = -1, y = -1;

    // 시작점 찾기
    // park에서 'S'의 위치를 찾고, 해당 좌표를 (x, y)로 설정
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == 'S') {
                y = i; // y 좌표 설정
                x = j; // x 좌표 설정
                break; // 'S'를 찾았으므로 더 이상 탐색할 필요 없음
            }
        }
        if (y != -1) break; // 'S'를 찾으면 반복문 종료
    }

    // 루트대로 이동하기
    // 주어진 루트를 따라 이동하면서 장애물과 공원을 벗어나는지 체크
    for (const string& route : routes) {
        char op = route[0]; // 이동 방향 (N, S, W, E)
        int n = route[2] - '0'; // 이동 거리 (문자에서 정수로 변환)

        int new_x = x; // 이동 후의 x 좌표
        int new_y = y; // 이동 후의 y 좌표
        bool can_move = true; // 이동 가능 여부

        // 주어진 거리만큼 이동하면서 장애물 확인
        for (int i = 0; i < n; i++) {
            if (op == 'N') { // 북쪽으로 이동
                if (new_y - 1 < 0 || park[new_y - 1][new_x] == 'X') {
                    can_move = false; // 장애물이 있거나 경계를 넘어서는 경우
                    break; // 더 이상 이동하지 않음
                }
                new_y--; // 이동
            } else if (op == 'S') { // 남쪽으로 이동
                if (new_y + 1 >= park.size() || park[new_y + 1][new_x] == 'X') {
                    can_move = false;
                    break;
                }
                new_y++; // 이동
            } else if (op == 'W') { // 서쪽으로 이동
                if (new_x - 1 < 0 || park[new_y][new_x - 1] == 'X') {
                    can_move = false;
                    break;
                }
                new_x--; // 이동
            } else if (op == 'E') { // 동쪽으로 이동
                if (new_x + 1 >= park[0].size() || park[new_y][new_x + 1] == 'X') {
                    can_move = false;
                    break;
                }
                new_x++; // 이동
            }
        }

        // 이동이 가능하면 새로운 좌표로 업데이트
        if (can_move) {
            x = new_x;
            y = new_y;
        }
    }

    answer.push_back(y); // y 좌표 추가
    answer.push_back(x); // x 좌표 추가
    return answer;
}
