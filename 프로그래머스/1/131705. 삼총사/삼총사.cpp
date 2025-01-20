#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for(size_t i = 0; i < number.size() ; ++i){
        for(size_t j = 0; j < number.size(); ++j){
            for(size_t k = 0; k < number.size(); ++k){
                if( i != j && i != k && j != k){
                    if(number[i]+number[j]+number[k]== 0){
                        answer += 1;
                    }
                }
            }
        }
    }
    
    
    
    return answer/6;
}