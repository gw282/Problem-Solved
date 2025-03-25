#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1; // 바로 만들 수 있는 경우
    
    vector<set<int>> dp(8); // N을 i+1번 사용해서 만들 수 있는 숫자들 저장
    
    int repeatedNum = 0; // N을 연속으로 나열한 숫자 (5, 55, 555 ...)
    for (int i=0;i<8; i++) {
        repeatedNum = repeatedNum * 10 + N;
        dp[i].insert(repeatedNum);
    }
    
    // 사칙연산을 활용하여 숫자를 만드는 과정
    for (int i=1;i<8;i++) { // N을 (i+1)번 사용
        for (int j=0;j<i;j++) { // 앞부분 (j+1)번, 뒷부분 (i-j)번 사용
            for (int a : dp[j]) {
                for (int b : dp[i - j - 1]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }
        
        if (dp[i].count(number)) return i + 1; // 목표 숫자가 만들어지면 반환
    }
    
    return -1; // 8번 이내로 만들 수 없으면 -1 반환
}