#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int left = 0;
    int right = people.size() - 1;

    // 사람들을 오름차순으로 정렬
    sort(people.begin(), people.end());

    // 투 포인터를 사용
    while (left <= right) {
        // 가장 가벼운 사람과 가장 무거운 사람을 함께 구출할 수 있는지 확인
        if (people[left] + people[right] <= limit) {
            left++;  // 가장 가벼운 사람도 구출
        }
        right--;  // 가장 무거운 사람 구출
        answer++;  // 보트 수 증가
    }

    return answer;
}
