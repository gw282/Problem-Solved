#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> heights(t);
    vector<int> results(t);

    for (int i=0;i<t;i++) {
        cin >> heights[i];
    }

    stack<pair<int,int>> s; // 탑의 높이, 인덱스 저장

    for (int i=0;i<t;i++) {
        while (!s.empty() && s.top().first < heights[i]) {
            s.pop(); // 현재 탑보다 낮은 탑은 제거
        }

        if (s.empty()) {
            results[i] = 0; // 닿는 탑이 없음
        } else {
            results[i] = s.top().second + 1; // 1-based 인덱스
        }
        s.push({heights[i], i}); // 현재 탑 추가
    }

    for (int i=0;i<t;i++) {
        cout << results[i] << " ";
    }

    return 0;
}
