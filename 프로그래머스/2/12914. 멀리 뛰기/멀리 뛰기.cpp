#include <vector>
using namespace std;

const int MOD = 1234567;

long long solution(int n) {
    // dp 배열을 생성하여 각 칸에 도달하는 방법의 수를 저장
    vector<long long> dp(n + 1, 0);

    // 초기 값 설정
    dp[1] = 1; // 1번째 칸에 도달하는 방법은 1가지
    if (n > 1) {
        dp[2] = 2; // 2번째 칸에 도달하는 방법은 2가지
    }

    // dp[n]을 계산 (점화식 dp[n] = dp[n-1] + dp[n-2])
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    // 결과를 1234567로 나눈 나머지를 반환
    return dp[n];
}