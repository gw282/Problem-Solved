/*
[2023-09-08 1991 트리 순회]
*/
#include <iostream>

using namespace std;

int n;
int pa[28];
int lc[28];
int rc[28];

void preorder(int cur) { // 전위 순회
    cout << char(cur + 'A' - 1);
    if(lc[cur] != 0) preorder(lc[cur]);
    if(rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) { // 중위 순회
    if(lc[cur] != 0) inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) { // 후위 순회
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char p, l, r;
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> p >> l >> r;
        pa[i] = p - 'A' + 1;
        if(l != '.') lc[pa[i]] = l - 'A' + 1;
        if(r != '.') rc[pa[i]] = r - 'A' + 1;
    }
    
    preorder(1);
    cout << '\n';
    inorder(1);
    cout <<'\n';
    postorder(1);
}