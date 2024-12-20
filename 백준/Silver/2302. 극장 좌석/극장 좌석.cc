//=====================================================================
//   2302번:    극장 좌석                   
//   @date:   2024-12-20              
//   @link:   https://www.acmicpc.net/problem/2302  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
using namespace std;
            
int seat[41];
vector<int> v;

int main() {
  int n,m;
  cin >> n >> m;

  for(int i=0;i<m;i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  seat[0] = 1;
  seat[1] = 1;

  for(int i=2;i<=n;i++) {
    seat[i] = seat[i-1] + seat[i-2];
  }

  int res = 1;
  int prev = 0; // 이전 VIP석 위치

  for(int i=0;i<m;i++) {
    int gap = v[i] - prev - 1; // 이전 VIP석 ~ 다음 VIP 석 사이의 좌석수

    if(gap > 0) {
      res *= seat[gap];
    }

    prev = v[i];
  }

  int gap = n - prev;  // 마지막 VIP석 뒤의 비VIP석 좌석수
  if (gap > 0) {
      res *= seat[gap];
  }

  cout << res;
  
  return 0;
}
