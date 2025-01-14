//=====================================================================
//   1806번:    부분합                   
//   @date:   2025-01-14              
//   @link:   https://www.acmicpc.net/problem/1806  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;

int n,s;
int a[100002];
int len = 100002;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0; // 부분합
    int en = 0;  // 끝 인덱스

    // 슬라이딩 윈도우
    for (int st = 0; st < n; st++) {
        // en을 계속 이동시켜 부분합이 s 이상이 되도록 맞추기
        while (en < n && cnt < s) {
            cnt += a[en++];
        }

        if (cnt >= s) {
            len = min(len, en - st); // 부분합 길이가 작으면 업데이트
        }

        cnt -= a[st]; // 처음 인덱스를 제거하고 부분합 재개
    }

    if (len == 100002) len = 0;

    cout << len;

    return 0;
}
