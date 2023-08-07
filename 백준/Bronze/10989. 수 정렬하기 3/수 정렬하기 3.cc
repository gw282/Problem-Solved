/*
[2023-08-07 10989 수 정렬하기 3]
merge sort -> 천만 개 이므로 시간초과 발생
입력받은 수를 카운팅하기 위해 해당 숫자 배열에 ++
*/
#include <iostream>

using namespace std;

int arr[10002]={0,};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,tmp;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> tmp;
        arr[tmp]= arr[tmp]+1;
    }

    for(int i=0;i<10001;i++) {
        if(arr[i] == 0) continue;
        for(int j=0;j<arr[i];j++) {
            cout << i << '\n';
        }
    }
}