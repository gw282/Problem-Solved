//=====================================================================
//   2504번:    괄호의 값                   
//   @date:   2024-12-06              
//   @link:   https://www.acmicpc.net/problem/2504  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <stack>
using namespace std;
            
int main() {
  int count = 0;
  int temp = 1;
  string s;
  stack<char> st;
  cin >> s;

  for(int i=0;i<s.length();i++) {
    if (s[i] == '(') {
      temp *= 2;
      st.push('(');
    } else if (s[i] == '[') {
        temp *= 3;
        st.push('[');
    }
    else if(s[i] == ')') {
      if(st.empty() || st.top() != '(') {
        cout << 0;
        return 0;
      }
      if (s[i - 1] == '(') { 
        count += temp;
      }
      temp /= 2;
      st.pop();
    }

    else if(s[i] == ']') {
      if(st.empty() || st.top() != '[') {
        cout << 0;
        return 0;
      }
      if (s[i - 1] == '[') { 
        count += temp;
      }
      temp /= 3;
      st.pop();
    }
  }

  if (!st.empty()) {
      cout << 0;
      return 0;
  }

  cout << count;

  
  return 0;
}
