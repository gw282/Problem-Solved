//=====================================================================
//   1456번:    거의 소수                   
//   @date:   2025-01-28              
//   @link:   https://www.acmicpc.net/problem/1456  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
using namespace std;

vector<int> check(int n) {
  vector<int> primes;
  vector<bool> ch(n + 1, true);
  ch[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (!ch[i]) continue;
    for (int j = i * i; j <= n; j += i)
      ch[j] = false;
  }
  for (int i = 2; i <= n; i++) {
    if (ch[i]) primes.push_back(i);
  }
  return primes;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> primes = check(10000000);
  long long a, b;
  cin >> a >> b;

  int cnt = 0;

  for (int p : primes) {
    for (long long i = p; i <= b / p; i *= p)
      cnt += (i * p >= a);
  }

  cout << cnt;

  return 0;
}