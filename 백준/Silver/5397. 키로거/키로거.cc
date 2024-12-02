/*
[2023-12-02 5397 키로거]
*/
#include <iostream>
#include <list>

using namespace std;

int n;
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> str;

        list<char> L = {};
        auto letter = L.begin();
        
        for(int j = 0; j < str.length(); j++) {
           if(str[j] == '<') {
                if(letter != L.begin()) {
                    letter--;
                }
           }
            else if(str[j] == '>') {
                if(letter != L.end()) {
                    letter++;
                    }
            }
            else if(str[j] == '-') {
                if(letter != L.begin()) {
                    letter--;
                    letter = L.erase(letter);
                }
            }
            else L.insert(letter, str[j]);
        }
        for (char c : L) {
            cout << c;
        }
        cout << '\n';
    }
}