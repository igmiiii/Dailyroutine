#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    
    for (int i = 0; i < ingredient.size(); ++i) {
        stack.push_back(ingredient[i]);
        
        // 스택의 마지막 4개 재료가 "빵, 야채, 고기, 빵" 순서인 경우
        if (stack.size() >= 4 && stack[stack.size() - 4] == 1 && stack[stack.size() - 3] == 2 && stack[stack.size() - 2] == 3 && stack[stack.size() - 1] == 1) {
            // 햄버거 포장
            stack.pop_back(); // 마지막 빵 제거
            stack.pop_back(); // 고기 제거
            stack.pop_back(); // 야채 제거
            stack.pop_back(); // 첫 번째 빵 제거
            answer++; // 포장된 햄버거 수 증가
        }
    }
    
    return answer;
}