#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> dress;
    
    // 옷 종류별로 개수 카운팅
    for(int i=0; i<clothes.size();i++) {
        dress[clothes[i][1]] += 1;
    }
    
    // 옷 종류가 1개일 경우 바로 리턴
    if (dress.size() == 1) {
        return dress.begin()->second;
    }
    
    // 경우의 수 계산
    for (const auto& entry : dress) {
        answer *= (entry.second+1);  // 각 종류의 옷을 입지 않는 경우도 포함
    }
    
    return answer-1;  // 아무것도 안 입는 경우는 제외
}
