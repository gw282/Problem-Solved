/*
[2023-07-24 1074 Z]
귀납적인 생각을 적용해서 문제를 풀어보자
한 변의 길이: 2^n
4구간 중 어디 속하는지 판단한 뒤 재귀적으로 그 위치를 구해나간다
*/
#include <iostream>
#include <cmath>

using namespace std;

int func(int n, int r, int c) { // 구간 판단하는 함수
    if(n==0) return 0;
    int side = pow(2,n-1); // 2^(n-1)
    if(r<side && c<side) return func(n-1, r, c); // 1구간
    if(r<side && c>=side) return side*side + func(n-1, r, c-side); // 2구간
    if(r>=side && c<side) return 2*side*side + func(n-1, r-side, c); // 3구간
    return 3*side*side + func(n-1, r-side, c-side); // 4구간
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,r,c;
    cin >> n >> r >> c; // r: 가로, c: 세로
    cout << func(n,r,c);

}