//=====================================================================
//   1543번:    문서 검색                   
//   @date:   2025-01-31              
//   @link:   https://www.acmicpc.net/problem/1543  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <string>
using namespace std;
            
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;
  string a, b;

  getline(cin, a); // 한 줄을 입력받음
  getline(cin, b);

  int it = a.find(b); // 문자열 시작 위치 발견

  while(it != string::npos) { // 문자열 끝까지 도달하기 전까지
    cnt++;
    it = a.find(b, it + b.size()); // 다음 위치부터 다시 문자열을 찾아봄. 찾은 위치 + 문자열 길이만큼 시작점 이동
  }

  cout << cnt;

  return 0;
}