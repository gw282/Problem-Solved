/*
[2023-08-21 1541 잃어버린 괄호]
*/
#include <iostream>
#include <sstream> // 문자열 파싱
#include <vector>
#include <string> // stoi

using namespace std;

string str;

vector<string> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    int sum = 0;
    bool flag = false;
    int pos;
    istringstream ss1(str);
    string buffer;

    char d1 = '+';
    char d2 = '-';

    while(getline(ss1,buffer,d1)) {
        istringstream ss2(buffer);
        while(getline(ss2,buffer,d2)) {
            v.push_back(buffer);
            if(!ss2.eof() && !flag) {
                v.push_back("-");
                flag = true;
            }
        }
    }

    pos = v.size();
    for(int i=0;i<v.size();i++) {
        if(v[i] == "-") {
            pos = i;
        }
    }

    for(int i=0;i<v.size();i++) {
        if(i < pos) sum += stoi(v[i]);
        else if(i > pos) sum -= stoi(v[i]);
    }
    
    cout << sum;
}