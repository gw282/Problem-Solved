#include <iostream>
#include <algorithm>

using namespace std;

int a[1001], d[1001];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int n,cnt,max_v=0;
	cin >> n;

	a[0] = 0;
	d[0] = 0;
	
	for(int i=1;i<=n;i++) {
		cin >> a[i];	
	}

	for(int i=1;i<=n;i++) {
		cnt=0;
		for(int j=0;j<i;j++) {
			if(a[j]<a[i]) {
				cnt = d[j]+1;
				d[i] = max(cnt,d[i]);
				max_v = max(max_v,d[i]);
			}
		}
	}
	cout << max_v;

	return 0;
}