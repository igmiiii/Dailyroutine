#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
   for (int i = 0; i < lost.size(); ++i) {
        for (int j = 0; j < reserve.size(); ++j) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);  // 도난당한 학생에서 제외
                reserve.erase(reserve.begin() + j);  // 여벌 체육복을 가진 학생에서 제외
                i--;  // lost 배열에서 해당 인덱스를 제거했으므로 i를 하나 감소
                break;  // 한 명만 처리하면 되므로 그만두기
            }
        }
    }

    // 체육복을 빌려주는 과정
    for (int i = 0; i < reserve.size(); ++i) {
        int student = reserve[i];
        if (find(lost.begin(), lost.end(), student - 1) != lost.end()) {  // 앞번호 학생에게 빌려주기
            lost.erase(find(lost.begin(), lost.end(), student - 1));
        } else if (find(lost.begin(), lost.end(), student + 1) != lost.end()) {  // 뒷번호 학생에게 빌려주기
            lost.erase(find(lost.begin(), lost.end(), student + 1));
        }
    }

    // 체육수업을 들을 수 있는 학생의 수는 총 학생 수에서 아직 체육복이 없는 학생의 수를 뺀 값
    return n - lost.size();
}