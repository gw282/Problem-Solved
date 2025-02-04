#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 진수 변환
string convert(int n, int k) {
    string str = "";
    
    while(n/k!=0) {
        int m = n%k;
        str = to_string(m) + str;
        n = n/k;
    }
    str = to_string(n%k) + str;
    return str;
}

// 소수 판별
bool isPrime(long long n) {
    if (n < 2) return false;
    for(int i=2;i<=int(sqrt(n));i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string str;
    
    if(k == 10) str = to_string(n);
    else str = convert(n, k);
    
    long long num = 0;
    for(char &c : str) {
        int temp = c -'0';
        if(temp != 0) { // 0이 아닌 경우
            num = num * 10 + temp;
        } else { // 0이 나온 경우
            if(isPrime(num)) {
                answer++;
                cout << num << '\n';
            }
            num = 0;
        }
    }
    if(isPrime(num)) {
        answer++; 
        cout << num;
    }
    return answer;
}