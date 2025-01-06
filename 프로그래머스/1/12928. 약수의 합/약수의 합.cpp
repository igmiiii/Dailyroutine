#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1 ; i<= n; i++){
        if(n%i==0){
            answer += i;
        }
    }
    //n의 약수 구하기
    //n의 약수 더하기
    return answer;
}