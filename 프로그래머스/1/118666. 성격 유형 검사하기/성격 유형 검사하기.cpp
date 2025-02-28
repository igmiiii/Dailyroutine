#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char, int> score= {{'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}};
    
    for(int i = 0; i < survey.size(); ++i)
    {
        int j = choices[i];
        string s = survey[i];
        
            if(j<4)
            {
                if(j == 1)
                {
                    score[s[0]]+=3;
                }
                if(j ==2)
                {
                    score[s[0]]+=2;
                }
                if(j ==3)
                {
                    score[s[0]]++;
                }
            }
            else if(j==4)
            {
                
            }
            else
            {
                if(j == 5)
                {
                    score[s[1]]++;
                }
                if(j==6)
                {
                    score[s[1]]+=2;
                }
                if(j ==7)
                {
                    score[s[1]]+=3;
                }
                
            }
        
    }
    if(score['R'] > score['T'])
    {
        answer+='R';
    }
    else if(score['R'] == score['T'])
    {
        answer+='R';
    }
    else
    {
        answer+='T';
    }
    
    if(score['C'] > score['F'])
    {
        answer+='C';
    }
    else if(score['C'] == score['F'])
    {
        answer+='C';
    }
    else
    {
        answer+='F';
    }
    
    if(score['J'] < score['M'])
    {
        answer+='M';
    }
    else if(score['J'] == score['M'])
    {
        answer+='J';
    }
    else
    {
        answer+='J';
    }
    
    if(score['A']< score['N'])
    {
        answer+='N';
    }
    else if(score['A'], score['N'])
    {
        answer+='A';
    }
    else
    {
        answer+='A';
    }
    
    return answer;
}