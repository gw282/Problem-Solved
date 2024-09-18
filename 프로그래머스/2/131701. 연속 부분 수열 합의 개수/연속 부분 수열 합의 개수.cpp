#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(const vector<int> elements) {
    vector<int> extendedElements(elements); // 원본 수열을 복사
    int n = elements.size();

    // 원형 수열을 처리하기 위해, 원본 수열의 처음부터 끝에서 하나 전까지의 요소를 추가
    extendedElements.insert(extendedElements.end(), elements.begin(), elements.end() - 1);

    unordered_set<int> uniqueSums; // 서로 다른 부분합을 저장할 집합

    // 모든 시작 위치에 대해 연속 부분 수열의 합 계산
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < i + n; ++j) {
            sum += extendedElements[j]; // 현재 부분 수열의 합을 업데이트
            uniqueSums.insert(sum); // 집합에 부분합 추가
        }
    }

    return uniqueSums.size(); // 서로 다른 부분합의 개수를 반환
}
