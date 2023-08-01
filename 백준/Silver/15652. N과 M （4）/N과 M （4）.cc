/*
[2023-08-01 15652 N과 M (4)]
base condition : m개까지 모두 선택된 경우 출력
recursion : 사용되지 않은 수를 순차적으로 배열에 입력, 사용됐다면 pass
*/
#include <iostream>

using namespace std;

int n,m;
int arr[10];
bool issued[10];

void func(int k) {
    if(k == m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!issued[i]) {
            if(k==0 || i>=arr[k-1]) { // 변경된 부분
                // arr 배열에 1)입력된 수가 없거나, 2)이전에 입력된 값보다 크거나 같은 경우
                arr[k]=i;
                // issued[i]=1; // 같은 수를 여러번 골라도 되므로
                func(k+1);
                issued[i]=0;
            }
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