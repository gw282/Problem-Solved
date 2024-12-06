//=====================================================================
//   3986번:    좋은 단어                   
//   @date:   2024-12-06              
//   @link:   https://www.acmicpc.net/problem/3986  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <stack>
using namespace std;
            
int main() {
  int t, count = 0;
	cin >> t;

  for(int i=0;i<t;i++) {
    string str;
    cin >> str;

    if(str.length() % 2 == 1) continue;
    stack<int> s;
    for(int i=0;i<str.length();i++) {
      if(s.empty()) s.push(str[i]);
      else if(s.top() != str[i]) s.push(str[i]);
      else s.pop();
    }
    if(s.empty()) count++;
  }
  cout << count;
  return 0;
}
