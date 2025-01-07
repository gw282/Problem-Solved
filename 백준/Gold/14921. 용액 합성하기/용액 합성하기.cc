//=====================================================================
//   14921번:    용액 합성하기                   
//   @date:   2025-01-07              
//   @link:   https://www.acmicpc.net/problem/14921  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;
            
int a[100002];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i=0;i<n;i++) {
    cin >> a[i];
  }

  int ans = 200000002;
  int st = 0, en = n - 1;
  
  while (st < en) {
    int val = a[st] + a[en];

    // 합이 0에 더 가까운 값이 나오면 ans 업데이트
    if (abs(val) < abs(ans)) ans = val;

    // 합이 음수라면 st를 증가하여 더 큰 값 찾기
    if (val < 0) st++;

    // 합이 양수라면 en를 증가하여 더 작은 값 찾기
    else en--;
  }

  cout << ans;

  return 0;
}
