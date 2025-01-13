//=====================================================================
//   2230번:    수 고르기                   
//   @date:   2025-01-13              
//   @link:   https://www.acmicpc.net/problem/2230  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int big = -1;
int a[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++) {
    cin >> a[i];
  }

  sort(a,a+n);

  int st = 0;
  int en = 0;

  for(st=0;st<n;st++) {
    while(en<n && a[en]-a[st] < m) {
      en++;
    }
    if(en==n) break;
    if(big == -1) big = a[en]-a[st];
    else big = min(big, a[en]-a[st]);
  }

  cout << big;
  
  return 0;
}
