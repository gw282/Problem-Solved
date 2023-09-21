/*
[2023-09-21 9655]
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;    
    if(n%2==0) cout << "CY";
    else cout << "SK";
}