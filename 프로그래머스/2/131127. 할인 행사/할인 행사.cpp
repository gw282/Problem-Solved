#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    // i부터 시작하는 10일 간의 항목을 검사
    for (int i = 0; i <= discount.size() - 10; i++) {
        
        map<string, int> itemMap;
        
        // itemMap을 want에 있는 항목들로 초기화하고 각 값을 0으로 세팅
        for (int j=0;j<want.size();j++) {
            itemMap[want[j]] = 0;
        }
        
        // i부터 시작하는 10일간의 할인 항목을 itemMap에 기록
        for (int j = i; j < i + 10; j++) {
            if (itemMap.find(discount[j]) != itemMap.end()) {
                itemMap[discount[j]]++;
            }
        }
        
        // 모든 want 항목의 개수가 충족되는지 확인
        bool match = true;
        for (int j = 0; j < want.size(); j++) {
            if (itemMap[want[j]] != number[j]) {
                match = false;
                break;
            }
        }

        // 모든 항목이 맞으면 answer을 설정하고 종료
        if (match) {
            answer++;
        }
    }

    return answer;
}
