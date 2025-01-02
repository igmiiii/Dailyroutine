#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    //벡터의 요소 다 더하기
    double sum = 0;
    for (int num : numbers){
        sum += num;
        }
    int sz= numbers.size();
        answer = sum / (double)sz;
    //더한값을 벡터의 개수로 나누기
    
    
    return answer;
}