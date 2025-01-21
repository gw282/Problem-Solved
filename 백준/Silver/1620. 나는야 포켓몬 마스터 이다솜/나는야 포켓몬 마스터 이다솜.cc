//=====================================================================
//   1620번:    나는야 포켓몬 마스터 이다솜                   
//   @date:   2025-01-21              
//   @link:   https://www.acmicpc.net/problem/1620  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  unordered_map<string, int> mon; // 순번 저장
  string num[100002]; // 이름 저장

  for(int i=1;i<=n;i++) {
    cin >> num[i];
    mon[num[i]] = i;
  }

  for(int i=0;i<m;i++) {
    string str;
    cin >> str;
    if(isdigit(str[0])) {
      cout << num[stoi(str)] << '\n';
    } else {
      cout << mon[str] << '\n';
    }
  }

  
  return 0;
}
