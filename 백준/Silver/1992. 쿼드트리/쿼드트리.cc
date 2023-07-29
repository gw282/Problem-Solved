/*
[2023-07-29 1992 쿼드트리]
귀납적인 생각을 적용해서 문제를 풀어보자 + 분할 정복해보자
영상 값(0,1)이 불일치하면 그 부분을 4등분해서 일치하는지 확인하는 작업을 반복
불일치 여부 확인 => 일치 시 pass, 불일치 시 4등분 후 불일치 여부 확인
반드시 z방향으로 분할 정복해야함 => 순서가 중요한 문제 (개수 세는 경우는 순서 중요x)
*/
#include <iostream>

using namespace std;

string str[64]; // 문자열을 입력받으므로 string 배열

void func(int x, int y, int n) {
    bool flag = true;
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            if(str[i][j] != str[x][y]) {
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    if(!flag) { // z방향으로 분할정복
        cout << '('; // 압축하지 못하는 경우 시작이므로 괄호 열기
        func(x,y,n/2); // 1 (0,0)
        func(x,y+n/2,n/2); // 2 (0,1)
        func(x+n/2,y,n/2); // 3 (1,0)
        func(x+n/2,y+n/2,n/2); // 4 (1,1)
        cout << ')';
    }
    else {
        if(str[x][y] == '0') cout << '0';
        else cout << '1';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> str[i];
    }
    func(0,0,n);
}