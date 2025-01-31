#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> mth1;
    vector<int> mth2;
    vector<int> mth3;
    vector<int> ans;
    int score1=0;
    int score2=0;
    int score3= 0;
    int max_score= 0;
    
    for(int i = 0; i< (answers.size()/5+1); i++)
    {
    mth1.insert(mth1.end(), {1, 2, 3, 4, 5});
    }
    for(int j = 0; j <(answers.size()/8+1);j++)
    {
    mth2.insert(mth2.end(), {2, 1, 2, 3, 2, 4, 2, 5});
    }
    for(int k= 0; k < (answers.size()/10+1); k++)
    {
    mth3.insert(mth3.end(), {3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    }
    
    for(size_t o = 0; o<answers.size(); ++o)
    {
        if(answers[o] == mth1[o])
        {
            score1++;
        }
        
    }
    for(size_t t = 0; t<answers.size(); ++t)
    {
        if(answers[t] == mth2[t])
        {
            score2++;
        }
        
    }
    for(size_t h = 0; h<answers.size(); ++h)
    {
        if(answers[h] == mth3[h])
        {
            score3++;
    }}
    
    max_score = max({score1, score2, score3});
    
    if(score1==max_score)
    {
        answer.push_back(1);
    }
    if(score2==max_score)
    {
        answer.push_back(2);
    }
    if(score3==max_score)
    {
        answer.push_back(3);
    }
    
    
    
    
    return answer;
}