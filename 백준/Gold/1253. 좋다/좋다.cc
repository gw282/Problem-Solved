//=====================================================================
//   1251번:    단어 나누기                   
//   @date:   2025-01-08              
//   @link:   https://www.acmicpc.net/problem/1251  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 배열을 오름차순으로 정렬
    sort(a.begin(), a.end());

    int cnt = 0;

    for (int i=0;i<n;i++) {
        unordered_set<int> seen;  // 중복된 합을 방지하기 위해 사용
        for (int j=0;j<n;j++) {
            if (i == j) continue; // 같은 인덱스는 제외

            int target = a[i] - a[j]; // 차이 계산

            // target 값이 seen에 존재하면 좋은 수로 간주
            if (seen.count(target)) {
                cnt++;
                break;
            }

            // target 값을 set에 추가
            seen.insert(a[j]);
        }
    }

    cout << cnt;
    return 0;
}
