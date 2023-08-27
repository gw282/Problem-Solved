#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	int n,m;
	cin >> n;
	int a[n];

	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	sort(a,a+n);

	cin >> m;
	int b[m];
	for(int i=0;i<m;i++) {
		cin >> b[i];
	}

	for(int i=0;i<m;i++) {
		int st=0,en=n-1,mid,ans=0;
		while(st<=en) {
		mid = (st+en)/2;
			if(a[mid]<b[i]) {
				st = mid+1;
			}
			else if(a[mid]>b[i]) {
				en = mid-1;
			}
			else {
				ans = 1;
				st = en+1;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}