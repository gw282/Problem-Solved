#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
    if(n==0) return m;
    return gcd(m%n, n);
}

int lcm(int n, int m) {
    return n / gcd(n,m) * m;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n,m));
    return answer;
}