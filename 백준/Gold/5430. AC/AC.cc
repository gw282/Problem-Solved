//=====================================================================
//   5430번:    AC                   
//   @date:   2024-12-05              
//   @link:   https://www.acmicpc.net/problem/5430  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

deque<int> dq;
string answer;
bool not_reversed = true;

// 숫자값만 가져오기
void Parsing(string numbers, deque<int> &dq) {
  // 괄호 제거하기
  if(numbers.front() == '[') numbers.erase(0,1);
  if(numbers.back() == ']') numbers.pop_back();

  stringstream ss(numbers);
  string temp;
  
  // 쉼표 단위로 숫자 추출하기
  while (getline(ss, temp, ',')) {
      dq.push_back(stoi(temp));
  }
}

// 연산하기
bool Calculating(string str, deque<int> &dq) {
  for(int i=0;i<str.length();i++) {
    if(str[i] == 'R') {
      not_reversed = !not_reversed;
    } else {
      if(dq.empty()) return false;
      else if(not_reversed) {
        dq.pop_front();
      } else {
        dq.pop_back();
      }
    }
  }
  return true;
}

string AC() {
  string str, numbers;
  int n;

  cin >> str;
  cin >> n;
  cin >> numbers;

  Parsing(numbers, dq);
  
  if(Calculating(str, dq)) {
    answer += '[';
    if(not_reversed) {
      for(int i=0;i<dq.size();i++) {
        answer += to_string(dq[i]);
        if(i != dq.size()-1) answer += ',';
      }
    } else if(!not_reversed) {
      for(int i=dq.size()-1;i>=0;i--) {
        answer += to_string(dq[i]);
        if(i > 0) answer += ',';
      }
    }
    answer += ']';
  } else answer = "error";
  return answer;
}


int main() {
  int t;
	cin >> t;

  while(t--) {
    cout << AC() << '\n';
    dq.clear();
    answer = "";
    not_reversed = true;
  }
  return 0;
}
