#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // a와 b가 만나지 않을 때까지 반복
    while (a != b) {
        a = (a + 1) / 2; // 다음 라운드 번호로 갱신
        b = (b + 1) / 2; // 다음 라운드 번호로 갱신
        answer++; // 라운드 수 증가
    }

    return answer;
}
