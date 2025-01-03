#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    //각 자릿수 뽑아내기
    
    while (n>0){
        answer += n%10;
            n= n/10;}
    return answer;
}