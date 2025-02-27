#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    
    for(string s : targets)
    {
        int temp = 0;
        for(char c :s)
        {
            int min = INT_MAX;
            for(string t :keymap)
            {
                
                if(t.find(c) != string::npos && t.find(c)<min)
                {
                    min = t.find(c);
                }
                
            }
            if(min != INT_MAX)
            {
            
                temp += min+1;
            }
            else
            {
                
                temp=-1;
                break;
            }
            
        }
        
        answer.push_back(temp);
        
        
    }
    
    
    return answer;
}