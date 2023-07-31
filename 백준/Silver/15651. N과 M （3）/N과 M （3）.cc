/*
[2023-07-31 15651 N과 M (3)]
base condition : m개까지 모두 선택된 경우 출력
recursion : 사용되지 않은 수를 순차적으로 배열에 입력, 사용됐다면 pass
*/
#include <iostream>

using namespace std;

int n,m;
int arr[10];
bool issued[10];

void func(int k) { // 현재까지 선택한 개수: k      
    if(k == m) { // m개까지 선택했다면
        for(int i=0;i<m;i++) {
            cout << arr[i] << ' '; // 기록해둔 수 출력
        }
        cout <<'\n';
        return;
    }
    for(int i=1;i<=n;i++) { // 1~n까지에 대해
        if(!issued[i]) { // i가 사용되지 않으면
            arr[k]=i; // k번째 수를 i로 설정
            // issued[i] = 1; // i 사용됨을 표시
            func(k+1); // 다음 수를 정하기 위해 func 호출
            issued[i] = 0; // k번째 수를 i로 정한 모든 경우를 살펴봤으니 i를 사용되지 않음으로 변경
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);
    
    return 0;
}