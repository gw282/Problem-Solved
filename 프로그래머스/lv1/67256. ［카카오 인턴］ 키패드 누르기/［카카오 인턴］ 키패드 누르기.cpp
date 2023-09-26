#include <string>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftrow=0, leftcol=3;
    int rightrow=2, rightcol=3;
    int l,r;
    for(int i=0;i<numbers.size();i++) {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            leftrow = 0;
            if(numbers[i] == 1) {
                leftcol = 0;
            }
            else if(numbers[i] == 4) {
                leftcol = 1;
            }
            else if(numbers[i] == 7) {
                leftcol = 2;
            }
            answer += "L";
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            rightrow = 2;
            if(numbers[i] == 3) {
                rightcol = 0;
            }
            else if(numbers[i] == 6) {
                rightcol = 1;
            }
            else if(numbers[i] == 9) {
                rightcol = 2;
            }
            answer += "R";
        }
        else {
            int b;
            if(numbers[i] == 2) {
                b = 0;
            }
            else if(numbers[i] == 5) {
                b = 1;
            }
            else if(numbers[i] == 8) {
                b = 2;
            }
            else if(numbers[i] == 0) {
                b = 3;
            }
            l = abs(leftrow-1) + abs(leftcol-b);
            r = abs(rightrow-1) + abs(rightcol-b);
            
            if(l>r) {
                answer += "R";
                rightrow = 1;
                rightcol = b;
            }
            else if(l<r) {
                answer += "L";
                leftrow = 1;
                leftcol = b;
            }
            else if(l==r) {
                if(hand == "right") {
                    answer += "R";
                    rightrow = 1;
                    rightcol = b;
                }
                else if(hand == "left") {
                    answer += "L";
                    leftrow = 1;
                    leftcol = b;
                }
            }
        }
    }
    
    return answer;
}