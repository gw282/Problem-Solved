#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i = 0; i < numbers.size(); ++i) {
        // 숫자가 짝수인 경우
        if (numbers[i] % 2 == 0)
            answer.push_back(numbers[i] + 1);  // 짝수는 +1을 더함
        else {
            long long bitMask = 1;  // 비트 마스크, 1부터 시작
            // 숫자의 이진 표현에서 첫 번째 0을 찾음
            while (true) {
                // 숫자의 해당 비트가 1이면, 계속해서 왼쪽으로 이동
                if ((numbers[i] & bitMask) == 0) break;
                bitMask *= 2;
            }
         
            // 첫 번째 0을 찾아서 그 비트를 1로 바꿔줌
            answer.push_back(numbers[i] + (bitMask / 2));
        }
    }
    
    return answer;
}
