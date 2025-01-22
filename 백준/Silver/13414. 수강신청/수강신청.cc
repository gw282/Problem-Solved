//=====================================================================
//   13414번:    수강신청                   
//   @date:   2025-01-22              
//   @link:   https://www.acmicpc.net/problem/13414  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int k, l;
unordered_map<string, int> num;
vector<pair<string,int>> ord;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	cin >> k >> l;

  for(int i=0;i<l;i++) {
    string str;
    cin >> str;
    
    num[str] = i;
  }

  for(auto i : num) {
    ord.push_back(i);
  }

  sort(ord.begin(),ord.end(), cmp);

  for(int i=0;i<min(k,(int)ord.size());i++) {
    cout << ord[i].first << '\n';
  }

  return 0;
}
