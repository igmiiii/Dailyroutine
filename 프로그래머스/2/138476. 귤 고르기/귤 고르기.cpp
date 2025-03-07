#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> TangerineCount;
    
    for(int i : tangerine)
    {
        TangerineCount[i]++;
    }
    
    vector<pair<int, int>> SortedVec (TangerineCount.begin(), TangerineCount.end());
    
    sort(SortedVec.begin(), SortedVec.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    });
    
    
        for(int i = 0; i<SortedVec.size(); ++i)
        {
            k = k - SortedVec[i].second;
            answer++;
            if(k<= 0)
            {
                break;
            }
        }
        
    
    return answer;
}