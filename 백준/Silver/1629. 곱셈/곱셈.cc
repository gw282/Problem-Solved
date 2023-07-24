#include <iostream>

using namespace std;

long long a,b,c,n;

int pow(int b) {
	if(b==0) return 1; // a*0 
	if(b==1) return a % c; // a*1

	long long n = pow(b/2); // b/2제곱수를 쪼개서 계산함
	// b를 계속 2로 나누어 연산하고 연산한 값을 저장
	if(b%2==0) // b가 짝수라면
		return n*n%c; // b/2제곱수를 제곱해줌
	else // b가 홀수라면
		return (n*n%c)*a%c; // 위의 케이스에 a를 곱해줌
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> a >> b >> c;

	cout << pow(b) % c;

	return 0;
}