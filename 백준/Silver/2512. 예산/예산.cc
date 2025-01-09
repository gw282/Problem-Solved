//=====================================================================
//   2512번:    예산                   
//   @date:   2025-01-09              
//   @link:   https://www.acmicpc.net/problem/2512  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;
            
int n, budget;
int a[100002];

bool func(int limit) {
  int sum = 0;
  for(int i=0;i<n;i++)
    sum += min(a[i], limit); // limit보다 작은 경우만 예산 할당
  return budget >= sum; // 예산 초과하지 않았으면 true
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int st = 1, en = 1;

  for(int i=0;i<n;i++) {
    cin >> a[i];
    en = max(a[i], en); // 최대 요청 예산
  }
  cin >> budget;

  while(st < en) {
    int mid = (st+en+1)/2;
    if(func(mid)) st = mid; // 예산 배정 가능
    else en = mid-1; // 예산 배정 불가
  }
  cout << st;

  return 0;
}
