#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);  // 기본값은 -1로 설정
    stack<int> st;

    for (int i = numbers.size() - 1; i >= 0; --i) {
        // 스택에서 현재 숫자보다 작은 값을 모두 제거
        while (!st.empty() && st.top() <= numbers[i]) {
            st.pop();
        }

        // 스택이 비지 않으면, 스택의 top이 현재 숫자보다 큰 수
        if (!st.empty()) {
            answer[i] = st.top();
        }

        // 현재 숫자를 스택에 추가
        st.push(numbers[i]);
    }

    return answer;
}