#include <string>
#include <vector>

using namespace std;

// 재귀적으로 가능한 모든 경우를 탐색하는 함수
void dfs(int index, int current_sum, const vector<int>& numbers, int target, int& answer) {
    // 배열의 모든 숫자를 다 처리한 경우
    if (index == numbers.size()) {
        // 현재 합이 타겟 넘버와 같으면 1을 더함
        if (current_sum == target) {
            answer++;
        }
        return;
    }

    // 현재 숫자에 대해 더하거나 빼는 두 가지 선택
    dfs(index + 1, current_sum + numbers[index], numbers, target, answer);
    dfs(index + 1, current_sum - numbers[index], numbers, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    // dfs를 0번째 인덱스부터 시작, 현재 합은 0
    dfs(0, 0, numbers, target, answer);
    return answer;
}