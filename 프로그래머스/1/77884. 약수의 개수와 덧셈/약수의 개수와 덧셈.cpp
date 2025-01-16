#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector <int> divisor;
    
    for(int n = left ; n <= right; n++)
    {
    
        for(int i =1; i<=n; i++)
    {
        if(n%i==0)
        {
        divisor.push_back(i);
        }
        
        
    }
        if(divisor.size()%2==0)
        {
            answer+=n;
        }
        else
        {
            answer-=n;
        }
        divisor={};
        
    }
    
    
    return answer;
}