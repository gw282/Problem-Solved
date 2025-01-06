//=====================================================================
//   3151번:    합이 0                   
//   @date:   2025-01-06              
//   @link:   https://www.acmicpc.net/problem/3151  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int a[10002];

int main() {
ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  long long ans = 0;

  // 첫 번째 학생을 고정
  for (int i=0;i<n-1;i++) {
    for (int j=i+1;j<n;j++) {
      // 두 번째 학생 뒤에서 세 번째 학생의 범위를 탐색
      //  -a[i]-a[j] : 세 번째 학생이 가져야 할 값
      auto ub = upper_bound(a+j+1, a+n, -a[i]-a[j]);
      auto lb = lower_bound(a+j+1, a+n, -a[i]-a[j]);
      ans += ub-lb;
    }
  }
  cout << ans;

  return 0;
}
