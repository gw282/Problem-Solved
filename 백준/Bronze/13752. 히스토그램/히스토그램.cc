#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n;

    while(n--) {
        cin >> m;
        for(int i=0;i<m;i++) {
            cout << "=";
        }
        cout <<'\n';
    }

}