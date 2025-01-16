//=====================================================================
//   2003번:    수들의 합 2                   
//   @date:   2025-01-16              
//   @link:   https://www.acmicpc.net/problem/2003  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;

int n, m;
long long a[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	cin >> n >> m;

  a[0] = 0;

  for(int i=1;i<=n;i++) {
    cin >> a[i];
    a[i] += a[i-1]; // 누적합 계산
  }

  int st = 0, en = 0;
  int ans = 0;

  while (en <= n) {
    long long sum = a[en] - a[st];
    if (sum < m) { // 합이 m보다 작은 경우
          en++;
        } 
        else if (sum > m) { // 합이 m보다 큰 경우
          st++; // 합 감소
        } 
        else { // sum == m인 경우
          ans++; // 조건 만족
          en++; // 합 증가
        }
  }

  cout << ans;

  return 0;
}
