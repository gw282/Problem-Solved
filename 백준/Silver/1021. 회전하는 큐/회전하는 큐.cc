//=====================================================================
//   1021번:    회전하는 큐                   
//   @date:   2024-12-04              
//   @link:   https://www.acmicpc.net/problem/1021  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
            
int main() {
  int n,m,count=0;
	cin >> n >> m;

  deque<int> d;

  for(int i=1;i<=n;i++) {
    d.push_back(i);
  }

  for(int i=0;i<m;i++) {
    int num;
    cin >> num;

    // 목표 원소의 위치 찾기
    auto it = find(d.begin(), d.end(), num);
    int idx = distance(d.begin(), it);

    // 연산 횟수 계산
    int op2 = idx; // 왼쪽으로 이동
    int op3 = d.size() - idx; // 오른쪽으로 이동

    if(op2 < op3) { // 왼쪽으로 이동
      count += op2;
      for(int j=0;j<op2;j++) {
        int numback = d.front();
        d.pop_front();
        d.push_back(numback);
      }
    } else { // 오른쪽으로 이동
      count += op3;
      for(int j=0;j<op3;j++) {
        int numfront = d.back();
        d.pop_back();
        d.push_front(numfront);
      }
    }

    // 원소 제거
    if(num == d.front()) {
      d.pop_front();
    }
  }

  cout<< count;
  return 0;
}
