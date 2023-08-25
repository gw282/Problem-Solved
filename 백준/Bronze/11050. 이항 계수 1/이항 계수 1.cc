#include <iostream>

using namespace std;

	int fac(int n) {
		if(n<=1) {
			return 1;
		}
		else 
			return n * fac(n-1);
	}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int n,k;
	cin >> n >> k;
	cout <<  (fac(n)/fac(k))/fac(n-k);


	return 0;
}