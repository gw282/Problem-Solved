#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // 벡터 A를 오름차순으로 정렬
    sort(A.begin(), A.end());
    
    // 벡터 B를 내림차순으로 정렬
    sort(B.begin(), B.end(), greater<int>());
    
    // 정렬된 벡터 A와 B의 요소를 곱하여 합산
    for (int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }
   
    return answer;
}