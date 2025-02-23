#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    sort(section.begin(), section.end());
    
    int current_end = 0; // 롤러가 칠한 마지막 구역의 끝
    
    for (int i = 0; i < section.size(); ++i) {
        // 만약 현재 구역이 롤러가 칠한 영역에 포함되지 않으면
        if (section[i] > current_end) {
            // 롤러를 하나 더 칠하고, 롤러의 끝을 현재 구역 + 롤러 길이로 설정
            answer++;
            current_end = section[i] + m - 1;  // 롤러의 끝 위치
        }
    }
    
    return answer;
}