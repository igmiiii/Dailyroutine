#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    vector<int> temp;
    
    for(int i =1; i<=score.size(); ++i )
    {
        for(int j = 0; j< i; ++j)
        {
            temp.push_back(score[j]);
        }
        
        if(temp.size()<=k)
        {
            answer.push_back(*min_element(temp.begin(), temp.end()));
            temp.clear();
        }
        
        else
        {
            sort(temp.begin(), temp.end());
            
            answer.push_back(*(temp.rbegin()+k-1));
            temp.clear();
            
        }
        
    }
    
    return answer;
}