//=====================================================================
//   7662번:    이중 우선순위 큐                   
//   @date:   2025-01-27              
//   @link:   https://www.acmicpc.net/problem/7662  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <set>
using namespace std;

int t; // 테스트 데이터 개수
int k; // 연산 개수

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    int k;
    cin >> k;

    multiset<int> set;

    while(k--){
      char com;
      cin >> com;
      if(com == 'D'){ // 삭제
        int q;
        cin >> q;
        if(set.empty()) continue; // 비어있으면 삭제하지 않음
        if(q == 1) set.erase(prev(set.end())); // 최댓값 삭제
        else set.erase(set.begin()); // 최솟값 삭제
      }
      else{ // 삽입
        int q;
        cin >> q;
        set.insert(q);
      }
    }
    if(set.empty()) cout << "EMPTY\n"; // 큐가 비었을 때
    else {
      cout << *prev(set.end()) << ' ' << *set.begin() << '\n';
    }
  }
}