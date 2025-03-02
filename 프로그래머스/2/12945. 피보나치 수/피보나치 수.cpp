#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int a = 0;
    int b = 1;
    
    if(n == 2)
    {
        answer = 1;
    }
    else
    {
        for(int i = 0; i< n/2; ++i)
        {
            a = (a+b)%1234567;
            b = (a+b)%1234567;
        }

        if(n%2 ==1)
        {
            answer = b;
        }
        else
        {
            answer = a;
        }
        
    }
    
    
    
    return answer;
}