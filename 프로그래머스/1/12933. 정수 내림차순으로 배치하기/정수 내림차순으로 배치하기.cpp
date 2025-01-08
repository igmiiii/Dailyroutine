#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<long long> digits;
    
    while(n>0){
        digits.push_back(n%10);
        n/=10;
    }
    sort(digits.begin(), digits.end());
    
    
    long long place =1;
    for(int i=0; i<digits.size(); i++){
        answer+= digits[i]*place;
        place*=10;
    }
    
    
    //각 자릿수 리턴
    //재배치
    
    return answer;
}