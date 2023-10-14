#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,v,cnt=0;
    int arr[102];

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    
    cin >> v;
    for(int i=0;i<n;i++) {
        if(v==arr[i]) cnt++;
    }
    cout << cnt;
}