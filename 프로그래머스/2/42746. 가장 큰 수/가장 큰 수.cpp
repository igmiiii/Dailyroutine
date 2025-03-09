#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 두 문자열을 이어붙였을 때 더 큰 수가 먼저 오도록 비교하는 함수
bool compare(const std::string &a, const std::string &b) {
    return a + b > b + a;
}

std::string solution(std::vector<int> numbers) {
    // 숫자들을 문자열로 변환
    std::vector<std::string> str_numbers;
    for (int num : numbers) {
        str_numbers.push_back(std::to_string(num));
    }

    // 비교 기준에 맞게 정렬
    std::sort(str_numbers.begin(), str_numbers.end(), compare);

    // 정렬된 배열을 이어 붙임
    std::string result = "";
    for (const std::string &str : str_numbers) {
        result += str;
    }

    // 만약 결과가 "0"이 포함된 문자열이라면, "0"을 반환
    if (result[0] == '0') {
        return "0";
    }

    return result;
}

int main() {
    // 테스트 예시
    std::vector<int> numbers1 = {6, 10, 2};
    std::vector<int> numbers2 = {3, 30, 34, 5, 9};

    std::cout << solution(numbers1) << std::endl;  // 6210
    std::cout << solution(numbers2) << std::endl;  // 9534330

    return 0;
}