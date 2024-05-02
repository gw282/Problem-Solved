#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    bool min_x =false, min_y=false, max_x=false, max_y=false;
    
    for(int i=0;i<wallpaper.size();i++) {
        for(int j=0;j<wallpaper[0].length();j++) {
            if(wallpaper[i][j] == '#') {
                answer.push_back(i); 
                min_x = true;
                break;
            }
        }
        if(min_x == true) break;
    }
    

    for(int j=0;j<wallpaper[0].length();j++) {
        for(int i=0;i<wallpaper.size();i++) {
            if(wallpaper[i][j] == '#') {
                answer.push_back(j);
                min_y= true;
                break;
            }
        }
        if(min_y== true) break;
    }
    
    
    for(int i=wallpaper.size()-1;i>=0;i--) {
        for(int j=wallpaper[0].length()-1;j>=0;j--) {
            if(wallpaper[i][j] == '#') {
                answer.push_back(i+1); 
                max_x = true;
                break;
            }
        }
        if(max_x == true) break;
    }
    
    for(int j=wallpaper[0].length()-1;j>=0;j--) {
        for(int i=wallpaper.size()-1;i>=0;i--) {
            if(wallpaper[i][j] == '#') {
                answer.push_back(j+1);
                max_y= true;
                break;
            }
        }
        if(max_y== true) break;
    }

    return answer;
}