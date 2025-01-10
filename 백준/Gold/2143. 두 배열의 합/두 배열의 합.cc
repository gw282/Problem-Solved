//=====================================================================
//   2143번:    두 배열의 합                   
//   @date:   2025-01-10              
//   @link:   https://www.acmicpc.net/problem/2143  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long arrA[1002], arrB[1002];
long long sumA[1002], sumB[1002];
vector<long long> partA, partB;
          
int main() {
  int t,n,m;
  long long ans = 0;

	cin >> t;

  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> arrA[i];
    // 배열의 누적합을 sum 배열에 저장
    sumA[i] = arrA[i] + sumA[i-1];
  }

  cin >> m;
  for(int i=1;i<=m;i++) {
    cin >> arrB[i];
    // B도 동일하게 진행
    sumB[i] = arrB[i] + sumB[i-1];
  }


  for(int i=1;i<=n;i++) {
    for(int j=0;j<i;j++) {
      // 부배열의 합을 벡터에 저장
      // sumA[0] = 0 
      partA.push_back(sumA[i]-sumA[j]);
    }
  }

  for(int i=1;i<=m;i++) {
    for(int j=0;j<i;j++) {
      // B도 동일하게 진행
      partB.push_back(sumB[i]-sumB[j]);
    }
  }

  // 벡터를 오름차순으로 정렬
  sort(partA.begin(),partA.end());
  sort(partB.begin(),partB.end());

  for(int i=0;i<partA.size();i++) {
    // A의 부분합 벡터 중 하나의 값을 뺀 나머지를 변수에 저장
    int remain = t - partA[i];
    // 나머지 값이 B의 부분합 벡터에 몇 개 존재하는지 확인
    ans += upper_bound(partB.begin(), partB.end(), remain) 
         - lower_bound(partB.begin(), partB.end(), remain);
  }

  cout << ans;

  return 0;
}
