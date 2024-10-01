#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;  // 각 기능을 완성하는 데 필요한 날짜를 저장하는 벡터
    
    for(int i = 0; i < speeds.size(); i++) {
        int remainingProgress = 100 - progresses[i];
        int day = (remainingProgress + speeds[i] - 1) / speeds[i]; // 올림 계산
        days.push_back(day);
    }

    int count = 0; // 배포할 기능 수
    int maxDays = days[0]; // 첫 번째 기능의 최대 날짜로 초기화

    for(int i = 0; i < days.size(); i++) {
        if (days[i] <= maxDays) {
            count++; // 현재 maxDays 내에서 배포 가능한 기능 수 증가
        } else {
            if (count > 0) {
                answer.push_back(count); // 배포할 기능 수가 있으면 answer에 추가
            }
            count = 1; // 새로운 기능의 경우 카운트 초기화
            maxDays = days[i]; // maxDays 업데이트
        }
    }

    // 마지막으로 남아있는 기능 수를 answer에 추가
    if (count > 0) {
        answer.push_back(count);
    }

    return answer;
}
