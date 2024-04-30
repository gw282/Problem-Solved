#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string sort_by_value;

bool compare(vector<int>& a, vector<int>& b) {
    if (sort_by_value == "code")
        return a[0] < b[0];
    else if (sort_by_value == "date")
        return a[1] < b[1];
    else if (sort_by_value == "maximum")
        return a[2] < b[2];
    else if (sort_by_value == "remain")
        return a[3] < b[3];
    else
        return false;
}


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    sort_by_value = sort_by;
    
    for(int i = 0; i < data.size(); i++) {
        if(ext == "code" && data[i][0] < val_ext) {
            answer.push_back(data[i]);
        }
        if(ext == "date" && data[i][1] < val_ext) {
            answer.push_back(data[i]);
        }
        if(ext == "maximum" && data[i][2] < val_ext) {
            answer.push_back(data[i]);
        }
        if(ext == "remain" && data[i][3] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    return answer;
}
