#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector <string> Case;
    
    while(s.find(' ')!= string::npos)
    {
        size_t pos = s.find(' ');
        Case.push_back(s.substr(0, pos));
        s.erase(0, pos+1);
    }
    Case.push_back(s);
        
    for(string s :Case)
    {
        
            if(isdigit(s[0]))
            {
                for(int i = 1; i<s.size(); ++i)
                {
                    if(isupper(s[i]))
                       {
                           s[i] = tolower(s[i]);
                       }
                }
                answer += s;
                answer += ' ';
            }
            else
            {
                s[0] = toupper(s[0]);
                for(int i = 1; i<s.size(); ++i)
                {
                    if(isupper(s[i]))
                    {
                        s[i] = tolower(s[i]);
                    }
                }
                answer += s;
                answer += ' ';
            }
            
        
        
        
        
        
        
        
        
    }
    
    answer.pop_back();
    
    
    return answer;
}