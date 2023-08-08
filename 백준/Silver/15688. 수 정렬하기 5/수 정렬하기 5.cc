/*
[2023-08-08 15688 수 정렬하기 5]
*/
#include <iostream>

using namespace std;

#define MAX 2000000

int arr[MAX+2]={0,};
int half = MAX/2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,tmp;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> tmp;
        arr[half+tmp]++;
    }

    for(int i=0;i<2000002;i++) {
        if(!arr[i]) continue;
        while(arr[i]--)
            cout << i-half << '\n';
    }
}