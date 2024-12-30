//=====================================================================
//   15903번:    카드 합체 놀이                   
//   @date:   2024-12-30              
//   @link:   https://www.acmicpc.net/problem/15903  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  long long res = 0;
	cin >> n >> m;

  for(int i=0;i<n;i++) {
    cin >> arr[i];
  }

  while(m--) {
    sort(arr,arr+n);
    long long t;
    t = arr[0] + arr[1];
    arr[0] = t;
    arr[1] = t;
  }

  for(int i=0;i<n;i++) {
    res += arr[i];
  }

  cout << res;
  
  return 0;
}
