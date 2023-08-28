#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int low(int*arr,int target,int size) {
	int mid,start,end;
	start = 0, end = size-1;

	while(end>start) {
		mid = (start+end)/2;
		if (arr[mid] >= target) 
			end = mid;
			else start =  mid + 1;
	}
	return end;
}

int up(int*arr,int target,int size) {
	int mid,start,end;
	start = 0, end = size-1;

	while(end>start) {
		mid = (start+end)/2;
		if (arr[mid] > target) 
			end = mid;
			else start =  mid + 1;
	}
	return end;
}

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

	int result[500000]={0,};

	for(int i=0;i<m;i++) {
		int l, u;
		l = low(a,b[i],n);
		u = up(a,b[i],n);
		if(u == n-1 && a[n-1] == b[i])
			u++;
			result[i] = u-l;
	}
	for(int i=0;i<m;i++) {
		cout << result[i] << ' ';
	}

	return 0;
}