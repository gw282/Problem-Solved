/*
[2023-08-06 15666 N과 M (12)]
base condition : m개까지 모두 선택된 경우 출력
recursion : 사용되지 않은 수를 순차적으로 배열에 입력, 사용됐다면 pass
- 중복 제거하는 방법: 변수 생성하여 이전값을 저장해두고, 현재값과 이전값이 같으면 pass
*/
#include <iostream>
#include <algorithm> // sort
using namespace std;

int n,m;

int arr[10];
int num[10];

void func(int k) {
    if(k==m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp=0;
    for(int i=1;i<=n;i++) {
        if(tmp==num[i]) continue;
        if(!k || arr[k-1]<=num[i]) {
            arr[k] = num[i];
            tmp = num[i];
            func(k+1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        cin >> num[i];
    }

    sort(num+1,num+n+1);
    func(0);
}