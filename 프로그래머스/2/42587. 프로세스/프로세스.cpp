#include <string>
#include <vector>
#include <deque>
#include <algorithm> // max

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool flag = false; // 해당 프로세스가 실행될 때 true
    int size = priorities.size();

    deque<pair<int,int>> dq;
    
    for(int i=0;i<size;i++) {
        dq.push_back({priorities[i], i});
    }
    
    while (!flag) {
        int dq_max = dq.front().first;
        int dq_size = dq.size();
        
        for (int i = 1; i < dq.size(); i++) {
            dq_max = max(dq_max, dq[i].first); // 우선순위 최댓값 저장
        }
            
        
        for (int i = 0; i < dq_size; i++) {
            // 최댓값과 현재 우선순위가 같을 경우
            if (dq_max == dq.front().first) {
                answer++;
                // 해당 프로세스인 경우
                if (dq.front().second == location) {
                    flag = true;
                    break;
                }
                dq.pop_front();
                break;
            // 아닌 경우: 대기큐에서 원소를 뒤로 이동
            } else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    return answer;
}
