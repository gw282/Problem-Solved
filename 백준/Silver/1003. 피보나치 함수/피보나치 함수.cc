#include <iostream>
#include <queue>

using namespace std;

int arr[42] = {0,1,};

int fibonacci(int n) {
    if(n==0 || n==1) return arr[n];
    else if(arr[n] == 0) {
        arr[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return arr[n];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;

        if(n==0) cout << "1 0" << '\n';
        else cout << fibonacci(n-1) << ' ' << fibonacci(n) << '\n';
    }
}