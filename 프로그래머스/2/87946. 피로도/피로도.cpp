#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxDungeonExplore(int k, vector<vector<int>> dungeons) {
    int maxDungeons = 0;
    vector<int> order(dungeons.size());
    
    // 순열을 위한 인덱스 초기화
    for (int i = 0; i < dungeons.size(); i++) {
        order[i] = i;
    }
    
    while (next_permutation(order.begin(), order.end())) {
        int remainingFatigue = k;
        int count = 0;
        
        // 던전 순서대로 탐험
        for (int i = 0; i < dungeons.size(); i++) {
            int minFatigue = dungeons[order[i]][0];  // 던전 탐험 최소 피로도
            int consumeFatigue = dungeons[order[i]][1];  // 던전 탐험 시 소모되는 피로도
            
            if (remainingFatigue >= minFatigue) {
                remainingFatigue -= consumeFatigue;
                count++;
            } else {
                break;  // 더 이상 탐험할 수 없으면 종료
            }
        }
        
        // 탐험 가능한 던전의 최대 개수 갱신
        maxDungeons = max(maxDungeons, count);
        
    }
    
    return maxDungeons;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    answer = maxDungeonExplore(k, dungeons);
    return answer;
}
