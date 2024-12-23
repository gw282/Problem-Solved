//=====================================================================
//   11057번:    오르막 수                   
//   @date:   2024-12-23              
//   @link:   https://www.acmicpc.net/problem/11057  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;

long long dp[1002][10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=1;i<=n;i++) {
    dp[i][0] = 1;
    for(int j=1;j<=9;j++) {
      dp[i][j] = (dp[i][j-1] + dp[i-1][j])%10007;
    }
  }

  int num = 0;
   for (int j=0;j<=9;j++) {
        num = (num + dp[n][j])%10007;
    }

  cout << num;
  
  return 0;
}
