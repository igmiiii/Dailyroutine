#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minmax [2][2] = {{INT_MAX, INT_MAX}, {INT_MIN, 0}};
    
    for(int i = 0 ; i<wallpaper.size(); ++i)
    {
        if(wallpaper[i].find('#')!= string::npos)
        {
            if(minmax[0][0]>i)
            {
                minmax[0][0]= i;
            }
            
            if(minmax[0][1] > wallpaper[i].find('#'))
            {
                minmax[0][1] = wallpaper[i].find('#');
            }
            
            
            if(minmax[1][0] < i)
            {
                minmax[1][0]=i;
            }
            
            if(minmax[1][1] < wallpaper[i].rfind('#'))
            {
                minmax[1][1] = wallpaper[i].rfind('#');
            }
        }
    }
    
    answer.push_back(minmax[0][0]);
    answer.push_back(minmax[0][1]);
    answer.push_back(minmax[1][0]+1);
    answer.push_back(minmax[1][1]+1);
    
    
    
    return answer;
}