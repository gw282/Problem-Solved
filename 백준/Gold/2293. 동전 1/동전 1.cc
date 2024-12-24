//=====================================================================
//   2293번:    동전 1                   
//   @date:   2024-12-24              
//   @link:   https://www.acmicpc.net/problem/2293  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;

int n, k;
int coin[10002], dp[10002]; // coin[]: 각 동전의 가치, dp[]: 각 금액을 만들 수 있는 방법의 수

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  
  for (int i = 0; i < n; i++)
    cin >> coin[i];

  dp[0] = 1;

  // 각 동전을 이용해 dp 배열을 갱신
  for (int i = 0; i < n; i++) { // 각 동전들에 대해
    for (int j = coin[i]; j <= k; j++) { // 금액 coin[i]부터 k까지 확인
      // dp[j - coin[i]]: coin[i]를 사용하기 전, dp[j - coin[i]]가 의미하는 것은
      // coin[i]를 사용하고 나서 (j - coin[i])원을 만들 수 있는 방법의 수
      dp[j] += dp[j - coin[i]]; // coin[i]를 추가해서 dp[j]를 갱신
      // 즉, dp[j]에 dp[j - coin[i]] 방법을 더하는 것과 같다
      // 왜냐하면 dp[j - coin[i]] 방법으로 금액 j - coin[i]를 만들 수 있다면, 
      // 그 방법에 coin[i]를 추가하여 j원을 만들 수 있기 때문
    }
  }

  cout << dp[k];

  return 0;
}