#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector <int> v(4);
    for(int i=0;i<survey.size();i++) {
        if(survey[i] == "RT") {
            v[0] = v[0] - (choices[i]-4);
        }
        if(survey[i] == "CF") {
            v[1] = v[1] - (choices[i]-4);
        }
        if(survey[i] == "JM") {
            v[2] = v[2] - (choices[i]-4);
        }
        if(survey[i] == "AN") {
            v[3] = v[3] - (choices[i]-4);
        }
        if(survey[i] == "TR") {
            v[0] = v[0] + choices[i]-4;
        }
        if(survey[i] == "FC") {
            v[1] = v[1] + choices[i]-4;
        }
        if(survey[i] == "MJ") {
            v[2] = v[2] + choices[i]-4;
        }
        if(survey[i] == "NA") {
            v[3] = v[3] + choices[i]-4;
        }
    }
    
    for(int i=0;i<v.size();i++) {
        if(v[i] >=0) {
            if(i==0) answer += 'R';
            if(i==1) answer += 'C';
            if(i==2) answer += 'J';
            if(i==3) answer += 'A';
        }
        else {
            if(i==0) answer += 'T';
            if(i==1) answer += 'F';
            if(i==2) answer += 'M';
            if(i==3) answer += 'N';
        }
    }
    return answer;
}