#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    if( t.size() == p.size())
    {
        return 1;
    }
    else
    {
        
    
    for(int i = 0; i< t.size()-p.size()+1 ; ++i)
    {
        if(stoll(p) >= stoll(t.substr(i, p.size())))
        {
            answer+= 1;
        }
    }
    }
    
    return answer;
}