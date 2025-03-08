#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, vector<string>> Classification;
    
    for(vector<string> vec: clothes)
    {
        Classification[vec[1]].push_back(vec[0]);
    }
    
    for(auto& pair : Classification)
    {
        pair.second.push_back("Nothing");
    }
    
    int temp = 1;
    
    for(auto& pair : Classification)
    {
        temp*=pair.second.size();
    }
    
    answer = temp-1;
    
    return answer;
}