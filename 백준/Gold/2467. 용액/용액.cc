//=====================================================================
//   2467번:    용액                   
//   @date:   2025-01-03              
//   @link:   https://www.acmicpc.net/problem/2467  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;

int a[100002];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }

  int ans1 = 1000000002;
  int ans2 = 1000000002;

  for(int i=0;i<n;i++) { // 배열을 순회하며
    // -a[i]가 들어갈 위치를 찾기 위해 lower_bound 사용
    int idx = lower_bound(a, a+n, -a[i]) - a; 
    // a[idx]는 -a[i]와 같거나 더 큰 값

    // a[i]와 더했을 때, 값이 가장 작은 두 수를 찾기 위해
    if(idx+1<n && i!=idx+1 && abs(a[i]+a[idx+1]) < abs(ans1+ans2)) {
      ans1 = a[i];  // 새로운 최적의 값을 찾으면 갱신
      ans2 = a[idx+1];
    }
    
    if(idx<n && i!=idx && abs(a[i]+a[idx]) < abs(ans1+ans2)) {
      ans1 = a[i];  // 새로운 최적의 값을 찾으면 갱신
      ans2 = a[idx];
    }

    if(idx!=0 && i!=idx-1 && abs(a[i]+a[idx-1]) < abs(ans1 + ans2)) {
      ans1 = a[i];  // 새로운 최적의 값을 찾으면 갱신
      ans2 = a[idx-1];
    }
  }

  if(ans1>ans2) swap(ans1, ans2);

  cout << ans1 << ' ' << ans2;

  return 0;
}