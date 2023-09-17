#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string s1="";
    string s2="";
    for(int i=0;i<arr1.size();i++) {
        s1 = "";
        s2 = "";
        int a = arr1[i];
        int b = arr2[i];
        
        while(s1.size()<n) {
            s1 += to_string(a%2);
            a = a/2;
        }
        reverse(s1.begin(),s1.end());
    
        while(s2.size()<n) {
            s2 += to_string(b%2);
            b = b/2;
        }
        reverse(s2.begin(),s2.end());
        
        for(int j=0;j<s1.size();j++) {
            if(s1[j] == '1') s1[j] = '#';
            else s1[j] = ' ';
        }
        
        for(int j=0;j<s2.size();j++) {
            if(s2[j] == '1') s2[j] = '#';
            else s2[j] = ' ';
        }
        for(int j=0;j<s2.size();j++) {
            if(s2[j] == '#') s1[j] = '#';
        }      
        answer.push_back(s1);
    }
    return answer;
}