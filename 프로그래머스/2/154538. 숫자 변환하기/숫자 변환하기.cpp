#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<int, int>> q;
    
    q.push({y, 0});  // y에서 출발, 연산 횟수는 0
    
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // 목표 값 x에 도달하면 그때의 연산 횟수를 반환
        if (current == x) {
            answer = steps;
            break;
        }

        // 세 가지 연산을 시도
        if (current % 3 == 0) {
            q.push({current / 3, steps + 1});
        }
        if (current % 2 == 0) {
            q.push({current / 2, steps + 1});
        }
        if (current - n >= x) {
            q.push({current - n, steps + 1});
        }
    }

    return answer;
}
