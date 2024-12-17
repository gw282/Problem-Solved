//=====================================================================
//   2240번:    자두나무                   
//   @date:   2024-12-17              
//   @link:   https://www.acmicpc.net/problem/2240  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1002]; // 각 시간에 딸 자두 나무 정보 (1번 나무 또는 2번 나무)
int d[1002][32][3]; // d[i][j][k]는 i번째 시간에 j번 이동 후 k번 나무에서 자두를 딴 최대 개수
            
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);  

  int t, w;
  cin >> t >> w;
  for (int i=1;i<=t;i++)
    cin >> arr[i];

  
  for (int i=1;i<=t;i++) {
    d[i][0][1] = d[i-1][0][1] + (arr[i] == 1 ? 1 : 0); // i번째까지 이동하지 않은 경우, 1번 나무에서 자두를 따면 +1
    for (int j = 1; j <= w; j++) { // j번 이동
      if (i < j) break; // 현재 시간보다 이동 횟수(j)가 많으면 안됨 (최대 t번 시간까지 이동 가능)
      if (arr[i] == 1) { // 1번 나무인 경우
        d[i][j][1] = max(d[i-1][j-1][2], d[i-1][j][1])+1;
        d[i][j][2] = max(d[i-1][j-1][1], d[i-1][j][2]);
      }
      else { // 2번 나무인 경우
        d[i][j][1] = max(d[i-1][j-1][2], d[i-1][j][1]);
        d[i][j][2] = max(d[i-1][j-1][1], d[i-1][j][2])+1;
      }
    }
  }

  int ans = 0;
  for (int j=0;j<=w;j++)
    ans = max({ans, d[t][j][1], d[t][j][2]});
  cout << ans;
  return 0;
}
