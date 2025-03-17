#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    // 각 기능이 완료되기까지 필요한 일수를 계산하여 queue에 저장
    for (int i = 0; i < progresses.size(); i++) {
        int remainingProgress = 100 - progresses[i];
        int day = (remainingProgress + speeds[i] - 1) / speeds[i]; // 올림 계산
        q.push(day);
    }

    while (!q.empty()) {
        int count = 1; // 배포할 기능 개수
        int maxDay = q.front(); // 첫 번째 기능의 배포 기준일
        q.pop();

        // 뒤에 있는 기능이 앞 기능과 함께 배포될 수 있는지 확인
        while (!q.empty() && q.front() <= maxDay) {
            count++;
            q.pop();
        }

        answer.push_back(count); // 배포 가능한 기능 개수를 저장
    }

    return answer;
}
