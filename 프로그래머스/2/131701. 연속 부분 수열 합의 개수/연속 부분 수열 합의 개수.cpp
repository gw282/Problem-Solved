#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int n = elements.size(); // 수열의 길이
    unordered_set<int> sumSet; // 서로 다른 부분합을 저장할 집합

    // 원형 수열의 연속 부분 수열 합 구하기
    for (int len = 1; len <= n; ++len) { // 부분 수열의 길이를 1부터 n까지
        for (int start = 0; start < n; ++start) { // 수열의 각 위치에서 시작
            int sum = 0; // 부분 수열의 합을 저장할 변수
            for (int i = 0; i < len; ++i) { // 길이 len 만큼의 수열을 더함
                sum += elements[(start + i) % n]; // 원형 수열을 처리하기 위해 % 사용
            }
            sumSet.insert(sum); // 계산된 부분 합을 집합에 추가 (중복 방지)
        }
    }
    
    answer =  sumSet.size();
    return answer;
}
