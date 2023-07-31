#include <iostream>
using namespace std;

int n,m;
int arr[10];
bool issued[10];

void func(int k) {
    if(k == m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << ' ';
        }
        cout <<'\n';
        return;
    }
    for(int i=1;i<=n;i++) {
        if(!issued[i]) {
            arr[k]=i;
            issued[i] = 1;
            func(k+1);
            issued[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    func(0);
    
    return 0;
}