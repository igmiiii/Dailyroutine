#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int j = 1; j < food.size(); ++j)
    {
        for(int i = 0; i < food[j]/2; ++i)
        {
            answer+= ('0' + j);
        }
    }
    
    answer += ('0' + 0);
    
    for(int k = food.size()-1; k >0; --k)
    {
        for(int i = 0; i < food[k]/2; ++i)
        {
            answer+= '0' + k;
        }
    }
    
    
    
    
    
    
    
    return answer;
}