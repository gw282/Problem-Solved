#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int sum=0;
    for(int i=0;i<5;i++) {
        cin >> n;
        sum += n;
    }
    cout << sum;
}