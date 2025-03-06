#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        n /= 2;
        answer++;
    }

    return answer;
}

int main() {
    int n = 16, a = 1, b = 16;
    cout << solution(n, a, b) << endl;  // 예시 실행
    return 0;
}