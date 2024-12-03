//=====================================================================
//   10773번:    제로                   
//   @date:   2024-12-03              
//   @link:   https://www.acmicpc.net/problem/10773  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <stack>
using namespace std;
            
int main() {
  int t, count = 0;
	cin >> t;

  stack<int> s;

  for(int i=0;i<t;i++) {
    int num;
    cin >> num;
    if(num == 0) s.pop();
    else s.push(num);
    
  }

  while(!s.empty()) {
    count += s.top();
    s.pop();
  }
  
  cout << count;
  return 0;
}
