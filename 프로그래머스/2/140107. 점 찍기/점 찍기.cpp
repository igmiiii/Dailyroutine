#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long count = 0;
    for (long long x = 0; x <= d; x += k) {
        long long maxY = sqrt((long long)d * d - x * x);
        count += (maxY / k) + 1;
    }
    return count;
}