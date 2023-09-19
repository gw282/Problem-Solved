/*
[2023-09-19 국영수]
*/
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
 
 
struct info {
    string name;
    int korean;
    int english;
    int math;
};
vector <info> v;

bool cmp(const info& x, const info& y) {
        if(x.korean != y.korean) return x.korean > y.korean;
        if(x.english != y.english) return x.english < y.english;
        if(x.math != y.math) return x.math > y.math;
        return x.name < y.name;

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string name; 
    int a, b, c;

    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> name >> a >> b >> c;

        info inform;
        inform.name = name;
        inform.korean = a;
        inform.english = b;
        inform.math = c;
        
        v.push_back({inform.name,inform.korean,inform.english,inform.math});

    }

    stable_sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++) {
        cout << v[i].name << '\n';
    }
}