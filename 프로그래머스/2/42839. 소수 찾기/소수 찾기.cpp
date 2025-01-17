#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    
    for(int i = 2;i*i <= num;i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> nums;
    
    sort(numbers.begin(),numbers.end());
    
    do {
        for (int i = 1; i <= numbers.size(); ++i) {
            string temp = numbers.substr(0, i); // 현재 순열의 부분 문자열 생성
            int num_temp = stoi(temp); // 부분 문자열을 숫자로 변환
            if (isPrime(num_temp)) {
                nums.insert(num_temp); // 소수인 경우 집합에 추가
            }
        } 
    } while (next_permutation(numbers.begin(), numbers.end())); // 다음 순열 생성
    
    return nums.size();
}