#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 작업을 끝나는 시간 기준으로 정렬하기 위한 비교 함수
bool cmp(const vector<int> &a, const vector<int> &b){
    // 소요 시간이 짧은 작업 우선
    if(a[1] == b[1]) {
        // 소요 시간이 같으면, 요청 시각이 빠른 작업 우선
        if(a[0] == b[0]) {
            // 요청 시각도 같으면, 작업 번호(인덱스)가 작은 작업 우선
            return a < b;  // 벡터 비교 시 lexicographical order (사전순 정렬)
        }
        return a[0] < b[0];  // 요청 시각이 빠른 작업 우선
    }
    return a[1] < b[1];  // 소요 시간이 짧은 작업 우선
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;  // 총 대기 시간을 저장할 변수
    int time = 0;    // 현재 시간을 나타내는 변수
    int cnt = jobs.size();  // 작업의 개수 (최종 대기 시간 평균을 구하기 위해 사용)
    
    // 작업을 종료 시간 기준으로 오름차순 정렬
    sort(jobs.begin(), jobs.end(), cmp);
    
    // 모든 작업이 처리될 때까지 반복
    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            // 작업이 시작 가능한 시간에 도달했을 때
            if(jobs[i][0] <= time){
                // 작업을 처리하고, 총 대기 시간에 더함
                time += jobs[i][1];  // 현재 시간에 작업 시간을 더함
                answer += (time - jobs[i][0]);  // 작업이 끝난 시간에서 시작 시간을 뺀 값은 대기 시간
                jobs.erase(jobs.begin() + i);  // 처리한 작업을 리스트에서 제거
                break;  // 작업을 하나 처리했으므로 다음 작업을 찾기 위해 루프 종료
            }
            // 만약 모든 작업을 확인했을 때도 처리할 수 없는 경우 시간 증가
            if(i == jobs.size() - 1) time++;
        }
    }
    // 총 대기 시간을 작업 개수로 나누어 평균 대기 시간 반환
    return answer / cnt;
}
