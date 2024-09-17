#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> // sort

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> map;
    
    // 각 귤 크기의 빈도수 계산
    for (int num : tangerine) {
        map[num]++;
    }
    
    // 빈도수를 벡터에 저장
    vector<int> count;
    for (const auto& pair : map) {
        count.push_back(pair.second);
    }
    
    // 빈도수를 내림차순으로 정렬
    sort(count.rbegin(), count.rend());
    
    int sum = 0;
    int answer = 0;
    
    // 가장 많이 등장하는 귤 크기부터 선택하여 k개 이상이 될 때까지 최소한의 종류를 찾음
    for (int freq : count) {
        sum += freq;
        answer++;
        if (sum >= k) {
            break;
        }
    }
    
    return answer;
}
