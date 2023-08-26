#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	int n;

	while(b!=0) {
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int t;
	cin >> t;
		
	while(t--) {
		int n;
		cin >> n;

		vector<int> v;
		long long sum = 0;
		
		while(n--) {
			int num;
			cin >> num;
			
			for(int i=0;i<v.size();i++) {
				sum += gcd(v[i], num);
			}
			v.push_back(num);
		}
		cout << sum << '\n';
	}
	return 0;
}