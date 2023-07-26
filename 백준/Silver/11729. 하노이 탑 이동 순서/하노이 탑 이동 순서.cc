/*
[2023-07-25 11729 하노이 탑 이동 순서]
귀납적인 생각을 적용해서 문제를 풀어보자
1. 함수의 정의 : func(int a, int b, int n)
2. base condition : n == 1
3. 재귀 식 : 1+2+3 = 6 
*/
#include <iostream>
#include <cmath>

using namespace std;

void func(int a, int b, int n) { // a위치에서 b위치로 이동, n: 원판 개수
    if(n==1) { // base condition : n 원판 a => b 이동
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a,6-a-b,n-1); // n-1개 원판 a => 6-a-b 이동
    cout << a << ' ' << b << '\n';
    func(6-a-b,b,n-1); // n-1개 원판 6-a-b => b 이동
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

     cout << (1<<n) - 1 << '\n';
    func(1,3,n);
}