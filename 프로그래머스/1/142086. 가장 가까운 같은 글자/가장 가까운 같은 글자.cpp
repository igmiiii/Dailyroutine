#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map<char, int> temp;
    
    for(int i =0 ; i<s.size(); ++i)
    {
        
        if(temp.find(s[i]) == temp.end())
        {
            answer.push_back(-1);
            temp[s[i]] = i;
        }
        else
        {
            answer.push_back(i - temp[s[i]]);
            temp[s[i]] = i;
        }
    }
    
    
    return answer;
}