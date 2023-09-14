using namespace std;
#include <iostream>
long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    long long ch_price = price;
    while(count--) {
        sum += ch_price;
        ch_price += price;
    }
    if(money >= sum) {
        answer = 0;
    }
    else answer = sum - money;
    return answer;
}