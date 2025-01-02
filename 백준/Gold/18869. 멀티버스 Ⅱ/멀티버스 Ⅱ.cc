//=====================================================================
//   18869번:    멀티버스 Ⅱ                   
//   @date:   2025-01-02              
//   @link:   https://www.acmicpc.net/problem/18869  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int arr[102][10002];

void change(int a[]) {
  vector<int> v(a, a + n); // 배열을 vector로 복사
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end()); // 중복값 제거
  for (int i=0;i<n;i++) {
    // lower_bound를 사용하여 각 원소가 v에서 몇 번째로 작은 값인지 찾음
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
  }

}

bool compare(int a[], int b[]) {
  for (int i=0;i<n;i++)
    if (a[i] != b[i]) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i=0;i<m;i++) {
    for (int j=0;j<n;j++) cin >> arr[i][j];
    change(arr[i]);
  }

  int ans = 0;
  for (int i=0;i<m-1;i++) {
    for (int j=i+1;j<m;j++) {
      ans += compare(arr[i], arr[j]);
    }
  }

  cout << ans;

  return 0;
}
