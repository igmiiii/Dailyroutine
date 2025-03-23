#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    // (우선순위, 원래 인덱스) 값을 저장하는 deque
    deque<pair<int, int>> queue;
    
    // 큐에 (우선순위, 원래 인덱스) 값을 넣기
    for (int i = 0; i < priorities.size(); ++i) {
        queue.push_back({priorities[i], i});
    }
    
    int execution_order = 0; // 실행 순서
    
    while (!queue.empty()) {
        // 가장 앞의 프로세스를 꺼냄
        auto current = queue.front();
        queue.pop_front();
        
        // 큐에서 우선순위가 더 높은 프로세스가 있는지 확인
        bool has_higher_priority = false;
        for (const auto& item : queue) {
            if (current.first < item.first) {
                has_higher_priority = true;
                break;
            }
        }
        
        if (has_higher_priority) {
            // 우선순위가 더 높은 프로세스가 있으면 다시 뒤로 넣기
            queue.push_back(current);
        } else {
            // 우선순위가 더 높은 프로세스가 없으면 실행
            execution_order++;
            // 우리가 찾는 프로세스가 실행되면 그 실행 순서를 반환
            if (current.second == location) {
                return execution_order;
            }
        }
    }
    
    return execution_order;
}

int main() {
    // 테스트 예시 1
    vector<int> priorities1 = {2, 1, 3, 2};
    int location1 = 2;
    cout << solution(priorities1, location1) << endl;  // 출력: 1

    // 테스트 예시 2
    vector<int> priorities2 = {1, 1, 9, 1, 1, 1};
    int location2 = 0;
    cout << solution(priorities2, location2) << endl;  // 출력: 5
    
    return 0;
}