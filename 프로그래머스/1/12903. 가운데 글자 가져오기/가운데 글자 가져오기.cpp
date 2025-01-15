#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int size = s.size();
        
        if(size%2 ==1)
        {
            return string(1, s[size/2]);
            
        }
        else if (size % 2 == 0)
        {
            answer = string(1, s[size/2 -1]) + string(1, s[size/2]);
        }
    
    return answer;
}