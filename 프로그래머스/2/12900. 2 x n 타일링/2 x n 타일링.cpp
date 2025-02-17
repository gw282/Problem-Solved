#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int arr[60002];
    arr[1] = 1;
    arr[2] = 2;

    for(int i=3;i<=n;i++) {
        arr[i] = (arr[i-2] + arr[i-1]) % 1000000007;
    }
    
    answer = arr[n];
    return answer;
}