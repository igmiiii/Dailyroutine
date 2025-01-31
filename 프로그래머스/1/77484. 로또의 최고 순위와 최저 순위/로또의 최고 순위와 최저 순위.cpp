#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int cnt=0;
    int var =0;
    unordered_map <int, int> ltt =
    {
        {6, 1}, {5, 2}, {4, 3}, {3, 4}, {2, 5}, {1, 6}, {0, 6} 
        
    };
    
    for(int f : win_nums)
    {
        if(find(lottos.begin(), lottos.end(), f)!= lottos.end())
        {
            cnt++;
        }
        
    }
    
    var = count(lottos.begin(), lottos.end(), 0);
    
    
    answer.push_back(ltt[cnt+var]);
    answer.push_back(ltt[cnt]);
    
    
    
    
    
    return answer;
}