#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        unordered_map<string, int> clothes;

        for (int i = 0; i < k; ++i) {
            string name, part;
            cin >> name >> part;
            clothes[part]++;
        }

        int c = 1;
        for (auto & item : clothes) {
            c *= (item.second + 1); // 해당 종류의 개수 + 1
        }

        cout << c - 1 << '\n';
    }

    return 0;
}
