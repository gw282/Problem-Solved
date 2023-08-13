/*
[2023-08-13 1932 정수 삼각형]
끝항부터 차례로 더하면서 올라오기
결국 1층에 최댓값이 저장된다
*/
#include <iostream>

using namespace std;

int n;
int arr[502][502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i+1;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=n-2;i>=0;i--) {
        for(int j=0;j<=i;j++) {
            arr[i][j] += max(arr[i+1][j],arr[i+1][j+1]); // 아래층에서 왼쪽, 오른쪽 중 큰값 선택해서 윗층 값에 더함
        }
    }
    cout << arr[0][0]; // 1층에 최댓값이 저장됨
}