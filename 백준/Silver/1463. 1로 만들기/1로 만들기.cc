#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int x;
	cin >> x;

	for(int i=2;i<=x;i++) {
		arr[i] = arr[i-1] + 1;

		if(i%2 == 0) {
			arr[i] = min(arr[i],arr[i/2]+1);
		}
		if(i%3 == 0) {
			arr[i] = min(arr[i],arr[i/3]+1);
		}
	}
	cout << arr[x];
	return 0;
}