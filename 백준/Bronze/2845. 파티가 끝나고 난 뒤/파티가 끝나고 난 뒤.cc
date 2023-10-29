#include <iostream>
using namespace std;

int main() {
    int n, p,a;
    cin >> n >> p;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        cout << a - n*p << ' ';
    }
}