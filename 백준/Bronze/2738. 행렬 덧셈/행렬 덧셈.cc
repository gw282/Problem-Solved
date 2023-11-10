#include <iostream>
using namespace std;

int arr1[101][101], arr2[101][101];

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
		for (int k = 0; k < m; k++) 
			cin >> arr1[i][k];


	for (int i = 0; i < n; i++) 
		for (int k = 0; k < m; k++) 
			cin >> arr2[i][k];
	

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) 
			cout << arr1[i][k] + arr2[i][k] << ' ';
		cout << '\n';
	}
}