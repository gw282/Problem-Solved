#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,cnt=0;
    int arr[5];

    cin >> n;
    for(int i=0;i<5;i++) {
        cin >> arr[i];
        if(arr[i] == n) cnt++;
    }
    cout << cnt;

}