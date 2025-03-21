#include <string>
#include <vector>

using namespace std;

// 영역이 모두 같은 값인지 확인하는 함수
bool isUniform(const vector<vector<int>>& arr, int x, int y, int size) {
    int value = arr[x][y];  // 첫 번째 값 저장
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (arr[i][j] != value) {
                return false;  // 값이 다르면 false
            }
        }
    }
    return true;  // 모두 같으면 true
}

// 재귀적으로 압축을 수행하는 함수
void compress(const vector<vector<int>>& arr, int x, int y, int size, int& zeroCount, int& oneCount) {
    // 현재 영역이 모두 같은 값이면 해당 값을 카운트
    if (isUniform(arr, x, y, size)) {
        if (arr[x][y] == 0) {
            zeroCount++;
        } else {
            oneCount++;
        }
        return;
    }

    // 영역을 4개의 부분으로 나누어 재귀적으로 압축
    int halfSize = size / 2;
    compress(arr, x, y, halfSize, zeroCount, oneCount);  // 왼쪽 상단
    compress(arr, x, y + halfSize, halfSize, zeroCount, oneCount);  // 오른쪽 상단
    compress(arr, x + halfSize, y, halfSize, zeroCount, oneCount);  // 왼쪽 하단
    compress(arr, x + halfSize, y + halfSize, halfSize, zeroCount, oneCount);  // 오른쪽 하단
}

vector<int> solution(vector<vector<int>> arr) {
    int zeroCount = 0, oneCount = 0;
    int n = arr.size();
    
    // 배열을 압축하는 함수 호출
    compress(arr, 0, 0, n, zeroCount, oneCount);
    
    // 결과 배열 반환
    return {zeroCount, oneCount};
}