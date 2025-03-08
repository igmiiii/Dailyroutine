#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    // left부터 right까지의 1차원 배열에 해당하는 값을 계산하여 저장
    for (long long i = left; i <= right; ++i) {
        long long row = i / n;   // 행 번호
        long long col = i % n;   // 열 번호
        
        // 각 구간에서의 값은 row와 col 중 더 큰 값
        answer.push_back(max(row, col) + 1);  // 1부터 시작하므로 +1
    }
    
    return answer;
}