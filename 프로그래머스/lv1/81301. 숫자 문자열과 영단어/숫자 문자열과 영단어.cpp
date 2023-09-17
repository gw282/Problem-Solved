#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int a = 0;
    string answer = "";
    string text = "";
    
    for(int i=0;i<s.size();i++) {
        if(s[i]>='0' && s[i]<='9') {
            answer += s[i];
        }
        else {
            text += s[i];
            cout << text << ' ';
            if(text == "zero") {
                answer+= '0';
                text = "";
            }
            else if(text == "one") {
                answer+= '1';
                text = "";
            }
            else if(text == "two") {
                answer+= '2';
                text = "";
            }
            else if(text == "three") {
                answer+= '3';
                text = "";
            }
            else if(text == "four") {
                answer+= '4';
                text = "";
            }
            else if(text == "five") {
                answer+= '5';
                text = "";
            }
            else if(text == "six") {
                answer+= '6';
                text = "";
            }
            else if(text == "seven") {
                answer+= '7';
                text = "";
            }
            else if(text == "eight") {
                answer+= '8';
                text = "";
            }
            else if(text == "nine") {
                answer+= '9';
                text = "";
            }
        }
    }
    a = stoi(answer);
    return a;
}