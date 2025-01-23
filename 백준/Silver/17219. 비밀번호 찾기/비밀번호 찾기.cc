//=====================================================================
//   17219번:    비밀번호 찾기                   
//   @date:   2025-01-23              
//   @link:   https://www.acmicpc.net/problem/17219  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <map>
using namespace std;

int n, m;
map<string, string> km;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i=0;i<n;i++) {
    string site, pw;
    cin >> site >> pw;
    km[site] = pw;
  } 

  for(int i=0;i<m;i++) {
    string site;
    cin >> site;
    cout << km[site] << '\n';
  }

  
  return 0;
}