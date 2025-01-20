#include <string>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    vector<int> temp;
    int a = INT_MIN;
    int b = INT_MAX;
    
    for(int i=1; i<=n; i++)
    {
        if(n%i == 0&& m%i==0)
        {
            temp.push_back(i);
        }
    }
    
    for(int j : temp)
    {
        
        if(j > a)
        {
            a=j;
        }
    }
    
    answer.push_back(a);
    
    temp.clear();
    
    for(int i=n; i<=n*m; i++)
    {
        if(i%n==0&&i%m==0)
        {
            temp.push_back(i);
        }
    }
    for(int k : temp)
    {
        if(k<b)
        {
            b=k;
        }
    }
    answer.push_back(b);
    
    return answer;
}