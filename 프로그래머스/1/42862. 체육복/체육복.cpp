#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 1. 중복된 학생 처리: reserve에 있지만 lost에 있는 학생은 제외
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int> actual_lost;
    vector<int> actual_reserve;
    
    // 중복 처리 (여벌 체육복을 가진 학생은 lost에서 제외)
    for (int i = 0; i < lost.size(); ++i) {
        if (find(reserve.begin(), reserve.end(), lost[i]) != reserve.end()) {
            // 여벌 체육복을 가져온 학생이 도난당했을 경우, 그 학생은 lost 배열에서 제외
            reserve.erase(find(reserve.begin(), reserve.end(), lost[i]));
        } else {
            actual_lost.push_back(lost[i]);
        }
    }
    
    actual_reserve = reserve; // 실제 여벌 체육복을 가진 학생 목록

    // 2. 여벌 체육복을 빌려줄 수 있는 학생 처리
    for (int i = 0; i < actual_reserve.size(); ++i) {
        int student = actual_reserve[i];
        
        // 앞 번호 학생에게 체육복을 빌려줄 수 있는지 확인
        auto it = find(actual_lost.begin(), actual_lost.end(), student - 1);
        if (it != actual_lost.end()) {
            actual_lost.erase(it); // 체육복을 빌려준 학생은 리스트에서 제거
        } else {
            // 뒤 번호 학생에게 체육복을 빌려줄 수 있는지 확인
            it = find(actual_lost.begin(), actual_lost.end(), student + 1);
            if (it != actual_lost.end()) {
                actual_lost.erase(it); // 체육복을 빌려준 학생은 리스트에서 제거
            }
        }
    }

    // 3. 체육수업을 들을 수 있는 학생의 수는 총 학생 수에서 아직 체육복이 없는 학생의 수를 뺀 값
    return n - actual_lost.size();
}