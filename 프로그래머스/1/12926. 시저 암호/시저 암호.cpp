#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    vector <char> vec;
    
    for(int i = 0 ; i < s.size(); ++i)
    {
        if(s[i]==' ')
        {
            vec.push_back(' ');
        }
        else if(65<=s[i] && s[i]<=90)
        {
            if( s[i]+n > 90)
            {
                vec.push_back (64 + ((s[i] + n) -90));
            }
            else
            {
                vec.push_back(s[i]+n);
            }
        }
        else
        {
            if( s[i]+n > 122)
            {
                vec.push_back(96 + ((s[i]+n)-122));
            }
            else
            {
                vec.push_back(s[i]+n);
            }
        }
    }
    
    for(char s : vec)
    {
        answer += s;
    }
    
    
    return answer;
}