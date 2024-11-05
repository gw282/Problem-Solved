#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    map<int,int> left;  // 왼쪽 조각에 있는 토핑의 종류
    map<int,int> right; // 오른쪽 조각에 있는 토핑의 종류
    
    // 1. 오른쪽에 모든 토핑을 배치
    for(int i = 0; i < n; i++) {
        right[topping[i]]++; 
    }
    
    // 2. 왼쪽으로 하나씩 이동하며 비교
    for(int i = 0; i < n; i++) {
        // 왼쪽에 토핑 추가, 오른쪽에서 제거
        left[topping[i]]++;
        right[topping[i]]--;
        
        // 오른쪽에서 토핑의 개수가 0이면 제거
        if(right[topping[i]] == 0) {
            right.erase(topping[i]);
        }
        
        // 3. 고유한 토핑 개수가 같으면 개수 추가
        if(left.size() == right.size()) {
            answer++;
        }
    }
    
    return answer;
}
