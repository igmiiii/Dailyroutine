#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    int atk = 0;
    
    for(int j = 1; j<= number; ++j)
    {
        
    atk = 0;
        
    for(int i = 1 ; i*i  <= j ; ++i)
    {
        if(j%i==0)
        {
            atk ++;
        
        if(i!= j/i){
            atk ++;
        }
        }
    
    
    }
        
    answer+= (atk <= limit) ? atk : power;
    }

    
    
    return answer;
}