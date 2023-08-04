/*
[2023-08-04 15656 N과 M (7)]
base condition : m개까지 모두 선택된 경우 출력
recursion : 사용되지 않은 수를 순차적으로 배열에 입력, 사용됐다면 pass
*/
#include <iostream>
#include <algorithm> // sort
using namespace std;

int arr[10];
int num[10];
bool isused[10];

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
        if(!isused[i]) {
            arr[k]=num[i];
            //isused[i]=1; // 똑같은 수가 계속 사용될 수 있으므로
            func(k+1);
            isused[i]=0;
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