#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int n = order.size();
    queue<int> belt;
    stack<int> auxiliary;
    int order_idx = 0;

    for (int i = 1; i <= n; ++i) {
        belt.push(i);
    }

    while (order_idx < n) {
        int target = order[order_idx];

        // 1. 컨테이너 벨트에서 바로 꺼낼 수 있는 경우
        if (!belt.empty() && belt.front() == target) {
            belt.pop();
            answer++;
            order_idx++;
        }
        // 2. 보조 컨테이너 벨트에서 꺼낼 수 있는 경우
        else if (!auxiliary.empty() && auxiliary.top() == target) {
            auxiliary.pop();
            answer++;
            order_idx++;
        }
        // 3. 컨테이너 벨트의 상자를 보조 컨테이너 벨트로 이동
        else if (!belt.empty()) {
            auxiliary.push(belt.front());
            belt.pop();
        }
        // 4. 더 이상 옮길 상자가 없는 경우
        else {
            break;
        }
    }

    return answer;
}