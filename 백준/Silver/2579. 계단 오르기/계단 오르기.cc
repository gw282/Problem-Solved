/*
[2023-08-14 2579 계단 오르기]
*/
#include <iostream>

using namespace std;

int n;
int arr[302][3]; 
// 0: 계단에 쓰여 있는 점수
// 1: 연속한 계단 수 = 1
// 2: 연속한 계단 수 = 2 -> 반드시 다다음 계단으로 가야함

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> arr[i][0];
    }
    if(n==1) {
        cout << arr[1][0];
        return 0;
    }

    arr[1][1] = arr[1][0]; // (1)
    arr[1][2] = 0; // (1)항에서 연속한 계단 수가 2가 될 수 없으므로 0
    arr[2][1] = arr[2][0]; // (2)
    arr[2][2] = arr[1][0] + arr[2][0]; // (1) + (2)

    for(int i=3; i<=n;i++) {
        arr[i][1] = max(arr[i-2][1],arr[i-2][2]) + arr[i][0];
        // 전전 항에서 연속한 계단 수가 1인 경우도 가능하고,
        // 연속한 계단 수가 2인 경우는 반드시 i 칸으로 와야 함
        arr[i][2] = arr[i-1][1] + arr[i][0];
        // 연속한 계단 수가 2가 되려면 이전 항만 가능 함
    }
    cout << max(arr[n][1],arr[n][2]); // 마지막 계단에 저장된 배열값 중 큰 값 출력
}