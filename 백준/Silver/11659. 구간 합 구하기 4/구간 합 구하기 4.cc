#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,num,st,end;
    deque<int> q;
    q.push_back(0);

    cin >> n >> m;
    
    for(int i=0;i<n;i++) {
        cin >> num;
        q.push_back(q[i]+num);
    }

    for(int i=0;i<m;i++) {
        cin >> st >> end;

        cout << q[end]-q[st-1] << '\n';
    }   
}