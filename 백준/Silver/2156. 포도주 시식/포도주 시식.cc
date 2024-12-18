//=====================================================================
//   2156번:    포도주 시식                   
//   @date:   2024-12-18              
//   @link:   https://www.acmicpc.net/problem/2156  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int glass[10010]; // 포도주 잔의 포도주 양
int mx[10010]; // 포도주의 최대 양

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
	cin >> t;

  for(int i=1;i<=t;i++) {
    cin >> glass[i];
  }

  mx[1] = glass[1]; 
  mx[2] = glass[1] + glass[2];

  for(int i=3;i<=t;i++) {
    // i번째 안마시기 vs i번째 잔만 마시기 vs i와 i-1번째 잔 마시기
    mx[i] = max({mx[i-1], mx[i-2] + glass[i], mx[i-3] + glass[i-1] + glass[i]});
  }

  cout << mx[t];
  
  return 0;
}
