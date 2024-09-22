#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // left부터 right까지 순회하며 필요한 값만 계산
    for (long long i=left;i<=right;i++) {
        int row = i/n;  // 행 계산
        int col = i%n;  // 열 계산
        answer.push_back(max(row+1, col+1));  // 해당 위치의 값을 계산
    }
    
    return answer;
}
