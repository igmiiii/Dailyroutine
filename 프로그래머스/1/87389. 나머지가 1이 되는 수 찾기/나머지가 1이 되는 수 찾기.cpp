#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int x= 0;
    
        for (x=1; ;x++){
            if(n%x == 1){
                return x;
            }
        }
    answer= x;
    
    
    
    return answer;
}