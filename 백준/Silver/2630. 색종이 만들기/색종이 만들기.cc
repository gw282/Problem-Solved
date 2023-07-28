#include <iostream>
#include <cstring>
#define MAX 129

using namespace std;

int arr[MAX][MAX];
int w=0,b=0;

void f(int n, int x, int y) {
    int cnt = 0;
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            if(arr[i][j]) {
                cnt++;
            }
        }
    }
    if(!cnt) w++;
    else if(cnt == n*n) b++;
    else {
        f(n/2,x,y);
        f(n/2,x,y+n/2);
        f(n/2,x+n/2,y);
        f(n/2,x+n/2,y+n/2);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    memset(arr,0,sizeof(arr));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    f(n,0,0);
    cout << w << '\n' << b;
    return 0;
}