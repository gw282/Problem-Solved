/*
[2023-08-02 15654 N과 M (5)]
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
            arr[k]=num[i]; // 그냥 i가 아닌 정렬된 배열의 i번째 수를 arr 배열에 저장
            isused[i]=1;
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

    sort(num+1,num+n+1); // 숫자를 오름차순으로 정렬
    func(0);

    return 0;
}   