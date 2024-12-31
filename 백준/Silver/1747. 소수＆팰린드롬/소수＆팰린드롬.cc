//=====================================================================
//   1747번:    소수&팰린드롬                   
//   @date:   2024-12-31              
//   @link:   https://www.acmicpc.net/problem/1747  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;
            
bool isprime(int n){
  if(n == 1) return false;
  for(int i = 2; i*i <= n; i++){
    if(n % i == 0) return false;
  }
  return true;
}

bool isPalindrome(int n) { // 원래 숫자 저장
  int reversedNumber = 0; // 뒤집힌 숫자 저장
  int tmp = n;
  while (n > 0) {
    reversedNumber = 10 * reversedNumber + n % 10; // 뒤집기
    n /= 10; // 마지막 자릿수 제거
  }

  return tmp == reversedNumber;  // 회문 확인
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while(!isprime(n) || !isPalindrome(n)) n++;
  cout << n;

  return 0;
}
