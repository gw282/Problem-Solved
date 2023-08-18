/*
[2023-08-08 15688 수 정렬하기 5]
*/
#include <iostream>

using namespace std;

int n;

long long arr[102][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    arr[1][0] = 0;
    for(int i=1;i<=9;i++) {
        arr[1][i] = 1;
    }
    
    for(int i=2;i<=n;i++) {
        for(int j=0;j<=9;j++) {
            if(j==0) {
                arr[i][j] = arr[i-1][1];
            }
            else if(j==9) {
                arr[i][j] = arr[i-1][8];
            }
            else {
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]);
            }
            arr[i][j] %= 1000000000;
        }
    }

    for(int i=1;i<=9;i++) {
        arr[n][0] += arr[n][i];
        arr[n][0] %= 1000000000;
    }
    
    cout << arr[n][0];
}