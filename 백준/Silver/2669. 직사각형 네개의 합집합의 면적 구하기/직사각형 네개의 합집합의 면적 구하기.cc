/*
[2023-09-29 2669 직사각형 네개의 합집합의 면적 구하기]
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, y1, y2;
    int cnt = 0;
    int arr[101][101]={0,};
    
    for(int k=0;k<4;k++) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i=x1;i<x2;i++) {
            for(int j=y1;j<y2;j++) {
                arr[i][j]++;
            }
        }
    }

    for(int i=1;i<101;i++) {
        for(int j=1;j<101;j++) {
            if(arr[i][j]>0) cnt++;
        }
    }
    cout << cnt;
}