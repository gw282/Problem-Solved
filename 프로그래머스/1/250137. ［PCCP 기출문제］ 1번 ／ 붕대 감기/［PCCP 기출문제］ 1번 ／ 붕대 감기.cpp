#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health; // 체력을 저장
    int attack_time = 0; // 공격 시간
    int attack_order = 0; // 공격 시간 벡터 순서
    int size = attacks.size(); // 공격 시간 개수
    int stack = 0; // 연속 성공 카운트

    for(int i = 1; i <= attacks[size-1][0]; i++) {
        // 공격 시간 업데이트
        if(attack_order < size && i >= attacks[attack_order][0]) {
            attack_time = attacks[attack_order][0];
            attack_order++;
        }

        // 공격 시간과 현재 시간 비교 및 체력 회복
        if(i != attack_time) {
            answer += bandage[1];
            if(answer > health) answer = health; // 체력이 최대치를 초과하지 않도록
            stack++;
        } else if(i == attack_time) {
            answer -= attacks[attack_order - 1][1]; // 공격 피해
            if(answer <= 0) return -1; // 체력이 0 이하이면 실패
            stack = 0; // 스택 초기화
        }
        
        // 연공 성공 체력 회복 조건
        if(stack == bandage[0]) {
            answer += bandage[2]; // 체력 회복
            if(answer > health) answer = health; // 체력이 최대치를 초과하지 않도록
            stack = 0; // 스택 초기화
        }

    }

    return answer;
}