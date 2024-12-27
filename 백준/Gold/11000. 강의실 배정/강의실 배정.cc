//=====================================================================
//   11000번:    강의실 배정                   
//   @date:   2024-12-27              
//   @link:   https://www.acmicpc.net/problem/11000  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ST first
#define EN second

int n;
vector<pair<int,int>> lec;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    int s, t;
    cin >> s >> t;
    lec.push_back({s, 1});
    lec.push_back({t, -1});
  }
  sort(lec.begin(), lec.end());

  int ans = 0; // 강의실의 최대 개수 (최종적으로 출력할 값)
  int curtime = lec[0].ST; // 현재 처리 중인 시간 (lec 배열의 가장 첫 번째 강의 시작 시간으로 초기화)
  int curroom = 0; // 현재 시간에 사용 중인 강의실의 개수
  int cur = 0; // lec 배열에서 현재 처리 중인 이벤트의 인덱스

  while(1){
    while(cur < 2*n && lec[cur].ST == curtime){
      curroom += lec[cur].EN; // 강의 시작이면 +1, 종료면 -1
      cur++;      
    }
    ans = max(ans, curroom); // 현재 필요한 강의실의 최대값 갱신
    if(cur == 2*n) break; // 모든 강의실을 처리하면 종료
    curtime = lec[cur].ST; // 다음 시간으로 이동
  }
  cout << ans;
}
