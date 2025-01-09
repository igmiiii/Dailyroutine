#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n= num;
    
    if(n ==1)
    {
        return 0;
    }
    while(n!=1&&answer<=501)
    {
    if(n%2==0)
    {
        n=n/2;
    }
    else
    {
        n = n*3+1;
    }
        answer++;
        
    }
    
    if (answer==502)
    {
        return -1;
    }
    return answer;
}