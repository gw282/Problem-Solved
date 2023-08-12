/*
[2023-08-12 12852 1로 만들기2]
새로운 배열에 최솟값을 만들어 주게한 수를 저장함
n에서 계속해서 최솟값을 만들어준 수를 배열을 찾아가며 출력
*/
#include <iostream>

using namespace std;

int arr[1000002]; // 최솟값을 저장
int arr2[1000002]; // 배열 안에 경로를 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,cur;
    cin >> n;

    arr[1] = 0;
    cur = n;

    for(int i=2;i<=n;i++) {
        arr[i] = arr[i-1]+1;
        arr2[i] = i-1;

        if(i%2==0 && arr[i] > arr[i/2]+1) { // 3번보다 2번이 최솟값일 경우
            arr[i] = arr[i/2]+1;
            arr2[i] = i/2;
        }
        if(i%3==0 && arr[i] > arr[i/3]+1) { // 3번보다 1번이 최솟값일 경우
            arr[i] = arr[i/3]+1;
            arr2[i] = i/3;
        }
    }

    cout << arr[n] << '\n'; // 최솟값
    while(1) {
        cout << cur << ' '; // 순서 출력
        if(cur==1) return 0; // 1을 만들었으면 종료
        cur = arr2[cur]; // 최솟값을 만들어준 수 출력 -> 계속 반복..
    }

}