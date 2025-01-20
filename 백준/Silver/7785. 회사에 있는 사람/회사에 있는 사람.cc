//=====================================================================
//   7785번:    회사에 있는 사람                   
//   @date:   2025-01-20              
//   @link:   https://www.acmicpc.net/problem/7785  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <set>
using namespace std;

set<string> remain;

int main() {
  int t;
	cin >> t;

  for(int i=0;i<t;i++) {
    string name;
    string record;
    cin >> name >> record;

    if(record == "enter") {
      remain.insert(name);
    } else {
      remain.erase(name);
    }
  }

  for(auto it=remain.rbegin(); it!=remain.rend();it++) {
      cout << *it << '\n';
  }

  return 0;
}
