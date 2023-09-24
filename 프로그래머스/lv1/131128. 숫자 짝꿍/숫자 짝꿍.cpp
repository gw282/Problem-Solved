#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int arrX[10] ={0,};
    int arrY[10] ={0,};
    
    for(int i=0;i<X.size();i++) {
        arrX[X[i]-'0']++;
    }
    for(int i=0;i<Y.size();i++) {
        arrY[Y[i]-'0']++;
    }

    for(int i=9;i>=1;i--) {
        int a = min(arrX[i],arrY[i]);
        while(a--) answer+= to_string(i);
    }
    
    int a = min(arrX[0],arrY[0]);
    if(answer.size() == 0 && a>0) answer+= "0";
    else while(a--) answer+= "0";
    
    if(answer.size() == 0) answer+= "-1";

    return answer;
}