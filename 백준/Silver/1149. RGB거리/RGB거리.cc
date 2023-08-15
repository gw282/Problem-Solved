#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	int arr[1000][3];
	int cost[3];
	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[0][2] = 0;
	
	cin >> n;

	for(int i=1;i<=n;i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		arr[i][0] = min(arr[i-1][1],arr[i-1][2])+cost[0];
		arr[i][1] = min(arr[i-1][0],arr[i-1][2])+cost[1];
		arr[i][2] = min(arr[i-1][0],arr[i-1][1])+cost[2];
	}
	cout << min(arr[n][2],min(arr[n][0],arr[n][1]));

	return 0;
}