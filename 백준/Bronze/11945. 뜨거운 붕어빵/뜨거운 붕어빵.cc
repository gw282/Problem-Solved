#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str= "";

    int n, m;

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> str[j];
        }
         for(int j=m-1;j>=0;j--) {
            cout << str[j];
        }
        cout << '\n';
    }

}