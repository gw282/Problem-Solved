/*
[2023-08-26 9465 스티커]
*/
#include <iostream>

using namespace std;

int arr[3][100002]; // 점수 입력받는 배열
int sum[3][100002]; // 누적 점수 저장하는 배열
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;

        cin >> n;

        for(int i=1;i<=n;i++) cin >> arr[1][i]; // 1행
        for(int i=1;i<=n;i++) cin >> arr[2][i]; // 2행

        sum[1][1] = arr[1][1]; // (1,1)
        sum[2][1] = arr[2][1]; // (2,1)
        sum[1][2] = arr[1][2] + arr[2][1]; // (1,2)
        sum[2][2] = arr[1][1] + arr[2][2]; // (2,2)

        for(int i=3;i<=n;i++) {
            sum[1][i] = arr[1][i] + max(sum[2][i-1], sum[2][i-2]); // ex) (1,3)의 누적최댓값: (1,3)의 값 + (2,2)의 누적값 or (2,1)의 누적값
            sum[2][i] = arr[2][i] + max(sum[1][i-1], sum[1][i-2]);
        }
        cout << max(sum[1][n], sum[2][n]) << '\n'; // 1행과 2행의 마지막 값 중 최댓값을 출력
    }
}