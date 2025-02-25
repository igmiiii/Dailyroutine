#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector <string> temp2;
    vector <int> temp3;
    
    for (int i = 0; i< s.size(); ++i)
    {
        if( s[i] != ' ')
        {
            if( s[i] == '-')
            {
                temp += s[i];
                i+=1;
                while(i < s.size() && s[i] != ' ')
                {
                    temp+=s[i];
                    i+=1;
                }
                temp2.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += s[i];
                i+=1;
                while(i<s.size() && s[i] != ' ')
                {
                    temp+=s[i];
                    i+=1;
                }
                
                temp2.push_back(temp);
                temp.clear();
            }
        }
        
    }
    
    for(string s : temp2)
    {
        temp3.push_back(stoi(s));
    }
    
    sort(temp3.begin(), temp3.end());
    
    answer += to_string(temp3.front());
    answer += ' ';
    answer += to_string(temp3.back());
    
    return answer;
}