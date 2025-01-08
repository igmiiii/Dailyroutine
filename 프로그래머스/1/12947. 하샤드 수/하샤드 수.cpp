#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int t= 0;
    t=x;
    
    while(x!=0){
    sum += x%10;
    x=x/10;
        }
    
    if(t%sum!=0){
        
        answer=false;
        
    }
    
    
    return answer;
}