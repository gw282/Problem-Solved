#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;

double solution(vector<int> arr) {
    double answer = 0;
    for(int i=0;i<arr.size();i++) {
        answer += arr[i];
    }
    answer /= arr.size();
    return answer;
}