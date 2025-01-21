#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <int> nature;
    
    if(n<3)
        return n;
    else
    {
    while(n>=3)
    {
        nature.push_back(n%3);
        n=n/3;
    }
        nature.push_back(n);
        
    }
    if(nature[0] ==0)
    {
        nature.erase(nature.begin());
    }
    for(int i = 0 ; i< nature.size(); ++i)
    {
        answer+= nature[i]*pow(3, nature.size() - i-1);
    }
    
    
    return answer;
}