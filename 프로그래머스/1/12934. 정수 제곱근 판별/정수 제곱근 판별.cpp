#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    //n이 제곱인지 확인
    //제곱이면 x+1의 제곱 리턴
    //제곱이 아니라면 -1리턴
    for(long long i=1; i<=n; i++){
        if(n%i==0){
            if(i*i==n){
                return (i+1)*(i+1);
            }
        }
        
}
    return -1;
}