#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d,sum1;
    int e,f,g,h,sum2;

    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;
    
    sum1 = a+b+c+d;
    sum2 = e+f+g+h;

    if(sum1>=sum2) cout << sum1;
    else cout << sum2;

}