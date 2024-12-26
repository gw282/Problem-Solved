//=====================================================================
//   4883번: 삼각 그래프                   
//   @date:   2024-12-26              
//   @link:   https://www.acmicpc.net/problem/4883  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트" 통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int a[100005][3]; // 각 위치의 비용 정보를 저장
int d[100005][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int k = 1;
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 3; j++)
        cin >> a[i][j];

    d[0][0] = 1001;
    d[0][1] = a[0][1];
    d[0][2] = a[0][1] + a[0][2];

    for (int i = 1; i < n; i++) {
      d[i][0] = a[i][0] + min(d[i - 1][0], d[i - 1][1]);
      d[i][1] = a[i][1] + min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]});
      d[i][2] = a[i][2] + min({d[i - 1][1], d[i - 1][2], d[i][1]});
    }
    cout << k++ << ". " << d[n - 1][1] << '\n';
  }
}