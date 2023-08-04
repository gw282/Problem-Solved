/*
[2023-08-04 15657 N과 M (8)]
base condition : m개까지 모두 선택된 경우 출력
recursion : 사용되지 않은 수를 순차적으로 배열에 입력, 사용됐다면 pass
*/
#include <iostream>
#include <algorithm> // sort

using namespace std;

int arr[10];
int num[10]; //isused는 중복 사용을 피하기 위해 사용한 것이므로 지워도됨

int n,m;

void func(int k) {
    if(k==m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << ' ';
        }
    cout << '\n';
    return;
    }

    for(int i=1;i<=n;i++) {
        if(k==0 || arr[k-1]<=num[i]) { //k가 첫입력이거나, 이전항이 현재항보다 크거나 같은 경우(비내림차순)
            arr[k]=num[i];
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

    sort(num+1,num+n+1); // 오름차순 정렬
    func(0);
}