#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    unordered_map<char, int> countX, countY;

    // X와 Y에서 각 숫자의 빈도수를 셈
    for (char c : X) {
        countX[c]++;
    }
    for (char c : Y) {
        countY[c]++;
    }

    // 공통된 숫자를 찾기 위한 벡터
    vector<char> common;

    // 공통된 숫자에 대해 처리
    for (auto& entry : countX) {
        char num = entry.first;
        if (countY.find(num) != countY.end()) {
            // X와 Y에서 이 숫자가 공통으로 등장한 횟수만큼 추가
            int count = min(countX[num], countY[num]);
            for (int i = 0; i < count; ++i) {
                common.push_back(num);
            }
        }
    }

    // 공통된 숫자들이 없다면 -1 반환
    if (common.empty()) {
        return "-1";
    }

    // 공통된 숫자들을 내림차순으로 정렬
    sort(common.rbegin(), common.rend());

    // 정렬된 숫자들을 합쳐서 결과 만들기
    for (char c : common) {
        answer += c;
    }

    // 결과가 0만 있는 경우 "0"을 반환
    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}