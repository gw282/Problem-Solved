#include <string>
#include <vector>
#include <queue> // priority_queue
#include <algorithm> // max

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size = priorities.size();

    // 우선순위 큐를 max heap으로 선언
    priority_queue<int> pq;
    
    for (int priority : priorities) {
        pq.push(priority); // 우선순위를 큐에 추가
    }

    // 원래의 인덱스를 추적하기 위한 변수
    int idx = 0;

    while (!pq.empty()) {
        // 가장 높은 우선순위를 가진 프로세스
        int curMax = pq.top();

        // 큐의 맨 앞 원소를 확인
        if (curMax == priorities[idx]) {
            answer++; // 프로세스 처리
            if (idx == location) { // 해당 프로세스가 location에 있는 경우
                break; // 루프 종료
            }
            pq.pop(); // 처리한 프로세스 제거
        }
        idx++; // 다음 인덱스 이동
        if (idx >= size) idx = 0; // 인덱스가 끝에 도달하면 다시 처음으로
    }

    return answer;
}