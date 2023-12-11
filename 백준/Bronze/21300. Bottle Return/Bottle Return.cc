#include <iostream>
using namespace std;

int main(void) {
    int tmp;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> tmp;
        sum += tmp;
    }
    cout << sum*5;
    return 0;
}