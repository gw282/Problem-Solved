//=====================================================================
//   18258번:    큐 2                   
//   @date:   2024-12-04              
//   @link:   https://www.acmicpc.net/problem/18258  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <queue>
using namespace std;
            
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
	cin >> t;

  queue<int> q;

  for(int i=0;i<t;i++) {
    string s;
    cin >> s;
    if(s == "push") {
      int X;
      cin >> X;
      q.push(X);
      continue;
    } else if(s == "pop") {
      if(q.empty()) cout << -1;
      else {
        cout << q.front();
        q.pop();
      }
    } else if(s == "size") {
      cout << q.size();
    } else if(s == "empty") {
      if(q.empty()) cout << 1;
      else cout << 0;
    } else if(s == "front") {
      if(q.empty()) cout << -1;
      else cout << q.front();
    } else if(s == "back") {
      if(q.empty()) cout << -1;
      else cout << q.back();
    }
    cout << "\n";
  }
  return 0;
}
