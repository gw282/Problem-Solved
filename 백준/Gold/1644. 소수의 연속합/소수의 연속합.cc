//=====================================================================
//   1644번:    소수의 연속합                   
//   @date:   2025-01-15              
//   @link:   https://www.acmicpc.net/problem/1644  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
using namespace std;

  int limit = 4000002;
  vector<bool> isPrime(limit, true);
  vector<int> primes;
            
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
	cin >> n;

  for (int i=2; i*i<limit; i++) {
      if (isPrime[i]) {
          for (int j=i*i; j<limit; j+=i) {
              isPrime[j] = false; // i의 배수는 소수가 아님
          }
      }
  }

  for (int i=2; i<limit; i++) {
      if (isPrime[i]) {
          primes.push_back(i); // 소수를 벡터에 추가
      }
  }

  int st = 0, en = 1, ans = 0;
  int sum = primes[0]; // st부터 en-1까지의 합

  while(1) {
    if(sum == n) ans++; // 일치하면 답 1 증가
    if(sum <= n) sum += primes[en++]; // 답을 찾았거나 합이 아직 작다면 소수 하나 더 더함
    if(sum > n) sum -= primes[st++]; // 합이 더 크면 맨 앞 소수 제거

    if(en-1 == primes.size()) break;
  }
  
  cout << ans;

  return 0;
}
