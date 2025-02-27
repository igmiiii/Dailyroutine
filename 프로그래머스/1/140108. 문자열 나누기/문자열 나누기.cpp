#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string cut = " ";
    int first=0;
    int els=0;
    
    cut = s;
    for(int i = 0; i<cut.size(); ++i)
    {
        if(cut[i] == *cut.begin())
        {
            first++;
        }
        else
        {
            els++;
        }
        
        if(first == els)
        {
            answer++;
            cut.erase(0, i+1);
            i= -1;
        }
    }
    
    if(cut.size()!= 0)
    {
        answer++;
    }
    
    return answer;
}