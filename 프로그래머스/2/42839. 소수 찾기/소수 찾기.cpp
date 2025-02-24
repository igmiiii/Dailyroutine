#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

// 소수 판별 함수
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void find_primes(string numbers, set<int>& primes) {
    sort(numbers.begin(), numbers.end());
    do {
        // 숫자 길이가 1 이상인 경우만 처리
        for (int len = 1; len <= numbers.size(); len++) {
            string num_str = numbers.substr(0, len);
            int num = stoi(num_str);
            if (is_prime(num)) {
                primes.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
}

int solution(string numbers) {
    set<int> primes;  // 중복을 없애기 위한 set
    find_primes(numbers, primes);  // 가능한 모든 숫자 순열을 생성하여 소수 판별
    return primes.size();  // 소수의 개수를 반환
}