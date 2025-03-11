#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    unordered_set<int> bro;
    unordered_set<int> me;
    vector<int> bro_cnt(n);
    vector<int> me_cnt(n);

    for (int i = n - 1; i >= 0; i--) {
        bro.insert(topping[i]);
        bro_cnt[i] = bro.size();
    }

    for (int i = 0; i < n - 1; i++) {
        me.insert(topping[i]);
        me_cnt[i] = me.size();
        if (me_cnt[i] == bro_cnt[i + 1]) {
            answer++;
        }
    }
    return answer;
}