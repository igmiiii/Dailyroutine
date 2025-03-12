#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) {
        return 0;
    }

    unordered_map<int, int> dp;
    queue<int> q;

    dp[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int next_values[] = {curr + n, curr * 2, curr * 3};

        for (int next_val : next_values) {
            if (next_val <= y && dp.find(next_val) == dp.end()) {
                dp[next_val] = dp[curr] + 1;
                q.push(next_val);
                if (next_val == y) {
                    return dp[y];
                }
            }
        }
    }

    return -1;
}
