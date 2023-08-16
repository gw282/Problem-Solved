#include <iostream>

using namespace std;

int arr[1000];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int n;
	cin >> n;
	arr[1]=1;
	arr[2]=2;

	for(int i=3;i<=n;i++) {
		arr[i] = arr[i-1]+arr[i-2];
		arr[i] = arr[i]%10007;
	}
	cout << arr[n];
	return 0;
}