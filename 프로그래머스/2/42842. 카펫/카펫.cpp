#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    // 전체 격자 수 = brown + yellow
    int total = brown + yellow;
    
    // 가로와 세로 길이를 구하는 방법
    for (int w = 3; w <= total; w++) { // 가로 크기는 최소 3부터 시작 (w - 2 >= 1이 되어야 하므로)
        if (total % w == 0) { // 전체 크기에서 w가 나누어 떨어지면
            int h = total / w; // 세로 크기 계산
            if ((w - 2) * (h - 2) == yellow) { // 노란색 격자 수가 맞는지 확인
                answer.push_back(h);
                answer.push_back(w);
                
                return answer; // 가로, 세로 크기 찾으면 바로 리턴
            }
        }
    }
    
    return answer;
}