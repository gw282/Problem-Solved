/*
[2023-08-02 9663 N-Queen]
base condition : 퀸 배치 성공 시(n개 배치 시) cnt에 1 더함
recursion : 퀸이 갈 수 있는 경로(행을 제외한 세 가지 방향)에 다른 퀸이 없는지 확인
isused1: 열이므로 i로 표시
isused2: / 방향 대각선이므로 행+열이면 대각선끼리 같은 값을 가짐 -> cur+i로 표시
isused3: \ 방향 대각선이므로 행-열+n-1이면 대각선끼리 같은 값을 가짐 -> cur-i+n-1로 표시
*/
#include <iostream>

using namespace std;

bool isused1[30]; // 열 체크하는 배열
bool isused2[30]; // / 방향 체크하는 배열
bool isused3[30]; // \ 방향 체크하는 배열

int cnt=0;
int n;

void func(int cur) { // cur에 해당하는 행에 말 배치
    if(cur==n) { // 퀸 배치 성공 시
        cnt++;
        return;
    }

    for(int i=0;i<n;i++) { // 행: cur, 열: i에 퀸 배치
        if(isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]) continue;
        // 열 or 대각선에 이미 퀸이 존재하면 pass
        isused1[i]=1;
        isused2[i+cur]=1;
        isused3[cur-i+n-1]=1;
        func(cur+1);  // 다음 퀸 위치를 정하기 위해 func 호출
        isused1[i]=0; // 모든 경우를 살펴봤으니 배열의 해당 값을 false로 변경
        isused2[i+cur]=0;
        isused3[cur-i+n-1]=0; 
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    func(0);
    cout << cnt;
}