#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int temp = 0;
    
    if(s.size()==4||s.size()==6)
    {
        for(char c : s)
        {
            temp = c-'0';
            if(temp >=10)
                return false;
        }
    }
    else
        return false;
    
    
    return answer;
}