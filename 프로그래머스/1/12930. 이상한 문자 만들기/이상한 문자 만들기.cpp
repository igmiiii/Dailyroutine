#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    vector <string> word;
    int cnt = 0;
    
    cnt = count(s.begin(), s.end(), ' ');
    
    for(int j = 0; j< cnt ; ++j)
    {
        word.push_back(s.substr(0, s.find(' ')+1));
        s.erase(0, s.find(' ')+1);
    }
    word.push_back(s);
    
    for(string k : word)
    {
        for(int i = 0; i< k.size(); ++i)
        {
            if(i%2 ==0)
            {
                answer += toupper(k[i]);
            }
            else
            {
                answer += tolower(k[i]);
            }
        }
    }
    
    return answer;
}