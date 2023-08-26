#include <iostream>

using namespace std;

int main() {
	int n,cnt =0;
	cin >> n;

	for(int i=1;i<=n;i++) {
		if(i % 125 == 0) cnt = cnt+3;
		else if(i % 25 == 0) cnt = cnt+2;
		else if(i % 5 == 0) cnt = cnt+1;
	}
	cout << cnt;

	return 0;
}