/*
[2023-08-31 1822 차집합]
binary search를 통해 없는 해당 값이 벡터 배열에 존재하는지 확인
*/
#include <iostream>
#include <algorithm> // stable_sort, binary_search
#include <vector>

using namespace std;

vector <int> a; // a집합
vector <int> b; // b집합
vector <int> c; // 없는 원소 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int el1, el2;
    int num, cnt=0;

    cin >> el1 >> el2;

    for(int i=0;i<el1;i++) {
        cin >> num;
        a.push_back(num);
    }

    for(int i=0;i<el2;i++) {
        cin >> num;
        b.push_back(num);
    }

    stable_sort(a.begin(),a.end());
    stable_sort(b.begin(),b.end()); // sorting

    for(int i=0;i<el1;i++) {
        if(!binary_search(b.begin(),b.end(),a[i])) { // 원소가 없다면!
            cnt++;
            c.push_back(a[i]);
        } 
    }
    
    if(c.empty()) { // 집합 A에는 속하면서 집합 B에는 속하지 않는 원소가 없다면 
        cout << 0;
        return 0;
    }
    
    cout << cnt << '\n';

    for(int i=0;i<c.size();i++) { // 저장된 원소 출력
        cout << c[i] << ' ';
    }
}