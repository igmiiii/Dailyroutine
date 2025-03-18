#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    
    
    for(int i = 0; i< discount.size()-9; i++)
    {
        int Count = 0;
        unordered_map<string, int> Temp;
        for(int j = i ; j<i+10; ++j)
        {
            Temp[discount[j]]++;
        }
        
        for(int k = 0; k <want.size(); ++k)
        {
            if(Temp.find(want[k])==Temp.end())
            {
                break;
            }
            else
            {
                if(Temp[want[k]]!=number[k])
                {
                    break;
                }
                Count ++;
            }
            
        }
        if(Count == want.size())
        {
            answer++;
        }
        Count = 0;
        Temp.clear();
    }
    
    return answer;
}