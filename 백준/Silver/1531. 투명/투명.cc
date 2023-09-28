/*
[2023-09-]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int x1, x2, y1, y2;
    int cnt = 0;
    int arr[101][101]={0,};

    cin >> n >> m;
    
    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=x1;i<=x2;i++) {
            for(int j=y1;j<=y2;j++) {
                arr[i][j]++;
            }
        }
    }

    for(int i=1;i<101;i++) {
        for(int j=1;j<101;j++) {
            if(arr[i][j]>m) cnt++;
        }
    }
    cout << cnt;
}